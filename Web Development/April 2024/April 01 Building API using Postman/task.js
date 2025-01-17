const path = require('path');
const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({extended: true}));

let students = ["Abhishek Pandey", "Archana", "Varda", "Ishan Gupta"];
let teachers = ["Kartik", "Monu", "Sabeel", "Mosina"];

// 1. GET '/students': GET Details of all students
app.get('/students', (req, res) => {
    res.send(students);
})

// 2. POST '/student': Add one student to students[]
app.post('/student', (req, res) => {
    const {name} = req.body;
    students.unshift(name);
    res.redirect('/students');
})

// 3. POST '/student/remove': Remove the student by name provided in queryParam
app.post('/student/remove', (req, res) => {
    const {name} = req.query;
    students = students.filter(s => s !== name);
    res.redirect('/students');
})

// 4. GET '/teachers': GET Details of all teachers
app.get('/teachers', (req, res) => {
    res.send(teachers);
})

// 5. POST '/teachers/update': Update the name of the teacher using body {oldname, newName}
app.post('/teachers/update', (req, res) => {
    let {oldName, newName} = req.body;
    let index = teachers.indexOf(oldName);
    if(index != -1)
        teachers[index] = newName;
    res.redirect('/teachers');
})

app.listen(port, () => {
    console.log(`http://localhost:` + port);
})