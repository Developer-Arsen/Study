import express from "express"
import bodyParser from "body-parser";
import cors from "cors"
import path from "path"
import dotenv from "dotenv"
import multer from "multer";
import { fileURLToPath } from 'url';
import { MongoClient } from "mongodb"
import { body, validationResult } from "express-validator";

dotenv.config();

const app = express();
const PORT = process.env.PORT;
const DB_NAME = process.env.DB_NAME;

const mongouri = process.env.DATABASE_URI + "/" + DB_NAME;
const client = await new MongoClient(mongouri).connect();
const collection = client.db(DB_NAME).collection("products");

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

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
        const result = await collection.find().toArray();

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

app.post("/products", productValidationRules(), async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
        return res.status(400).json({ errors: errors.array() })
    }
    
    const { name, price, url } = req.body;
    try {
        const result = await collection.insertOne({ name, price, url });

        if (result.acknowledged) {
            const createdDocument = await collection.findOne({ _id: result.insertedId });
            return res.status(201).send({
                message: ' Success! Your document has been inserted into our database.',
                data: createdDocument,
            });
        } else {
            return res.status(500).send({
                message: 'Oops! Something went wrong. We couldn’t save your document this time.',
            });
        }
    } catch (error) {
        return res.status(500).send({
            message: 'An unexpected error occurred while processing your request.',
        });
    }
})

app.listen(PORT);

