function downloadMovie(url){
    return new Promise(function(resolve, reject){
        let ext = url.split('/').pop().split('.').pop();
        if(ext != 'mp4'){
            reject("Correct url link");
        }
        else{
            setTimeout(function(){
                resolve(url.split('/').pop());
            }, 2000);
        }
    })
}

downloadMovie('myurl.com/avengers.mp4')
.then(function(movie){
    console.log(movie);
})
.catch(function(err){
    console.log(err)
})