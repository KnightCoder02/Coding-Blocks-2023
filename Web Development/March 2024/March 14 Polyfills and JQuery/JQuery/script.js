let body = $('body');
console.log(body);

let b = document.querySelector('body');
let b1 = $(b);
console.log(b1);

let h1 = $('<h1>');
body
    .append(
        h1.text('Hello World').css('font-size','54px')
    )
    .append(
        $('<button>')
            .text('Click Me')
            .addClass('button')
            .click(ev => {
                $(ev.target).css('background-color', 'magenta');
            })
            .dblclick(ev => {
                console.log("Why press double");
            })
    )
    .append(
        $('<ul>')
            .html(
                '<li>Avengers</li> <li>Thor</li> <li>Ironman</li>'
            )
            .addClass('movies')
    )
