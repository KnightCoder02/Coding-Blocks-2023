let obj = {
    a: 1,
    b: 2,
    fun: function(){
        console.log(this);
        console.log("a", this.a);
        console.log("b", this.b);
        this.c = "Hello";
    }
}

obj.fun();
console.log(obj);