let arr = [1, 2, 3, 4, "Hello", true, 1.11];
console.log(arr);

arr.unshift("Happy");
console.log(arr);

arr.shift("Happy");
console.log(arr);

arr.push("Valentine");
console.log(arr);

arr.pop();
console.log(arr);

// for of loop
for(let el of arr){
    console.log(el);
}

for(let inx in arr){
    console.log(inx);
}

// Searching Key
let indx = arr.indexOf("Hello");
console.log("Index: ", indx);

let inx = arr.indexOf("Hell"); // value does not exist then it prints -1
console.log("Index: ", inx);