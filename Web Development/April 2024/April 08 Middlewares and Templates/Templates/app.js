const path = require('path');
const express = require('express');
const app = express();
const port = 3000;
const hbs = require('hbs');

hbs.registerPartials(path.join(__dirname + '/views/partials'));
app.set('view engine', 'hbs');
app.use(express.urlencoded({extended: true}));

let todos = ["Cricket", "Dance", "Sing", "Hockey"];

app.get('/', (req, res) => {
    res.render('index', {
        firstname: "Manav",
        lastname: "Aggarwal",
        todos
    })
})

app.post('/todos', async (req, res) => {
    try{
        const {newTask} = req.body;
        todos.push(newTask);
        res.redirect('/');
    }
    catch(err){
        res.send(err);
    }
})

app.get('/deletetask', async (req, res) => {
    try{
        const {name} = req.query;
        todos = todos.filter(t => t!==name);
        res.redirect('/');
    }
    catch(err){
        res.send(err);
    }
})

app.get('/increase', (req, res) => {
    try{
        const {name} = req.query;
        let index = todos.indexOf(name);
        if (index > 0)
            [todos[index - 1], todos[index]] = [todos[index], todos[index - 1]];
        res.redirect('/');
    }
    catch(err){
        res.send(err);
    }
})

app.get('/decrease', (req, res) => {
    try{
        const {name} = req.query;
        let index = todos.indexOf(name);
        if (index < todos.length - 1)
            [todos[index + 1], todos[index]] = [todos[index], todos[index + 1]];
        res.redirect('/');
    }
    catch(err){
        res.send(err);
    }
})

app.listen(port, () => {
    console.log(`http://localhost:` + port);
});