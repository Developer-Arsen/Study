const http = require("http");
const fs = require("fs");

const server = http.createServer((res, req) => {
  res.writeHead(200, { "Content-type": "application/json" });
  res.end(JSON.stringify({ message: "hello world" }));
});

console.log("start");
const write = fs.writeFileSync("file.txt", "heloooasdasd");
const res = fs.readFileSync("file.txt", "ascii", (error) => {
  console.log(error);
});
console.log(res);
console.log("end");

console.log(__filename);

const PORT = 3001;
server.listen(PORT, () => {
  console.log(`server is runing on port${PORT}`);
});
