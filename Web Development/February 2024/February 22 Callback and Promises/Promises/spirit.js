let maggiLekarAauga = new Promise(function(resolve, reject){
    setTimeout(function(){
        let dukaanKhuliHai = true;
        if(dukaanKhuliHai){
            resolve("Maggi mil gayi");
        }
        else{
            reject("Maggi nhi mili");
        }
    }, 2000);
})

maggiLekarAauga.then(function(data){
    console.log(data);
}).catch(function(msg){
    console.log(msg);
})