import express from "express"
import bodyParser from "body-parser";
import cors from "cors"
import path from "path"
import dotenv from "dotenv"
import multer from "multer";
import { ObjectId } from "mongodb";
import { fileURLToPath } from 'url';
import { MongoClient } from "mongodb"
import { body, validationResult } from "express-validator";

dotenv.config();

const app = express();
const PORT = process.env.PORT;
const DB_NAME = process.env.DB_NAME;
const APP_URL = process.env.APP_URL;

const mongouri = process.env.DATABASE_URI + "/" + DB_NAME;
const client = await new MongoClient(mongouri).connect();
const db = client.db(DB_NAME)

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const storage = multer.memoryStorage();
const upload = multer({ storage: storage });

app.use(cors())
app.use(express.static(path.join(__dirname, "public")))
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

const productValidationRules = () => {
    return [
        body("name")
            .trim()
            .isLength({ min: 1 })
            .withMessage("Name is required")
            .isLength({ max: 16 })
            .withMessage("Name must be at most 16 characters long"),

        body('price')
            .isFloat({ gt: -1, lt: 1000 })
            .withMessage('Price must be between 0 and 999.99'),

        body('url')
            .trim()
            .isLength({ min: 1 })
            .withMessage('URL is required')
            .isLength({ max: 250 })
            .withMessage('URL must be at most 50 characters long')
    ];
};


app.get("/", (req, res) => {
    let pathtofile = path.join(__dirname, "public", "index.html")
    res.sendFile(pathtofile)
})

app.get("/products", async (req, res) => {
    try {
        const result = await db.collection("products").find().toArray();

        if (result.length > 0) {
            return res.status(200).send({
                message: 'Success! Products retrieved successfully.',
                data: result,
            });
        } else {
            return res.status(200).send({
                message: 'No products found. Please add products to see them',
            });
        }
    } catch (error) {
        return res.status(500).send({
            message: 'An unexpected error occurred while fetching the products.',
            error: error.message,
        });
    }
});

app.post("/products", [upload.single('image')], async (req, res) => {
    const photo = req.file.buffer;
    let photoData;
    if (photo) {
        photoData = {
            data: req.file.buffer,
            contentType: req.file.mimetype,
        };
    };

    // const errors = validationResult(req);
    // if (!errors.isEmpty()) {
    //     return res.status(400).json({ errors: errors.array() })
    // }

    const { name, price } = req.body;
    try {
        const photoRes = await db.collection("photos").insertOne({ photo });
        if (photoRes.acknowledged) {
            const obj = {
                name,
                price,
                url: APP_URL + photoRes.insertedId,
                photoId: photoRes.insertedId
            }
            const result = await db.collection("products").insertOne(obj);
            const data = await db.collection("products").findOne(result.insertedId);

            if (result.acknowledged) {
                return res.status(201).send({
                    message: ' Success! Your document has been inserted into our database.',
                    data: data,
                });
            } else {
                return res.status(500).send({
                    message: 'Oops! Something went wrong. We couldn’t save your document this time.',
                });
            }
        }
    } catch (error) {
        return res.status(500).send({
            message: 'An unexpected error occurred while processing your request.',
        });
    }
})

app.get("/products/:id", async (req, res) => {
    const { id } = req.params;

    let result = await db.collection("products").findOne({ _id: new ObjectId(id) });
    res.send(result);
})

app.delete("/products/:id", async (req, res) => {
    const { id } = req.params;
    let result = await db.collection("products").findOne({ _id: new ObjectId(id) });
    const photodel = await db.collection("photos").deleteOne({ _id: result.photoId });
    result = await db.collection("products").deleteOne({ _id: result._id });
    res.send("okay");
})

app.get("/cdn/:id", async (req, res) => {
    const { id } = req.params;
    const photo = await db.collection("photos").findOne({ _id: new ObjectId(id) });

    if (photo) {
        res.setHeader("Content-Type", photo.photo.sub_type);
        res.status(200).send(photo.photo.buffer);
    } else {
        res.send("not okay");
    }
});

app.post("/cdn/:id", upload.single("image"), async (req, res) => {
    const { id } = req.params;
    const { image } = req.body;

    const base64Data = image.replace(/^data:image\/\w+;base64,/, "");
    const imgBuffer = Buffer.from(base64Data, 'base64');

    const newImage = {
        image: imgBuffer,
        contentType: 'image/png'  // or extract content type dynamically
    };

    console.log(id);
    const result = await db.collection("photos").updateOne({ _id: new ObjectId(id) }, { $set: { photo: imgBuffer } })
    
    // if (photo) {
    //     res.setHeader("Content-Type", photo.photo.sub_type);
    //     res.status(200).send(photo.photo.buffer);
    // } else {
    //     res.send("not okay");
    // }
    res.send("ok");
});

app.listen(PORT);

