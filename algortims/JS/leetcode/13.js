var romanToInt = function(s) {
    const arr = s.split('');
    let number = 0;
    const obj = {
        I: 1,
        IV: 4,
        V: 5,
        IX: 9,
        X: 10,
        XL:40,
        L: 50,
        XC: 90,
        C: 100,
        CD: 400,
        D: 500,
        CM: 900,
        M: 1000
    };
    for (let i = 0; i < arr.length; ++i) {
        if (obj[arr[i]] <  obj[arr[i + 1]]) {
            number += obj[arr[i] + arr[i + 1]];
            i++;
        } else {
            number += obj[arr[i]];
        }
    }
};

console.log(romanToInt("LVIII"));