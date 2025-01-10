let body = document.querySelector('body');
let navBar = document.querySelector('.navBar');

function scrollFun(){
    console.log("Scrolling");
}

window.addEventListener('scroll', debounce(scrollFun, 1000));

function debounce(fun, delay){
    let id;
    return function(){
        clearInterval(id);
        let id = setTimeout(() => {
            fun();
        }, delay);
    }
}