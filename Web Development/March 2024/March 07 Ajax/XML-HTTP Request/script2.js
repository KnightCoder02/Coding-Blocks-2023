const btn = document.querySelector('button');
const ul = docment.querySelector('ul');

function getData(url){
    return new Promise((resolve, reject) => {
        // 1. Create the XML Http Request Object
        let xml = new XMLHttpRequest();

        // 2. Setup the Request
        xml.open('GET', url);

        // 3. If request is success
        xml.onload = (res) => {
            let data = JSON.parse(res.target.response);
            resolve(data);
        }

        // 4. If request is failed
        xml.onerror = (err) => {
            reject(err);
        }

        xml.send(); //To send request we have to do list
    })
}

btn.addEventListener('click', () => {
    getData('https://cat-fact.herokuapp.com/facts')
    .then((data) => {
        ul.innerText = '';
        data.forEach((d) => {
            let li = document.createElement('li');
            li.innerText = d.text;
            ul.appendChild(li);
        })
    }).catch((err) => {
        console.log(err);
    })
})