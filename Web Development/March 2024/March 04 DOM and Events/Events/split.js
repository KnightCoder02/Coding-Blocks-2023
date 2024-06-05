let btn = document.querySelector('button');
let para = document.querySelector('.para');
console.log(btn);
console.log(para);

btn.addEventListener('click', () => {
    console.log("Clicked");
})

btn.addEventListener('click', () => {
    console.log("I am Clicked");
})