module.export = function isLoggedIn(req, res, next){
    let loggedIn = false;
    if(loggedIn === false){
        return res.send("Login First");
    }
    next();
}