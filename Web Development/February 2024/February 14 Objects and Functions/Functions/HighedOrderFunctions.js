function outerFun(){
    // inner function
    function innerFun(){
        console.log("Inside Inner Fun");
        // It return undefined by default
    }

    // return innerFun;
    return innerFun();
}

let f = outerFun();
console.log(f);
// f();

function add(a, b){
    return a + b;
}

function substract(a, b){
    return a - b;
}

function doOperations(add, sub){
    console.log(add(10, 20));
    console.log(substract(30, 10));
}

doOperations(add, substract);
doOperations(function add(a, b){
    return a + b;
    }, 
    function substract(a, b){
    return a - b;
    }
);