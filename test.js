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
