function findNested(obj, keys) {
    let tmp = {};
    let str = '';
    for (let i = 0; i < keys.length; ++i) {
        str += `${keys[i]}`

        if (obj[keys[i]]) {
            tmp[str] = true;
            str += ".";
            obj = obj[keys[i]];
        } else {
            tmp[str] = false;
        }
    }

    return tmp;
}

function hasProperties(data, arr) {
    let obj = {};
    if (!obj || !arr || !Array.isArray(arr) || !arr.length) { return obj; }

    for (let i = 0 ; i < arr.length; ++i) {
        let searchKey = arr[i];
        if (searchKey.includes(".")) {
            obj = {...obj, ...findNested(data, searchKey.split(".")) } ;
        } else {
            if (data[searchKey] !== undefined) {
                obj[searchKey] = true;
            }
        }
    }
   
    return obj;
}

const user = { name: "Alice", address: { city: "Wonderland" } };
console.log(hasProperties(user, ["name", "address.city", "address.zip"]));
// Output: { name: true, "address.city": true, "address.zip": false }
