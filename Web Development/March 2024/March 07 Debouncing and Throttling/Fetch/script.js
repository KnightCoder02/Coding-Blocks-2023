let btn = document.querySelector('button');
let factList = document.querySelector('.factList');

btn.addEventListener('click', throttling((ev) => {
    fetch('https://cat-fact.herokuapp.com/facts')
    .then((res) => {
        return res.json();
    })
    .then((res) => {
        console.log(res);
        factList.innerText = "";
        res.forEach((data) => {
            let li = document.createElement('li');
            li.innerText = data.text;
            factList.appendChild(li);
        })
    })
}, 1000));

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