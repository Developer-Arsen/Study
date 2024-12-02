const andOperator = (a,b) => {
    if (a) {
        if (b) {
            return b;
        } else {
            return a;
        }
    } 
    return a;
}

const orOpertaor = (a,b) => {
    if (a) { return a; }
    if (b) { return b; }
    return b;
}

const nullishOperator = (a,b) => {
    if (a == undefined || a == null) { return b; };
    return a;
}

let OPERATORS = {
    '&&': andOperator,
    '||': orOpertaor,
    '??': nullishOperator
}

const evaluateLogical = (a, b, op) => {
    return OPERATORS[op](a,b);
}


console.log(evaluateLogical(5, 10, '&&')); // 10
console.log(evaluateLogical(null, 'default', '??')); // "default"
console.log(evaluateLogical(false, 42, '||')); // 42