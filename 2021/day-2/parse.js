var fs = require('fs')

module.exports = {
    parse: async function(file) {
        const lines = fs.readFileSync(file, 'utf8').split('\n')
        return lines
    }
}