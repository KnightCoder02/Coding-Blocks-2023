const path = require('path');
const express = require('express');
const app = express();
const PORT = 3000;

const mongoose = require('mongoose');

app.use(express.urlencoded({extended: true}));

const session = require('express-session');
const MongoStore = require('connect-mongo');
app.use(session({
    secret: 'randomSecretKeyValue',
    resave: false,
    saveUninitialized: true,
    store: MongoStore.create({ mongoUrl: 'mongodb+srv://manav:manav@cluster0.mq4xd.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0' })
}))

const hbs = require('hbs');
app.set('view engine', 'hbs');

hbs.registerPartials(__dirname + '/views/partials');

app.use('/', require('./routes/user'));

mongoose.connect('mongodb+srv://manav:manav@cluster0.mq4xd.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0')
    .then(() => {
        app.listen(PORT, () => {
            console.log(`http://localhost:` + PORT);
        });
    })
    .catch((err) => {
        console.log(err);
    })