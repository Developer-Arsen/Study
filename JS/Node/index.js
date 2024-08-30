import express from "express"
import bodyParser from "body-parser";
import cors from "cors"
import path from "path"
import dotenv from "dotenv"
import multer from "multer";
import { fileURLToPath } from 'url';
import { MongoClient } from "mongodb"
import { body, validationResult } from "express-validator";

const app = express();

const mongouri = process.env.DATABASE_URI;
const client = await new MongoClient(mongouri).connect();
const collection = client.collection("products");


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
            .isLength({ max: 50 })
            .withMessage('URL must be at most 50 characters long')
    ];
};


app.get("/", () => {
    const path = path.join(__dirname, "public", "index.html")
    res.sendFile(path)
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
            return res.status(404).send({
                message: 'No products found.',
                hint: 'Try adding some products first, then try again.',
            });
        }
    } catch (error) {
        return res.status(500).send({
            message: 'An unexpected error occurred while fetching the products.',
            suggestion: 'Please try again later or contact support if the problem persists.',
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
            return res.status(201).send({
                message: ' Success! Your document has been beautifully inserted into our database.',
                details: result,
            });
        } else {
            return res.status(500).send({
                message: 'Oops! Something went wrong. We couldn’t save your document this time.',
                hint: 'Please try again later or contact support.',
                details: result,
            });
        }
    } catch (error) {
        return res.status(500).send({
            message: 'An unexpected error occurred while processing your request.',
            suggestion: 'Our team is already notified. Please wait a moment and try again.',
            error: error.message,
        });
    }
})

app.listen(12345);

