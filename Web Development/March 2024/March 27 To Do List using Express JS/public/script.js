const btn = document.querySelector('button');
const inp = document.querySelector('input');

btn.addEventListener('click',async (ev) => {
    ev.preventDefault();    //This stops default behaviour of HTML
    
    // We can send AJAX request from here
    try{
        let {data} = await axios.get(`/gettask?task=${inp.value}`)
        console.log(data); 
    }
    catch(err){
        console.log(err);
    }
})