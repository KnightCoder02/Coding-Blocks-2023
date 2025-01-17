const path = require('path');
const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({extended: true}));  //This will make the body readable
app.use(express.static(path.join(__dirname, 'public')));
app.use(express.json());    // To make axios data readable

// GET: /submit-form | API Route
app.get('/submit-form', (req, res) => {
    const {username, password} = req.query;
    res.send(`Received GET Request on /submnit-form with ${username}, ${password}`);
})

// POST: /submit-form | API Route
app.post('/submit-form', (req, res) => {
    console.log(req.body);
    const {username, password} = req.query;
    res.send(`Received POST Request on /submnit-form with ${username}, ${password}`);
})

app.listen(port, () => {
    console.log(`http://localhost:` + port);
});