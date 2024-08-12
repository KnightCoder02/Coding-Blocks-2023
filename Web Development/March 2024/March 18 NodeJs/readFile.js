const fs = require('fs/promises');
let filePath = __dirname + '/database/data.json'

fs.readFile(filePath)
    .then((data) => {
        console.log(data.toString());
    })
    .catch(err => {
        console.log(err);
    })