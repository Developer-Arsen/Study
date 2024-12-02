const evaluateTruthiness = (values) => {
    let obj = {
        truthy: [],
        falsy: [],
    } 
    values.forEach(element => {
        if (element) { 
            obj['truthy'].push(element); 
        }
        else {
            obj['falsy'].push(element);
        }
    });
    return obj;
}


console.log(evaluateTruthiness([0, 1, "", "hello", null, undefined, false, true, [], {}]));
// Output: { truthy: [1, "hello", true, [], {}], falsy: [0, "", null, undefined, false] }