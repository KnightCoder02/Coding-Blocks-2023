function add(a, b){
    return a + b;
}
console.log(add(10, 20));

function sayHi(name){
    return "Hello " + name;
}
console.log(sayHi("Manav"));

let sayHello = function hello(name){
    return "Oyee, Hello " + name;
}
console.log(sayHello("Aggarwal"));
// Since, we invoke the function hello(){} by the name 'hello' therefore there is no use of even writing it, we can skip that part.
// console.log(hello("Aggarwal"));

// Anonymous Function is stored inside sayBye variable
let sayBye = function(name){
    return "Bye " + name;
}
console.log(sayBye("Manav"));