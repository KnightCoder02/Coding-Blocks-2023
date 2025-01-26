const path = require('path');
const express = require('express');
const app = express();
const port = 3000;
const mongoose = require('mongoose');

app.set('view engine', 'hbs');
app.use(express.urlencoded({extended:true}));

// Routes
// /admin, /admin/abc, /admin/abc/def, /admin/abc/def/../../
const adminRouter = require('./routes/admin');
app.use('/admin', adminRouter);

mongoose.connect('mongodb://127.0.0.1:27017/ecommerce').then(() => {
    app.listen(port, () => {
        console.log(`http://localhost:` + port);
    });
})
.catch(err => {
    console.log(err);
})