function customInstanceOf (obj, constructor) {
  if (obj == null || typeof obj !== 'object' || typeof constructor !== 'function') { return false; }

  let proto = Object.getPrototypeOf(obj);

  while (proto) {
    if (proto == constructor.prototype) {
        return true;
    }

    proto = Object.getPrototypeOf(proto);
  }

  return false;
}


class Animal {}
class Dog extends Animal {}

const dog = new Dog();

console.log(dog instanceof Dog);
console.log(dog instanceof Animal);  
console.log(customInstanceOf(dog, Animal));  
console.log(customInstanceOf(dog, Dog));  