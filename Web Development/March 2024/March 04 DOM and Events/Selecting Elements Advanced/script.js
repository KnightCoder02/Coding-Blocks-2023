// 1. Using query Selector: Will only give one element
let movie = document.querySelector('.movie');
let movies = document.querySelectorAll('.movie');
console.log(movies);

// Selecting id using query Selector
let gadar = document.querySelector('#gadar');
console.log(gadar);

// Selecting using TagName
let div = document.querySelector('div');
console.log(div);

// Pick the li item that has the class ironman
let ironman = document.querySelector('li.ironman');
console.log(ironman);