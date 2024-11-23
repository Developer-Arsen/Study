export const decimalToBinary = (number, aggr) => {
    if (number === 0 && aggr === '') return '0'; 
    if (number === 0) return aggr;
    
    aggr = (number % 2) + aggr; 
    return decimalToBinary(Math.floor(number / 2), aggr);
}

export const decimalToBinaryAsString = (number) => {
    return decimalToBinary(number, '');
}

export const floatingToBinary = (number, aggr) => {
    if (number === 0) return aggr;

    const integer = Math.floor(number);
    aggr += integer;

    let fractionalPart = number - integer;

    if (fractionalPart > 0) {
        return floatingToBinary(fractionalPart * 2, aggr);
    }

    return aggr;
}

export const floatingToBinaryAsString = (number) => {
    if (number === 0) return '';
    return floatingToBinary(number, '').split('').splice(1).join('');
}

export const getExpFromNumber = (integer, float) => {    
    if (integer) {
        if (integer.length > 1) { return integer.length - 1; } 
        return 1;
    } else {
        const index = float.split('').findIndex((element) => {
            return Number.parseInt(element);
        });
        return -1 * index;
    }
}

export const binaryToDecimal = (numberAsString) => {
    let sum = 0;
    for (let i = 0 ; i < numberAsString.length; ++i) {
        if (numberAsString[numberAsString.length - 1 - i] === '1') {
            sum += Math.pow(2, i);
        }
    }
    return sum;
}

export const signOperatorExist = (number) => {
    return Number.isNaN(Number.parseInt(number[0]));
};

export const detectSignBit = (number) => {
    if (number[0] == '-') {
        return 1;
    } else {
        return 0;
    }
};

export const removeSign = (number) => {
    return number.split('').splice(1).join('');
};