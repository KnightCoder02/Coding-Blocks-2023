const express = require('express')
const path = require('path');
const app = express()
const port = 3000;

// If we got request 0f type "get" on path '/' then what to do? Mention it here
// app.get(path, callback);
app.get('/', (req, res) => {
    // console.log(req);
    res.send("Hello, How are you?");
})

app.get('/home', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
})

/* We don't want to do this manually one by one
app.get('/script.js', (req, res) => {
    res.sendFile(path.join(__dirname, 'script.js'));
})

app.get('/style.css', (req, res) => {
    res.sendFile(path.join(__dirname, 'style.css'));
})
*/

// Alternative to the above part is to send all the files inside a folder to the browser at once
let publicPath = path.join(__dirname, "public");
app.use(express.static(publicPath));

app.get('/greetings', (req, res) => {
    res.send("Hey, Good Day! Sir");
})

// PARAMS req: '/greet/manav'
app.get('/greet/:name', (req, res) => {
    console.log(req.params);
    res.send(`Hey, how are you? ${req.params.name}`);
})

// Query Parameters req: '/bye?name=manav&city=delhi'
app.get('/bye', (req, res) => {
    res.send(`Bye, talk to you later ${req.query.name} from ${req.query.city}`);
})

app.listen(port, () => {
    console.log(`http://localhost:${port}`);
});    //This will start the server