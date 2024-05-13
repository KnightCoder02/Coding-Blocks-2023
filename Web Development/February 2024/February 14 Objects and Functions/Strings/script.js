let str = "Hello World Learning Strings";
console.log(str);

for(let i = 0; i < str.length; i++){
    console.log(str[i]);
}

for(let inx in str){
    console.log(str[inx]);
}

for(let el of str){
    console.log(el);
}