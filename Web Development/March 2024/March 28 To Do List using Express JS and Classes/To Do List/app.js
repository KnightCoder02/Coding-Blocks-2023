const express = require('express')
const path = require('path');
const app = express()
const port = 3000;

let publicPath = path.join(__dirname, "public");
app.use(express.static(publicPath));
app.use(express.json());

let todos = ["Dancing", "Singing", "Coding", "Reading"];
app.get('/todos', (req, res) => {
    res.status(200).send(todos);
})

app.get('/addtask', (req, res) => {
    let {task} = req.query;
    // If task is already in list then don't add it to the array
    if(!todos.includes(task)){
        todos.push(task);
    }
    res.redirect('/todos');
})

app.use((req, res, next) => {
    res.status(404).json("Error 404: Page not Found");
})

app.get('/increase', (req, res) => {
    const {task} = req.query;
    let indx = todos.indexOf(task);
    
    if(indx > 0 && indx <= todos.length - 1){
        let temp = todos[indx];
        todos[indx] = todos[indx - 1];
        todos[indx - 1] = temp;
    } 
    res.redirect('/todos');
})

app.get('/decrease', (req, res) => {
    const {task} = req.query;
    let indx = todos.indexOf(task);
    
    if(indx >= 0 && indx < todos.length - 1){
        let temp = todos[indx];
        todos[indx] = todos[indx + 1];
        todos[indx + 1] = temp;
    }
    res.redirect('/todos');
})

app.get('/delete', (req, res) => {
    const {task} = req.query;
    todos = todos.filter(d => d != task);
    res.redirect('/todos');
})

app.listen(port, () => {
    console.log(`http://localhost:${port}`);
});    //This will start the server