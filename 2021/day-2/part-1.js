const parser = require('./parse');

let h = 0 // horizontal position
let d = 0 // depth position

let moves = {
    'forward':  x => h += x ,
    'up':       x => d -= x ,
    'down':     x => d += x
}

parser.parse('data.txt').then(data => {
    data.forEach(e => {
        let fnc = moves[e.split(' ')[0]]
        let value = parseInt(e.split(' ')[1])
        fnc(value)
    })
    console.log(h * d)
})