const fs = require('fs/promises');
const filepath = __dirname + '/database/data.json';
let data = ['Coding', 'Dancing', 'Singing'];

async function getData(){
    try{
        let data = await fs.readFile(filepath);
        data = JSON.parse(data);
        console.log(data);
    }
    catch(err){
        console.log(err);
    }
}

getData();

// fs.readFile(filepath, {
//     encoding: 'utf-8'
// })
//     .then((data) => {
//         data = JSON.parse(data);
//         data.forEach(d => {
//             console.log(d);  
//         })
//         console.log(data);
//     })
//     .catch(err => {
//         console.log(err);
//     })