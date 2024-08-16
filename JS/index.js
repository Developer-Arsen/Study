function test_factorial() {
    if (factorial(0) == 1 && factorial_rec(0) == 1) { console.log("0 succ"); } 
    else { console.log("0 fail"); }

    if (isNaN(factorial(null)) && isNaN(factorial_rec(null))) { console.log("null succ");} 
    else { console.log("null fail"); }

    if (isNaN(factorial(-1)) && isNaN(factorial_rec(-1))) { console.log(" -1 succ"); } 
    else { console.log("-1 fail"); }

    if (isNaN(factorial([])) && isNaN(factorial_rec("[]"))) { console.log("[] succ"); } 
    else { console.log("[] fail"); }

    if (isNaN(factorial("string")) && isNaN(factorial_rec("string"))) { console.log("string succ"); } 
    else { console.log("string fail"); }
}

function factorial(num) {
    if (typeof num != "number" || num < 0) {
        return NaN;
    }

    let sum = 1;
    for (let i = 2; i <= num; ++i) {
        sum *= i;
    }

    return sum;
}

function factorial_rec(num) {
    let sum = 1;
    if (typeof num != "number" || num < 0) {
        return NaN;
    }

    if (num == 0) return sum;
    sum = num * factorial_rec(num-1);

    return sum;
}


function test_sumEvenNumbers() {
    if (sumEvenNumbers(0) == 0) { console.log("0 succ"); }
    else { console.log("0 fail"); }

    if (sumEvenNumbers("str") == 0) { console.log("str succ"); }
    else { console.log("str fail"); }

    if (sumEvenNumbers(null) == 0) { console.log("null succ"); }
    else { console.log("null fail"); }

    if (sumEvenNumbers(NaN) == 0) { console.log("NaN succ"); }
    else { console.log("NaN fail"); }
}

function sumEvenNumbers(arr) {
    if (!Array.isArray(arr)) {
        return 0;
    }

    let sum = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}


function test_countVowels() {
    if (countVowels([]) == 0) { console.log("[] succ");}
    else { console.log("[] fail");}

    if (countVowels(2) == 0) { console.log("2 succ");}
    else { console.log("2 fail");}

    if (countVowels(null) == 0) { console.log("null succ");}
    else { console.log("null fail");}

    if (countVowels(NaN) == 0) { console.log("NaN succ");}
    else { console.log("NaN fail");}
}

function countVowels(str) {
    if (typeof str !== "string") {
        return 0;
    }
    
    const obj = {
        "A" : 1,
        "E" : 1,
        "O" : 1,
        "U" : 1,
        "I" : 1,
        "a" : 1, 
        "e" : 1,
        "o" : 1,
        "u" : 1,
        "i" : 1
    }
     
    let sum = 0;
    for (let char of str) {
        sum += char in obj;
    }

    return sum;
}


console.log(countVowels("hllo"));