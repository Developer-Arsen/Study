import express from 'express'
import multer from "multer"
import { MongoClient } from 'mongodb';

const app = express()
const uri = "mongodb://localhost:27017"
const client = await new MongoClient(uri);
const db = client.db("arsen");


app.use(express.json());

app.get('/users', (req, res) => {
    // console.log(req.xhr); // Output: ''
    res.redirect("/test");
});

let i = 0
app.get('/test', (req, res) => {
    console.log("test" , i++);
    
    // console.log(req.xhr); // Output: ''
    // res.redirect( "/bxk");
});

app.get('/bxk', (req, res) => {
    // console.log(req.xhr); // Output: ''
    res.redirect("back");
});




// const storage = multer.diskStorage({
//     destination: function (req, file, cb) {
//         cb(null, 'uploads/'); // Set the destination for uploaded files
//     },
//     filename: function (req, file, cb) {
//         cb(null, Date.now() + '-' + file.originalname); // Set the filename
//     }
// });

// const upload = multer({ storage: storage });

// app.post('/upload', upload.single('file'), async (req, res) => {
//     res.send('File uploaded successfully!');
// });

// app.get('/users', async (req, res) => {
//     console.log(req.baseUrl);
//     res.send("as");
// });

// app.post('/users', async (req, res) => {
//     const { name } = req.body;
//     const user = {
//         name,
//     };

//     const result = await collection.insertOne(user);
//     return result;
// });

// app.patch('/users/:id', async (req, res) => {
//     res.send('File uploaded successfully!');
// });

// app.delete('/users', async (req, res) => {
//     const { name } = req.body;
//     res.send(collection.deleteOne({ name }));
// });

app.listen(12345)