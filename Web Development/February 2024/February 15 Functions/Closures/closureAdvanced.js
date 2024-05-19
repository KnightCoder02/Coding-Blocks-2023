function grandFather(){
    var x = 1;

    function parent(){
        x++;

        function child(){
            x++;
            console.log(x);
        }
        return child;
    }
    return parent;
}

let fun = grandFather();
let f1 = fun();
let f2 = fun();

f1();
f1();
f2();
f2();