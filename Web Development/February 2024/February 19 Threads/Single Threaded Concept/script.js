// Let's create a function to add 1 second of delay
// endTime - startTime >= 1 sec

function delayOneSec(){
    let currentTime = new Data().getTime();
    while(new Data().getTime() - currentTime < 1000){

    }
}

function delayNSec(){
    for(let i = 0; i < n; i++){
        delayOneSec();
    }
}

delayNSec(5);
console.log("Hello World");