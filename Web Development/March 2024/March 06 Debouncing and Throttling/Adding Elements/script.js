let btn = document.querySelector('.btn');
let movieList = document.querySelector('.movieList');

let movies = [
    "Avengers",
    "Thor",
    "Ironman",
    "Loki",
    "Gadar"
];

let imgLinks = [
    'https://i.imgflip.com/2/3q84ls.jpg',
    'https://i.imgflip.com/2/3q84ls.jpg',
    'https://i.imgflip.com/2/3q84ls.jpg',
    'https://i.imgflip.com/2/3q84ls.jpg'
]

let i = 0;
btn.addEventListener('click', () => {
    console.log(movieList.innerHTML);
    if(i == movies.length){
        let url = imgLinks[Math.floor((Math.random()*imgLinks.length))];
        let img = document.createElement('img');
        img.setAttribute('src', url);
        movieList.appendChild(img);
        i++;
    }
    else if(i < movies.length){
        let li = document.createElement('li');
        li.innerText = movies[i];
        movieList.appendChild(li);
        i++;
    }
})