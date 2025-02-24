// new Promise((res, rej) => {
//   rej(1);
// })
//   .catch((msg) => console.log(msg))
//   .then((msg) => console.log(msg));

// Promise.resolve()
//   .then(() => {
//     throw new Error();
//   })
//   .catch(() => console.log(65))
//   .then(() => {
//     console.log(5);
//   });

// for (key in null) {
//   console.log(key);
// }
// (async () => {
//   const sleep = async (delay) => {
//     return new Promise((res, rej) => {
//       setTimeout(() => {
//         res(console.log("sleep"));
//       }, delay);
//     });
//   };

//   console.log("start");
//   await sleep(2000);
//   console.log("end");
// })();

// function Person(name, age) {
//   this.name = name;
//   this.age = age;
//   this.greet = function () {
//     console.log(
//       `Hello, my name is ${this.name} and I am ${this.age} years old.`
//     );
//   };
// }

// const person1 = Person("Alice", 25);
// console.log(person1)
// // const person2 = new Person("Bob", 30);

// console.log(person1.name); // Output: "Alice"

// person1.greet(); // Output: "Hello, my name is Alice and I am 25 years old."

// const test = () => {
//   return function a(...args) {
//     if (args.length >= 4) return args.reduce((acc, x) => acc + x, 0);

//     return (arg) => a(...args, arg);
//   };
// };

// const b = test();
// console.log(b(12)(22)(3)(4));

// function limitCountParmas(...args) {
//   if (args.length == 4) {
//     return args.slice(0, 4).reduce((aggr, value) => aggr + value, 0);
//   }
//   return function (...currnetArgs) {
//     return limitCountParmas(...args, ...currnetArgs);
//   };
// }
// console.log(limitCountParmas(1)(2)(3)(4));

const test = () => {
  let x = 0;
  const add = () => x++;
  const sub = () => x--;
  return {
    add,
    sub,
  };
};

// let a = test();
// console.log(a.add());
// console.log(a.add());
// console.log(a.add());

// console.log(a.subtract());
// console.log(a.subtract());
// console.log(a.subtract());
const { add, sub } = test();
console.log(add());
console.log(add());
console.log(add());
console.log(sub());
console.log(sub());
console.log(sub());
