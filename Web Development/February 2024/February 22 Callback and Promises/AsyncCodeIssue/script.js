function mummyMaggiBanado(cb){
    setTimeout(function(){
        console.log("Mummy Maggi Bnado");
        cb(maggiBanaStart); //This is a callback function of mummyMaggiBanado
    }, 2000);
}

function jaaMarketSeMaggiLaa(cb){
    setTimeout(function(){
        console.log("Jakar Market se maggi lekar aa");
        cb();
    }, 2000);
}

function maggiBanaStart(){
    setTimeout(function(){
        console.log("Maggi Bnana started");
    }, 2000);
}

mummyMaggiBanado(jaaMarketSeMaggiLaa);