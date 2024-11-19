
function mapToBoolean(arr) {
    // return  arr.map((item) => !!item);
    return  arr.map((item) => Boolean(item));
}

console.log(mapToBoolean([0, "hello", "", NaN, 42, {}, []]));
// Output: [false, true, false, false, true, true, true]
