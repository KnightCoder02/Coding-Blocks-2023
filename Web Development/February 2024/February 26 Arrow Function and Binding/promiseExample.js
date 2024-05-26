function download(url){
    return new Promise(function(resolve, reject){
        console.log("Downloading starts from ", url);
        setTimeout(function(){
            let extension = url.split('.').pop();
            if(['webp', 'png', 'jpg'].indexOf(extension) != -1){
                let img = url.split('/').pop();
                resolve(img);
            }
            else{
                reject("Correct the URL");
            }
        }, 1000);
    })
}

function compress(file){
    return new Promise(function(resolve, reject){
        console.log("Compression starts of ", file)
        setTimeout(function(){
            let compressedImg = file.split('.')[0]+'.zip';
            console.log("Compression completed, ", compressedImg);
            resolve(compressedImg);
        }, 1000);
    })
}

function upload(file){
    return new Promise(function(resolve, reject){
        console.log("Uploading starts of ", file)
        setTimeout(function(){
            let newLink = 'http://newSite.com/'+file;
            console.log("Uploading completed, ", newLink);
            resolve(newLink);
        }, 2000);
    })
}

download('http://randomurl.com/avengers.jpg')
.then(function(img){
    console.log("Download completed, ", img);
    return img;
})
.then(compress)
.then(upload)
.then(function(newLink){
    console.log("Everything Done", newLink);
})
.catch(function(err){
    console.log(err);
})