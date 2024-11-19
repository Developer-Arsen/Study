function filterFalsyValues(arr) {
    if (!Array.isArray(arr)) { return [] };

    return arr.filter((item) => !!item);
}

console.log(filterFalsyValues([0, 1, "", "hello", null, undefined, false, 42]));
// Output: [1, "hello", 42]
