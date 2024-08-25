import express from 'express'
import multer from "multer"

const app = express()

const storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, 'uploads/'); // Set the destination for uploaded files
    },
    filename: function (req, file, cb) {
        cb(null, Date.now() + '-' + file.originalname); // Set the filename
    }
});

const upload = multer({ storage: storage });

app.post('/upload', upload.single('file'), async (req, res) => {
    console.log(req);
    console.log(req.body["ars"]);
    res.send('File uploaded successfully!');
});

app.post("/test/:id", function (req, res) {
    const { body } = req;
    console.log(body);
    res.send(body ?? "hehcban")
});

app.listen(12345)