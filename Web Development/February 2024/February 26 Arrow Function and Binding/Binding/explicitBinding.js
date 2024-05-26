function hello(state, country){
    console.log("Name",this.name);
    console.log("Hobby",this.hobby);
    console.log("State",state);
    console.log("Country",country);
}

let person1 = {
    name: "Manav",
    hobby: "Travelling"
}

let person2 = {
    name: "Vashu",
    hobby: "Bakchodi"
}

// 1. Bind through call: Inbuilt function to change the binding inside hello function
// Syntax: hello.call(this, arguments); 
hello.call(person1, "Delhi", "India"); //This will point to person1
hello.call(person2, "Delhi", "India"); //This will point to person2

// 2. Bind through apply
// Arguments are written inside the array
// Syntax: hello.apply(this, [arguments]);
// call and apply can invoke function immediately
hello.apply(person2, ["Delhi", "India"]); //This will point to person2

// 3. Change this through Bind
// Bind does not call function immediately. It returns function thta can be called later on
let f = hello.bind(person1);
f("Delhi", "India");

let f1 = hello.bind(person2, "Texas");
f1("USA");

let f3 = hello.bind(person1, "Mumbai", "India");
f3();