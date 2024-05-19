// let is block scope, can;t be hoisting
// Var is functional scope, can be hoisting

for(let i = 0; i < 5; i++){
    console.log(i);
}

console.log(i); //Error

for(var j = 0; j < 5; j++){
    console.log(j);
}

console.log(j);

let x = 1;
function fun(){
    console.log(x);

    let x = 1;
    console.log(x);
    x++;
}

fun();
console.log(x);