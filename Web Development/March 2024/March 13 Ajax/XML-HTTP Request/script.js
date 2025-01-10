const btn = document.querySelector('button');
const ul = docment.querySelector('ul');

// 1. Create the XML Http Request Object
let xml = new XMLHttpRequest();

// 2. Setup the Request
let url = 'https://cat-fact.herokuapp.com/facts';
xml.open('GET', url);

// 3. If request is success
xml.onload = (res) => {
    let data = JSON.parse(res.target.response);
    data.forEach((d) => {
        let li = document.createElement('li');
        li.innerText = d.text;
        ul.appendChild(li);
    })
}

// 4. If request is failed
xml.onerror = (err) => {
    console.log(err);
}

btn.addEventListener('click', () => {
    xml.send(); //To send request we have to do list
})