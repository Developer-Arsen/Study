import { _64_BIT_BIAS } from "./constants/index.js";
import { binaryToDecimal } from "./Utils/index.js";

const edgeCases = (sign_bit, exponent, fraction) => {
    if (allOnes(exponent)) {
        
        if (!allZeros(fraction)) {
            return NaN;
        }
        return sign_bit == 1 ? -Infinity : Infinity;
    } else if (allZeros(fraction)) {
        return sign_bit == 1 ? -Infinity : Infinity;
    }
}

const allOnes = (number) => {
    return number.split('').every(elem => elem == 1);
}

const allZeros = (number) => {
    return number.split('').every(elem => elem == 0);
}

const decode = (binaryString) => {
    const sign_bit = binaryString[0];
    const exponent = binaryString.slice(1, 12);
    const fraction = binaryString.slice(12);

    if (edgeCases(sign_bit, exponent, fraction) !== undefined) {
        return console.log(edgeCases(sign_bit, exponent, fraction));
    } 

    const exponent_decimal = binaryToDecimal(exponent);
    const actual_exponent = exponent_decimal - _64_BIT_BIAS;

    let mantissa = 1;
    for (let i = 0; i < fraction.length; i++) {
        mantissa += parseInt(fraction[i]) * Math.pow(2, -(i + 1));
    }

    const sign = sign_bit === '1' ? -1 : 1;
    const result = sign * mantissa * Math.pow(2, actual_exponent);

    console.log(`Decoded value: ${result}`);
};


const encodedValues = [
    '01000000010001010',  // Positive Normalized Number (Integer) 42
    '11000000010001010',  // Negative Normalized Number (Integer) -42
    '0100000000001001001000011111101101010100010001000010110100011000',  // Positive Normalized Number (Decimal) 3.14
    '1100000000001001001000011111101101010100010001000010110100011000',  // Negative Normalized Number (Decimal) -3.14
    '0011111111101111010101101000100010001011101100010001001100000000',  // Positive Small Decimal 0.000123456
    '1011111111101111010101101000100010001011101100010001001100000000',  // Negative Small Decimal -0.000123456
    '0000000000000000000000000000000000000000000000000000000000000000',  // Positive Zero 0
    '1000000000000000000000000000000000000000000000000000000000000000',  // Negative Zero -0
    '0111111111100000000000000000000000000000000000000000000000000000',  // Positive Infinity
    '1111111111100000000000000000000000000000000000000000000000000000',  // Negative Infinity
    '0111111111111000000000000000000000000000000000000000000000000000',  // NaN
    '1100000011110000000000000000000000000000000000000000000000000000',  // Positive Normalized Number (Integer) 123456
    '1011110011110000000000000000000000000000000000000000000000000000',  // Negative Normalized Number (Decimal) -1.5
    '010000000000111111111101111100111101101100100010110100001110010011111',  // Positive Small Decimal 0.999
    '110000000000111111111101111100111101101100100010110100001110010011111',  // Negative Small Decimal -0.999
    '0100000011111110001001000000',  // Large Positive Integer 123456
    '1100000011111110001001000000',  // Large Negative Integer -123456
];

encodedValues.forEach((binaryString) => {
    decode(binaryString);
});
