function sendReq(){
    axios.post('/submnit-form', {
        username: 'Manav',
        password: 'Manav02'
    })
    .then((data) => {
        console.log(data);
    })
    .catch(err => {
        console.log(err);
    })
}

sendReq();