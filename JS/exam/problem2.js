const customInstanceOf = (obj, constructor) => {
    let proto = Object.getPrototypeOf(obj);
    while (proto) {
        if (constructor.prototype == proto) {
            return true;
        }
        proto = Object.getPrototypeOf(proto);
    }
    return false;
}

class Animal {}
class Dog extends Animal {}

const dog = new Dog();

console.log(customInstanceOf(dog, Dog));     // true
console.log(customInstanceOf(dog, Animal));  // true
console.log(customInstanceOf(dog, Array));   // false