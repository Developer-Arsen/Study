const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const net = require('net');

const client = new net.Socket();
client.connect(12345, 'localhost', () => {
    // client.write('create file.js');
});

const app = express();
const PORT = 3000;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

// Handle form submission
app.post('/submit-form', (req, res) => {
    const { filename } = req.body;
    client.write("create " + filename)
    
    client.on('data', (data) => {
        res.send('Received from server:' + data.toString());
        client.destroy(); // Close the connection after receiving data
    });
});

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
