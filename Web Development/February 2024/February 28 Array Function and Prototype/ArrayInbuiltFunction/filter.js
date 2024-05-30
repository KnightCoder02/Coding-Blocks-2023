let arr = [1, 2, 3, 4, 5];

let newArr = arr.filter((val, indx, arr) => {
    if(val % 2 == 0)return false;
    else return true;
})

console.log(newArr);