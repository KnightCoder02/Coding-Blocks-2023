const User = require('../models/user');

const bcrypt = require('bcrypt');
const saltRounds = 10;

module.exports.getHome = (req, res) => {
    res.render('index')
}

module.exports.getSignup = (req, res) => {
    res.render('signup');
}

module.exports.getProfile = (req, res, next) => {
    res.render('profile', {
        username: req.session.username
    });
}

module.exports.getLogin = (req, res) => {
    if(req.session.isLoggedIn == true){
        return res.redirect('/profile');
    }
    res.render('login');
}

module.exports.getLogout = (req, res) => {
    req.session.destroy(function (err){
        if(err){
            return res.send(err);
        }
        res.redirect('/login');
    })
}

module.exports.postSignup = async (req, res) => {
    const {username, password} = req.body;
    try{
        let user = await User.findOne({username});
        if(user)
            return res.render('signup', {
                msg: "Username already taken, choose another name"
            })

        bcrypt.hash(password, saltRounds, async function (err, hash){
            user = await User.create({
                username,
                password: hash
            })

            res.render('login', {
                msg: "Account created successfully, login to continue"
            })
        });
    }
    catch (err) {
        res.send(err);
    }
}

module.exports.postLogin = async (req, res) => {
    const {username, password} = req.body;
    try{
        let user = await User.findOne({ username });
        if(!user){
            return res.render('login', {
                msg: "Invalid Username"
            })
        }

        // If user found
        bcrypt.compare(password, user.password, function (err, result){
            if(result == true){
                req.session.username = username;
                req.session.isLoggedIn = true;
                res.redirect('/profile');
            }
            else{
                res.render('login', {
                    msg: "Invalid Password try again"
                })
            }
        });

    }
    catch(err){
        res.send(err);
    }
}