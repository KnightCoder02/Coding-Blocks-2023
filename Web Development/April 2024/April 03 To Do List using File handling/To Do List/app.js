const path = require('path');
const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({extended: true}));  //This will make the body readable
app.use(express.static(path.join(__dirname, 'public')));
app.use(express.json());    // To make axios data readable

let todos = ["Cricket", "Dance", "Sing", "Hockey"];

// 1. GET '/todos': Return all the todos
app.get('/todos', (req, res) =>{
    res.send(todos);
})

// 2. POST '/todos': Add a newTask to todos array
app.post('/todos', (req, res) => {
    const {newTask} = req.body;

    let index = todos.indexOf(newTask);
    if(index == -1){    //Prevents adding duplicate tasks
        // todos.push(newTask); //It adds newTask in the end of the array
        todos.unshift(newTask); //It adds newTask in the beginning of the array
    }

    // res.send(todos); //It will send the response to the client
    res.redirect('/todos'); //It will send the response on GET '/todos'
})

// 3. GET '/increase': Increase the priority of a given task {name}
app.get('/increase', (req, res) => {
    const {name} = req.query;
    let index = todos.indexOf(name);
    if(index != -1 && index > 0 && index < todos.length){
        [todos[index], todos[index - 1]] = [todos[index - 1], todos[index]]; 
    }
    res.redirect('/todos');
})

// 4. GET '/decrease': Decrease the priority of a given task {name}
app.get('/decrease', (req, res) => {
    const {name} = req.query;
    let index = todos.indexOf(name);
    if(index != -1 && index >= 0 && index < todos.length - 1){
        [todos[index], todos[index + 1]] = [todos[index + 1], todos[index]]; 
    }
    res.redirect('/todos');
})

// 5. GET '/deletetask': Delete a task from todo list by name
    // name will come in query parameter
app.get('/deletetask', (req, res) => {
    const {name} = req.query;
    todos = todos.filter(t => t !== name);
    res.redirect('/todos');
})

app.listen(port, () => {
    console.log(`http://localhost:` + port);
});