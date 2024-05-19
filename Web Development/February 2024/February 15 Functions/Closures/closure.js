function Parent(){
    var x = 1;
    
    function Child(){
        x++;
        console.log(x);
    }
    return Child;
}

let f = Parent();
let f1 = Parent();

f();
f();

f1();
f1();