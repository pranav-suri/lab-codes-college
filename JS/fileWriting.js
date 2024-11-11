const fs = require("fs");
const content = "This is the content to be written to the file.";
fs.writeFileSync("example.txt", content, "utf8");
fs.readFileSync("example.txt", "utf8");
fs.rmSync("example.txt");

setInterval(myFunction, 1000);
function myFunction() {
    const d = new Date();
    const st = d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
    console.log(st);
}
