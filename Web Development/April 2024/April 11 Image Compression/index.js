console.log('hello world');
let inp = document.getElementById('inp');

inp.onchange = function(e){
    console.log(e.target.files[0], 'non-compressed');
    let file = e.target.files[0];

    const options = { 
        maxSizeMB: 1,   // (default: Number.POSITIVE_INFINITY)
    }
      
    imageCompression(file, options)
        .then(res => {
            console.log(res, 'compressed');
        })
}