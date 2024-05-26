let id = setTimeout(function(){
    console.log("Hello World")
}, 5000, setTimeOut(function(){
    clearTimeout(id);
}, 6000));