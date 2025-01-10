
let body = document.querySelector('body');
let btn = document.querySelector('.btn');

function clickHandler(){
    console.log("Clicked");
}

btn.addEventListener('click', throttling(clickHandler, 1000));

function throttling(fun, delay){
    let initialTime = 0;
    return function(){
       if(new Date().getTime() - initialTime >= delay){
            initialTime = new Date().getTime();
            fun();
       }
       else{
            console.log("Not possible now");
       }
    }
}