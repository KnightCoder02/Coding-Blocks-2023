function add(a, b){
    return a + b;
}

console.log(add(10, 20));

function substract(a, b){
    return a - b;
}

function checkPrime(n){
    for(let i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

module.exports = {
    add,
    msg: "Hello World",
    checkPrime,
    substract
}