// Syntax
// let p = new Promise(function(resolve, reject){});
// p.then(resolveFun, rejectFun);
// p.then(resolveFun).catch(rejectFun);

let isPromiseFulfill = false;
let p = new Promise(function(resolve, reject){
    if(isPromiseFulfill){
        resolve("Fulfilled");
    }
    else{
        reject("Not fulfilled");
    }
})

// p.then(function(msg){
//     console.log(msg);
// }, function(err){
//     console.log(err);
// });

p.then(function(msg){
    console.log(msg);
}).catch(function(err){
    console.log(err);
})