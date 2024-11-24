import { _64_BIT_BIAS } from "./constants/index.js";
import { signOperatorExist, removeSign, detectSignBit, decimalToBinaryAsString, floatingToBinary, floatingToBinaryAsString, getExpFromNumber } from "./Utils/index.js";

const encode = (number) => {
    const number_as_string = number.toString();

    const sign_bit = detectSignBit(number_as_string);
    const float = number_as_string.split('.')[1] ? '0.' + number_as_string.split('.')[1] : 0;

    let integer = number_as_string.split('.')[0] ?? null;
    if (signOperatorExist(number_as_string)) {
        integer = removeSign(integer);
    }
    let integer_binary = decimalToBinaryAsString(Number.parseInt(integer)) ?? [];
    let floating_binary = !!float ? floatingToBinaryAsString(float) : [];
    let exp = getExpFromNumber(integer_binary, floating_binary);
    
    let integer_binary_array = integer_binary.split('');
    let float_binary_array = floating_binary && floating_binary.length ? floating_binary.split(''): []; 


    for (let i = 0; i < exp - 1; ++i) {
        if (exp) {
            const elem = integer_binary_array.pop();
            float_binary_array.unshift(elem);
        } else {
            const elem = float_binary_array.shift();
            integer_binary_array.push(elem);
        }
    }

    const mantissa = [...integer_binary_array, ...float_binary_array];
    const exponent = decimalToBinaryAsString(exp + _64_BIT_BIAS);
    const fraction = mantissa.splice(1).join('');


    console.log(`input is ${number} : res : `, [sign_bit, exponent, fraction].join(' | '));
};


// Test the function with 20 different inputs
const testValues = [
    42,            // Positive integer
    -42,           // Negative integer
    3.14,          // Positive decimal
    -3.14,         // Negative decimal
    0,             // Zero
    -0,            // Negative zero
    123456,        // Large positive integer
    -123456,       // Large negative integer
    0.999,         // Small positive decimal
    -0.999,        // Small negative decimal
    1.5,           // Simple positive decimal
    -1.5,          // Simple negative decimal
    1000000,       // Very large positive integer
    -1000000,      // Very large negative integer
    0.12345,       // Fractional only positive
    -0.12345,      // Fractional only negative
    9876543210,    // Large number
    -9876543210,   // Large negative number
    "123",         // Positive integer as a string
    "-123.45",     // Negative decimal as a string
];

testValues.forEach((value) => encode(value));
