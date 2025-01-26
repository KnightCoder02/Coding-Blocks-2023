const path = require('path');
const express = require('express');
const app = express();
const port = 3000;
const {MongoClient} = require("mongodb");

app.set('view engine', 'hbs');
app.use(express.urlencoded({extended:true}));

// Connection URL
const url = 'mongodb://127.0.0.1:27017';
const client = new MongoClient(url);
let cbDB = undefined;

async function main(){
    if(cbDB != undefined){
        return cbDB;
    }
    // Use connect method to connect to the server
    await client.connect();
    
    console.log('Connected successfully to server');
    const db = client.db("codingBlocks");
    cbDB = db.collection('documents');
    
    return 'done.';
}

main()
    .then(() => {
        app.listen(port, () => {
            console.log(`http://localhost:` + port);
        });
    })
    .catch(err => {
        console.log("Error");
    })