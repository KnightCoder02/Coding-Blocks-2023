let Obj = {
    a: 1,
    "Hello World": "Earth",
    "": "Empty String",
    " ": "Space",
    "Hello":"World"
};

console.log(Obj.a);
console.log(Obj.Hello);
// console.log(Obj."Hello World"); //This don't work
console.log(Obj["Hello World"]);


// for in loop
for(let k in Obj){
    console.log(Obj[k]);
}

