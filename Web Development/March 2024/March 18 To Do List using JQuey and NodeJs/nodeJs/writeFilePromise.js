// To use fs module we will have to require it in our file.
const fs = require('fs/promises');
console.log(__dirname);
let filePath = __dirname + '/database/data.txt';
console.log(filePath)
fs.writeFile(filePath, 'Hello World')
    .then(() => {
        console.log("All OKAY");
    })
    .catch(err => {
        console.log(err);
    })