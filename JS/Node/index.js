import express from "express"
import { MongoClient } from "mongodb"
import bodyParser from "body-parser";
import { body, validationResult } from "express-validator";

const uri = "mongodb://localhost:27017";
const client = await new MongoClient(uri).connect();
const db = client.db("arsen");
const collection = db.collection("products");

const app = express();

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
            .withMessage('Price must be between 0 and 999.99')
    ];
};

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());


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

    const { name, price } = req.body;
    try {
        const result = await collection.insertOne({ name, price });

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

