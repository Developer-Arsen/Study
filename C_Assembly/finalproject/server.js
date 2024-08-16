const net = require('net');

const client = new net.Socket();

client.connect(12345, 'localhost', () => {
  console.log('Connected to the server');
  client.write('create file.js');
});

client.on('data', (data) => {
  console.log('Received from server:', data.toString());
  client.destroy(); // Close the connection after receiving data
});

client.on('close', () => {
  console.log('Connection closed');
});

client.on('error', (err) => {
  console.error('Error:', err.message);
});
