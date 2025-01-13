const fs = require('fs/promises');
const filepath = __dirname + '/database/data.json';
let data = ['Coding', 'Dancing', 'Singing'];
fs.writeFile(filepath, JSON.stringify(data))
    .then(() => {
        console.log("All set");
    })
    .catch(err => {
        console.log(err);
    })