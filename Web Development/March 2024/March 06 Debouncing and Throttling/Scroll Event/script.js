let body = document.querySelector('body');
let navBar = document.querySelector('.navBar');

window.onscroll = (ev) => {
    if(window.scrollY > 300){
        navBar.style.backgroundColor = "orange";
    }
    else{
        navBar.style.backgroundColor = "white";
    }
}

window.onscrollend = (ev) => {
    console.log("Ending Scroll");
}