// To use fs module we will have to require it in our file.
const fs = require('fs');
console.log(__dirname);
let filePath = __dirname + '/database/data.json';
console.log(filePath)
let data = {
    text: "Hello World",
    date: '18 March 2024'
}
fs.writeFile(filePath, JSON.stringify(data), (err) => {
    if(err){
        console.log(err);
    }else{
        console.log("All OKAY");
    }
})