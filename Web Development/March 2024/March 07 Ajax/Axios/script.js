const btn = document.querySelector('button');
const ul = document.querySelector('ul');

btn.addEventListener('click', () => {
    axios('https://cat-fact.herokuapp.com/facts')
    .then(res => {
        let data = res.data;
        ul.innerText = '';
        data.forEach((d) => {
            let li = document.createElement('li');
            li.innerText = d.text;
            ul.appendChild(li);
        })
    })
    .catch(err => console.log(err));
})