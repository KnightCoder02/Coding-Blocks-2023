let arr = [1, 2, 3, 4, 5, 6];
let arr1 = [1, 2, 3, 4, "Hello", 6];

Array.prototype.myforEach = function(fun){
    let arr = this;
    for(let i = 0; i < arr.length; i++){
        fun(arr[i], i, arr);
    }
}

arr.myforEach((data, indx, arr) => {
    console.log("Index: ", indx, "Data: ", data, "Arr: ", arr);
})

arr1.myforEach((data, indx, arr) => {
    console.log("Index: ", indx, "Data: ", data, "Arr: ", arr);
})

// Inbuilt forEach
arr.forEach((data, indx, arr) => {
    console.log("Index: ", indx, "Data: ", data, "Arr: ", arr);
})