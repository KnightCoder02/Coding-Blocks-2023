let movies = document.querySelectorAll('.movie');
let body = document.querySelector('body');

movies.forEach((item) => {
    console.log(item);
    item.style.color = 'blue';
    item.style.fontSize = '40px';
    item.style.backgroundColor = 'black';
    item.style.listStyle = 'none';
})

let x = 1;
setInterval(() => {
    x = 1 - x;
    if(x){
        body.style.backgroundColor = 'black';
        body.style.color = 'yellow';
    }
    else{
        body.style.backgroundColor = 'white';
        body.style.color = 'black';
    }
}, 1000);

// Usecase of setInterval
// let id = setInterval(() => {
//     console.log("Hello");
// }, 1000);

// setTimeout(() => {
//     clearInterval(id);
// }, 5000);