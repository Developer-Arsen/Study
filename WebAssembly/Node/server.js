const net = require('net');

const server = net.createServer((socket) => {
    console.log('Client connected');

    socket.on('data', (data) => {
        console.log(`Received from client: ${data.toString()}`);
        socket.write('Message received by server');
    });

    socket.on('end', () => {
        console.log('Client disconnected');
    });
});

server.listen(3006, () => {
    console.log('Server is listening on port 3006');
});
