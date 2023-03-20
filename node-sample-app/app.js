const { sum } = require('addon');

let num1 = 3;
let num2 = 5;
let expected = num1 + num2;

const result = sum(num1, num2);

if (result === expected) {
    console.log('Result is:', result);
} else {
    console.log('Error: Result is:', result, 'but expected:', expected);
}
