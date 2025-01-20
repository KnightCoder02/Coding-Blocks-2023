const path = require('path');
const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({extended:true}));
app.use(express.json());

// Path specific middlewares
// Works for: /result, /result/a, /result/a, /result/a/b/c/d
// Won't work for: /resulta
app.use('/result', (req, res, next) => {
    console.log("Running result middleware");

    // if next() calls, request go ahead otherwise not
    next();
})

// Generic midddleware: Works for all requests
let x = true;
app.use((req, res, next) => {
    console.log("Running generic middleware");
    if(x == false){
        return res.send("Not Allowed");
    }
    next();
})

// Exact path match middleware
const isLoggedIn = require('./isLoggedIn');
app.get('/', isLoggedIn, (req, res, next) => {
    res.send("Hello World");
})

app.get('/result', (req, res) => {
    res.send("Result request received success");
})

app.listen(port, () => {
    console.log(`http://localhost:` + port);
})