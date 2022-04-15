function processData(input) {
    //Enter your code here}
    var is = input.split("\n");
    var giver = [];
    var taker = [];
    for (var i = 1; i < is.length; i++) {
        if (is[i][0] === "1") {
            var value = is[i].slice(1).trim();
            taker.push(value);
        }
        if (is[i][0] === "2") {
            if (giver.length > 0) giver.pop();
            else {
                while (taker.length !== 0) giver.push(taker.pop());
                giver.pop();
            }
        }
        if (is[i][0] === "3") {
            if (giver.length > 0) console.log(giver[giver.length-1]);
            else {
                while (taker.length !== 0) giver.push(taker.pop());
                console.log(giver[giver.length-1]);
            }
        }
    }
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
