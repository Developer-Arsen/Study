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

function f(data) {
    let nested = null;
    let count = 0;

    Object.values(data).forEach((data2) => {
        if (Array.isArray(data2) || typeof data == 'object') {
            nested = data2;

            while (nested) {
                
                if (Array.isArray(nested)) {
                    console.log(1);
                    console.log(nested);
                    nested = nested.filter((elem) => {
                        if (typeof elem == 'object') return true;
                        count += isNan(elem);
                    })
                } else if (typeof nested == "object") {
                    console.log(2);
                    console.log(nested);
                    nested = Object.values(nested).filter((elem) => {
                        if (typeof elem == 'object') return true;
                        count += isNan(elem);
                    })
                }
                nested = null;
            }
        }
        count += isNan(data2);
    });
    console.log(count);
}


// if (!Array.isArray(data) && typeof data == 'object') {
//     console.log("obj", data);
//     data = Object.values(data).filter(element => {
//        if (typeof element == 'object') {
//             return true;
//        } 
//        count += isNan(element);
//        return false;
//     });
// } 
// else if (Array.isArray(data)) {
//     console.log("arr");
//     data = data.filter(element => { 
//         if (typeof element == 'object') {
//             data = Object.values(element).filter(() => {

//             })
//         } 
//     });


// }
// console.log(typeof data);
// console.log(data)
// }

// console.log(stack);


f(obj);