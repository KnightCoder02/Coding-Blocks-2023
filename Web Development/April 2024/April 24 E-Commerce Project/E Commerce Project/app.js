const path = require('path');
const express = require('express');
const app = express();
const mongoose = require('mongoose');
const port = 3000;

// setting up the partials of HBS
const hbs = require('hbs');
hbs.registerPartials(__dirname + '/views/partials');

app.set('view engine', 'hbs');
app.use(express.urlencoded({extended:true}));
app.use(express.static(path.join(__dirname, 'public')));

app.get('/', (req, res, next) => {
    res.render('index');
})

// Routes
// /admin, /admin/abc, /admin/abc/def, /admin/abc/def/../../
const adminRouter = require('./routes/admin');
app.use('/admin', adminRouter);

mongoose.connect('mongodb://127.0.0.1:27017/e-commerce').then(() => {
    app.listen(port, () => {
        console.log(`http://localhost:` + port);
    });
})
.catch(err => {
    console.log(err);
})