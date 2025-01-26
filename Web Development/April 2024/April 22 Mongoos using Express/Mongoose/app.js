const express = require('express');
const path = require('path');
const app = express();
const port = 3000;

const mongoose = require('mongoose');
const students = require('./database/models/students');
const address = require('./database/models/address');

app.set('view engine', 'hbs');
app.use(express.urlencoded({extended:true}));
app.use(express.json());

// POST: /student
// name, age, marks
app.post('/student', async (req, res) => {
    try{
        const {name, age, marks} = req.body;
        let stu = await students.create({name, age, marks});
        
        res.send({
            msg: "Student Created Successfully",
            student: stu
        })
    }
    catch(err){
        console.log(err);
    }
})

// /students/:limit/:skip, params
// /students?limit=10&skip=0, queryparameter
app.get('/student', async (req, res) => {    
    let {limit, skip} = req.query;
    limit = +limit;
    skip = +skip;
    let stu = await students
        .find()
        .skip(skip)
        .limit(limit)
        .populate('address_id');

    res.send({
        students: stu
    })
})

app.post('/update', async(req, res) => {
})

mongoose.connect('mongodb://127.0.0.1:27017/codingBlocks')
    .then(() => {
        app.listen(port, () => {
        console.log(`http://localhost:` + port);
        });
    })
    .catch(err => {
        console.log(err);
    })
    