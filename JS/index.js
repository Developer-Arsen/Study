// function isPermutation (str1, str2) {
//     if (str1.length != str2.length) {
//         return false;
//     }

//     let obj = {};
//     let obj2 = {};

//     for(let i = 0 ; i < str1.length; ++i) {
//         obj[i] = str1[i];
//         obj2[str2[i]] = 1;
//     }

//     for (let i = 0 ; i < str1.length; ++i) {
//         if (!obj2[obj[i]]) return false;
//     }

//     return true;
// }

// class Stack {
//     #minArr;

//     constructor () {
//         this.arr = [];
//         this.#minArr = [Infinity];
//         this.text = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
//     }

//     push(val) {
//         if (val < this.#minArr[this.#minArr.length - 1] ) {
//             this.#minArr.push(val);
//         }
//         this.arr.push(val);
//     }

//     pop() {
//         this.arr.pop();
//         this.#minArr.pop();
//     }

//     get min() {
//         return this.#minArr[this.#minArr.length - 1];
//     }
// }

// // let stack = new Stack();
// // stack.push(1);
// // stack.push(2);
// // stack.push(3);
// // stack.push(3);
// // stack.push(3);
// // stack.push(-12);
// // console.log(stack.min);


// class Queue {
//     stack1;
//     stack2;

//     // constructor() {
//     //     this.stack1 = [];
//     //     this.stack2 = [];
//     // }



//     push(val) {

//         for(let i = 0 ; i < this.stack1.length; i++) {
//             this.stack2.push(this.stack1[i]);
//         }

//         this.stack1.push(val);
        
//         for(let i = 0 ; i < this.stack2.length; i++) {
//             this.stack1.push(this.stack2[i]);
//         }
//     }

//     pop() {
//         this.stack1.pop();
//     }

//     peek() {
//         return this.stack1.at(-1);
//     }

//     isEmpty() {
//         return this.stack1.length;
//     }
// }



// function a () {
//     console.log(this == globalThis);
// }

// function add(x,y,j,k) {
//     return x + y + j + k;
// }

// function f (cb) {
//     return function fn(...args) {
//         if (args.length == 4) { 
//             return cb(...args);
//         }
//         else {
//             return function (...argv) {
//                 return fn(...args, ...argv);
//             }
//         }
//     }
// }

// function good() {
//     const obj = { a: 1, b: 2, c: 3 };
//     let sum = 0;
  
//     for (let i = 0; i < 10_000_000; ++i) {
//       if (i % 1_000_000 == 0) {
//         obj.a = 97;
//       }
//       sum += obj.a + obj.b + obj.c;
//     }
  
//     return sum;
// }

// function bad() {
//     const ob = { a: 1, b: 2, c: 3 };
//     let sum = 0;
    
//     for (i = 0; i < 10_000_000; i++) {
//       if (i % 1_000_000 == 0) {
//         delete ob.a;
//         ob.d = 1;
//         ob.a = ob.d;
//       }
//       sum += ob.a + ob.b + ob.c;
//     }
    
//     return sum;
// }

// function bsr(arr, target, start, end) {
//     if (start > end) {
//         return -1;
//     }

//     let midIndex = parseInt((start + end) / 2);
//     if (arr[midIndex] === target && (Number.isNaN(target) && Number.isNaN(arr[midIndex]))) {
//         return midIndex;
//     }

//     if (arr[midIndex] > target) {
//         return bsr(arr, target, start, midIndex - 1);
//     }

//     return bsr(arr, target, mid + 1, end);

    
// }

// let cache = {}

// function factGlob(n) {
//     if (cache[n] !== undefined) {
//         return cache[n]
//     }

//     if (n <= 1) {
//         return 1;
//     } 

//     cache[n] = n * f(n -1);
//     return cache[n];
// }


// function f(n) {
//     f.obj = f.obj || {};
//     if (f.obj[n] !== undefined) {
//         return f.obj[n]
//     }

//     if (n <= 1) {
//         return 1;
//     } 


//     f.obj[n] = n * f(n -1);;
//     return f.obj[n];
// }

// function factClos() {
//     let obj = {};
//     return function f(n) {
//         if (obj[n] !== undefined) {
//             return obj[n]
//         }
    
//         if (n <= 1) {
//             return 1;
//         } 
    
//         obj[n] = n * f(n -1);
//         return obj[n];
//     }
// }


// function f (n) {
//     let sum = n;
    
//     function b(y) {
//         sum += y;
        
//         b.sum = sum;
//         return b;
//     }

//     return b;
// }

// const originalLog = console.log;


// console.log = function (...args) {
//     args = args.map(arg => {
//         if (typeof arg === "function") {
//             if (arg.name = "b") {
//                 return arg.sum;
//             }
//         }
//         return arg;  
//     });
//     originalLog.apply(console, args);
// };

// let x = f(2)(3)(4)(10);
// // console.log(x);


// // let str = "asa";
// // console.log(Number.MAX_VALUE, Math.pow(2, 608), Number(-0))
// // console.log(Array.prototype.map.call(str, (s) => s.toUpperCase()).join())
// // console.log(1 .toFixed(5))

// // function bsr(arr, target, start, end) {
// //     if (start > end) {
// //         return -1;
// //     }

// //     let midIndex = parseInt((start + end) / 2);
// //     if (arr[midIndex] === target || (Number.isNaN(target) && Number.isNaN(arr[midIndex]))) {
// //         return midIndex;
// //     }

// //     if (arr[midIndex] > target) return bsr(arr, target, start, midIndex -1);
// //     return bsr(arr, target, mid + 1, end);
// // }


// // const code = [
// //     {type: 'let', value: '5'},
// //     {type: 'var', value: '6'},
// //     {type: 'var', value: '7'},
// //     {type: 'const', value: '8'}
// // ]

// // code.sort((a,b) => (a.type == "let") - (b.type == "let"))

// // code.sort((a,b) => {
// //     return !((a.type == "var") - (b.type == "var"))
// // })
// // console.log(code)

// // code.forEach((obj) => {
// //     if (obj.type == 'var') {
// //         obj.toString = () => {
// //             return -Infinity;
// //         }
// //     }
// // })
// // let obj1 = {}
// // let obj2 = {}

// // let map = new Map([[obj1, "a"], [obj2, "b"]])


// // // Arajadranq 1
// // function processString(input) {
// //     if (!input.startsWith('ABC')) {
// //         input = input.trim();
// //         console.log(input.slice(5));
// //     } else {
// //         console.log(input);
// //     }
// // }

// // const inputString = "  Hello, this is a test string.  ";
// // processString(inputString);

// // // Arajadranq 2
// // function processArray(arr) {
// //     const filteredArray = arr.filter(str => str !== str.toUpperCase());

// //     if (filteredArray.length > 0) {
// //         filteredArray.pop();
// //     }

// //     console.log(filteredArray);
// // }

// // const inputArray = ["HELLO", "WORLD", "example", "TEST", "sample"];
// // processArray(inputArray);


// // // Arajadranq 1
// // const students = [
// //     { "Name": "Anahit", "Adm_date": "2022-09-01", "grades": [14, 16, 13, 15, 14] },
// //     { "Name": "Babken", "Adm_date": "2021-09-01", "grades": [12, 14, 11, 15, 13] },
// //     { "Name": "Elen", "Adm_date": "2021-09-01", "grades": [14, 14, 13, 13, 14] },
// //     { "Name": "Ara", "Adm_date": "2022-09-01", "grades": [10, 13, 12, 11, 10] },
// //     { "Name": "Nane", "Adm_date": "2022-09-01", "grades": [15, 12, 13, 14, 13] },
// // ];

// // const currentYear = new Date().getFullYear();

// // function checkPalindrome(name) {
// //     const lowerName = name.toLowerCase();
// //     return lowerName === lowerName.split('').reverse().join('');
// // }

// // function calculateAverage(grades) {
// //     return grades.reduce((sum, grade) => sum + grade, 0) / grades.length;
// // }

// // const selectedStudents = [];
// // const uniqueNames = new Set();

// // for (const student of students) {
// //     const admYear = parseInt(student["Adm_date"].slice(0, 4), 10);

// //     if (currentYear - admYear === 2 && checkPalindrome(student["Name"]) && calculateAverage(student["grades"]) < 15) {
// //         if (!uniqueNames.has(student["Name"])) {
// //             selectedStudents.push(student);
// //             uniqueNames.add(student["Name"]);
// //         }
// //     }
// // }

// // for (const student of selectedStudents) {
// //     console.log(student);
// // }


// // const factorial = (n, acc = 1) => {
// //     if (n <= 0) return acc;
// //     factorial.obj ||= {};
    
// //     if (factorial.obj[n]) {
// //         return factorial.obj[n];
// //     } 
    
// //     factorial.obj[n] = factorial(n-1, acc * n);
// //     return factorial.obj[n];
// // }

// // function bn(arr, target) {
// //     let start = 0;
// //     let end = arr.length - 1;

// //     while(start <= end) {
// //         let midIndex = start + end;

// //         if (arr[midIndex] == target) {
// //             return midIndex;
// //         }

// //         if (arr[midIndex] > target) {
// //             end = midIndex - 1;
// //         }
// //         else {
// //             start = midIndex + 1;
// //         }
// //     }

// //     return -1;
// // }


// // function bsr(arr, target, start, end) {
// //     console.log(target)
    
// //     if (start > end) {
// //         return -1;
// //     }

// //     let midIndex = parseInt((start + end) / 2);
// //     if (arr[midIndex] == target) {
// //         return midIndex;
// //     }

// //     if (arr[midIndex] > target) {
// //         return bsr(arr, target, start , midIndex -1);
// //     }
// //     return bsr(arr, target, midIndex + 1, end);
// // }

// // function fib(n) {

// //     let a = 1;
// //     let b = 2;
// //     for (let i = 2; i < n; i++) {
// //         let sum = a + b;
// //         a = b;
// //         b = sum; 
// //     }

// //     return a;
// // }

// // function fibr(n) {
// //     if (n === 0) return 0;
// //     if (n === 1) return 1;

// //     fibr.obj ||= {};

// //     if (fibr.obj[n]) {
// //         return fibr.obj[n];
// //     }

// //     fibr.obj[n] = fibr(n - 1) + fibr(n - 2);
// //     return fibr.obj[n];
// // }


// function fibr(n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (n == 2) return 1;

//     return fibr(n-1) + fibr(n-2) + fibr(n-3);
// }

// function tribonacci(n) {
//     if (n === 0) return 0;
//     if (n === 1 || n === 2) return 1;

//     let a = 0;
//     let b = 1;
//     let c = 1;

//     for (let i = 3; i <= n; i++) {
//         let sum = a + b + c;
//         a = b;
//         b = c;
//         c = sum;
//     }

//     return c;
// }


// function binaryAdd(arr, target) {
//     let start = 0;
//     let end = arr.length - 1;
//     while(start <= end) {
//         let midIndex = parseInt((start + end) / 2);

//         if (arr[midIndex] == target) {
//             return midIndex;
//         }

//         if (arr[midIndex] > target) {
//             end = midIndex - 1;
//         } else {
//             start = midIndex + 1;
//         }

//     }

//     return start;
// }


// let arr = [];

// arr.splice(binaryAdd(arr, 5), 0, 5);
// arr.splice(binaryAdd(arr, 3), 0, 3);
// arr.splice(binaryAdd(arr, 2), 0, 2);
// arr.splice(binaryAdd(arr, 1), 0, 1);
// arr.splice(binaryAdd(arr, 0), 0, 0);

// console.log(arr)

// const data = {
//     x: 1,
//     y: [
//         { z: 2, w: [3, { v: 4 }] },
//         { u: 5, t: { s: 6, r: [ 7, 8 ] }}
//     ],
//     q: { p: 9, o: [10, { n: 11 }] }
// };

// function calculate(obj) {
//     let total = 0;

//     function process(item, inList = false) {
//         if (Array.isArray(item)) {
//             item.forEach(element => process(element, true));
//         } else if (typeof item === 'object' && item !== null) {
//             Object.values(item).forEach(val => process(val, false));
//         } else if (typeof item === 'number') {
//             if (inList && item % 2 !== 0) {
//                 total += item;
//             } else if (!inList && item % 2 === 0) {
//                 total += item;
//             }
//         }
//     }

//     process(obj);
//     return total;
// }

// console.log(calculate(data));


var data = [
    { id: 1, value: { a: 5 } },
    { id: 2, value: { a: 10 } },
    { id: 3, value: { a: 15 } }
];

var ref = data[1].value;
ref.a = 20;

for (let i = 1; i < data.length; i++) {
    if (data[i].id % 2 === 0) {
        data[i].value.a += i * 2;
    } else {
        data[i].value.a -= i;
    }
}

console.log(data[0].value.a);
console.log(data[1].value.a);
console.log(data[2].value.a);

