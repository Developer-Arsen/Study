const countFractionOnes = (number) => {
    if (typeof number != 'string' && !number.length) { return 0;}
    return number.slice(12).split('').filter(bit => bit == 1).length;;
}

console.log(countFractionOnes("1100000000011010000000000000000000000000000000000000000000000000"));
console.log(countFractionOnes("0011111110111001100110011001100110011001100110011001100110011010"));