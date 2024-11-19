
let obj = {
    x: 1,                         // number
    y: NaN,                       // NaN
    name: "example",              // string
    flag: true,                   // boolean
    details: {
        age: 25,                  // number
        hobbies: ["reading", "sports", NaN],  // array with strings and NaN
        address: {
            street: "123 Main St",            // string
        }
    },
};

function isNan(item) {
    return item !== item;
}


function withstack(maindata) {
    let count = 0;
    let stack = [maindata];

    while (stack.length > 0) {
        let current = stack.pop();
        let data = current;
        
        if (current && typeof current == 'object') {
            data = Object.values(current);
        }
        
        data.forEach(item => {
            if (current && typeof item == "object") {
                stack.push(item);
            }
            else {
                count += isNan(item);
            }
        })
    }
    return count;
}

console.log(withstack(obj));
