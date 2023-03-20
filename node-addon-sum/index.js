const addon = require('bindings')('add');

const sum = (a, b) => {
    const path = __dirname + '\\build\\Release\\NativeLibrary.dll'
    const result = addon.add(a, b, path);
    return result;
}

module.exports = {
    sum
};