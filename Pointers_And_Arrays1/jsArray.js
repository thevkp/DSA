let arr = [1, 2, 3, 4, 5];
console.log(arr);

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.question("Enter elements:", function(input){
    arr = input.split(" ").map(item => item.trim());
    console.log(arr);
    rl.close();
})