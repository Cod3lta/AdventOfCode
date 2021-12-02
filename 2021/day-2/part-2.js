const parser = require('./parse');

let h = 0 // horizontal position
let d = 0 // depth position
let a = 0 // aim

let moves = {
    'forward': x => { 
        h += x
        d += a * x
    },
    'up': x => {
        a -= x
    },
    'down': x => {
        a += x
    }
}

parser.parse('data.txt').then(data => {
    data.forEach(e => {
        let fnc = moves[e.split(' ')[0]]
        let value = parseInt(e.split(' ')[1])
        fnc(value)
    })
    console.log(h * d)
})