let movies = document.querySelectorAll('.movie');
let body = document.querySelector('body');

// classList
// 1. add
// 2. remove
// 3. toggle: If there is a class then remove and if there is no class then add a class
// Adding a class to an element using js
body.classList.add('theme-1');

setTimeout(() => {
    body.classList.remove('theme-1');
}, 3000);

setInterval(() => {
    body.classList.toggle('theme-2');
}, 1000);