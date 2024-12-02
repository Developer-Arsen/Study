
const hasNestedProperty = (obj, property) => {
    if (typeof obj != 'object' || !property) { return false; }
    let properties = property.split('.');

    for (let i = 0; i < properties.length; ++i) {
        if (!(properties[i] in obj)) {
            return false;
        }
        obj = obj[properties[i]];
    }

    return true;
}

const user = { name: "Alice", address: { city: "Wonderland", zip: "12345" } };
console.log(hasNestedProperty(user, "name")); // true
console.log(hasNestedProperty(user, "address.city")); // true
console.log(hasNestedProperty(user, "address.state")); // false