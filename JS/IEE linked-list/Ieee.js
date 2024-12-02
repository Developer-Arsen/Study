class Node {
    constructor(bit) {
      this.bit = bit; 
      this.next = null;
    }
}

class Utils {
    constructor(){};
    
    static isDotExist(number) {
        return number.toString().includes('.');
    }

    static decimalToBinary (number, aggr) {
        if (number === 0 && aggr === '') return '0'; 
        if (number === 0) return aggr;
        
        aggr = (number % 2) + aggr; 
        return Utils.decimalToBinary(Math.floor(number / 2), aggr);
    }
    
    static decimalToBinaryAsString (number) {
        return Utils.decimalToBinary(number, '');
    }
    
    static floatingToBinary (number, aggr) {
        if (number === 0) return aggr;
    
        const integer = Math.floor(number);
        aggr += integer;
    
        let fractionalPart = number - integer;
    
        if (fractionalPart > 0) {
            return Utils.floatingToBinary(fractionalPart * 2, aggr);
        }
    
        return aggr;
    }
    
    static floatingToBinaryAsString (number) {
        if (number === 0) return '';
        return Utils.floatingToBinary(number, '').split('').splice(1).join('');
    }
    
    static getExpFromNumber (integer, float) {    
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
    
    static binaryToDecimal (numberAsString) {
        let sum = 0;
        for (let i = 0 ; i < numberAsString.length; ++i) {
            if (numberAsString[numberAsString.length - 1 - i] === '1') {
                sum += Math.pow(2, i);
            }
        }
        return sum;
    }
    
    static signOperatorExist (number) {
        return Number.isNaN(Number.parseInt(number[0]));
    };
    
    static detectSignBit (number) {
        if (number[0] == '-') {
            return 1;
        } else {
            return 0;
        }
    };
    
    static removeSign (number) {
        return number.split('').splice(1).join('');
    };

    static edgeCases (sign_bit, exponent, fraction) {
        if (Utils.allOnes(exponent)) {
            if (!Utils.allZeros(fraction)) {
                return NaN;
            }
            return sign_bit == 1 ? -Infinity : Infinity;
        } else if (Utils.allZeros(fraction)) {
            return sign_bit == 1 ? -Infinity : Infinity;
        }
    }

    static allOnes (number) {
        return number.split('').every(elem => elem == 1);
    }
    
    static allZeros (number) {
        return number.split('').every(elem => elem == 0);
    }

    static fullAdder(A, B, Cin) {
        const sum = A ^ B ^ Cin;
        
        const Cout = (A & B) | (Cin & (A ^ B));
        
        return { sum, Cout };
    }

    static addTwoBinaryStrings(bin1, bin2) {
        let result = "";
        let carry = 0;
        const maxLength = Math.max(bin1.length, bin2.length);
        bin1 = bin1.padStart(maxLength, '0');
        bin2 = bin2.padStart(maxLength, '0');
    
        for (let i = maxLength - 1; i >= 0; i--) {
            const bit1 = parseInt(bin1[i], 10);
            const bit2 = parseInt(bin2[i], 10);
            const { sum, Cout } = Utils.fullAdder(bit1, bit2, carry);
            result = sum + result;
            carry = Cout;
        }
    
        if (carry) {
            result = carry + result;
        }
        return result;
    }

    static incrementExponent(exp) {
        let carry = 1; 
        let result = '';
        
        for (let i = exp.length - 1; i >= 0; i--) {
            const sum = (exp[i] === '1' ? 1 : 0) + carry;
            result = (sum % 2 === 1 ? '1' : '0') + result;
            carry = Math.floor(sum / 2);
        }
        
        return result;
    }
}
  
class LinkedList {
    static _64_BIT_BIAS = 1023;

    constructor() {
      this.head = null;
      this.tail = null;
    }

    /**
     * Converts a double number to a 64-bit binary linked list.
     * @param {number} number - The double-precision floating-point number.
     * @returns {LinkedList} - A linked list representing the 64-bit binary number.
     */
    static fromDouble(number) {
        const number_as_string = number.toString();

        const sign_bit = Utils.detectSignBit(number_as_string);
        const float = number_as_string.split('.')[1] ? '0.' + number_as_string.split('.')[1] : 0;
    
        let integer = number_as_string.split('.')[0] ?? null;
        if (Utils.signOperatorExist(number_as_string)) {
            integer = Utils.removeSign(integer);
        }
        
        let integer_binary = Utils.decimalToBinaryAsString(Number.parseInt(integer)) ?? [];
        let floating_binary = !!float ? Utils.floatingToBinaryAsString(float) : [];
        let exp = Utils.getExpFromNumber(integer_binary, floating_binary);
        
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
        const exponent = Utils.decimalToBinaryAsString(exp + LinkedList._64_BIT_BIAS);
        let fraction = mantissa.splice(1).join('');
    
        if (fraction.length < 52) {
            fraction = fraction.padEnd(52, 0);
        } else if(fraction.length > 52) {
            fraction = fraction.slice(0,52);
        }
        
        const finalArr = [sign_bit, ...exponent, ...fraction];

        let list = new LinkedList();
        finalArr.forEach((bit, index) => {
            if (index != 64) {
                list.append(bit)
            }
        });
        return list;
    }
  
    /**
     * Converts the binary linked list back to a double-precision floating-point number.
     * @returns {number} - The double-precision number.
     */
    toDouble() {
        let binaryString = this.makeString();
        const sign_bit = binaryString[0];
        const exponent = binaryString.slice(1, 12);
        const fraction = binaryString.slice(12);
    
        if (Utils.edgeCases(sign_bit, exponent, fraction) !== undefined) {
            return Utils.edgeCases(sign_bit, exponent, fraction);
        } 
    
        const exponent_decimal = Utils.binaryToDecimal(exponent);
        const actual_exponent = exponent_decimal - LinkedList._64_BIT_BIAS;
    
        let mantissa = 1;
        for (let i = 0; i < fraction.length; i++) {
            mantissa += parseInt(fraction[i]) * Math.pow(2, -(i + 1));
        }
    
        const sign = sign_bit === '1' ? -1 : 1;
        const result = sign * mantissa * Math.pow(2, actual_exponent);
        
        return result;
    }
  
    /**
     * Adds two linked lists representing 64-bit binary numbers.
     * @param {LinkedList} listA - The first linked list.
     * @param {LinkedList} listB - The second linked list.
     * @returns {LinkedList} - A new linked list representing the sum.
     */
    static add(listA, listB) {
        let numberStringA = listA.makeString();
        let fractionA = numberStringA.slice(12);
        let expA = numberStringA.slice(1, 12);
        let signBitA = numberStringA.slice(0, 1);
        
        let numberStringB = listB.makeString();
        let fractionB = numberStringB.slice(12);
        let expB = numberStringB.slice(1, 12);
        let signBitB = numberStringB.slice(0, 1);
        
        if (expA === expB) {
            let newFraction = Utils.addTwoBinaryStrings(fractionA, fractionB);
            
            let carry = newFraction.length > 52 ? 1 : 0;
            if (carry) {
                newFraction = newFraction.slice(1); 
                expA = Utils.incrementExponent(expA); 
            }
        
            let list = new LinkedList();
            let merge = [signBitA, ...expA.split(''), ...newFraction.split('')];
            merge.forEach((bit) => list.append(bit));
            return list;
        } else {
            const a = listA.toDouble();
            const b = listB.toDouble();
            return LinkedList.fromDouble(a + b);
        }
    }

    clear () {
        this.head = null;
        this.tail = null;
    }

    append(bit) {
        let tmp = new Node(bit);
        
        if (this.head) {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }

            current.next = tmp;
            this.tail = tmp;
        } else {
            this.head = tmp;
            this.tail = tmp;
        }
    }

    makeString() {
        let arr = [];
        let current = this.head;
        while (current) {
          arr.push(current.bit);
          current = current.next;
        }
        return arr.join('');
    }
  
    /**
     * Converts the linked list to a binary string.
     * @returns {string} - The binary representation of the linked list.
     */
    toBinaryString() {
      let arr = [];
      let current = this.head;
      while (current) {
        arr.push(current.bit);
        current = current.next;
      }
      return arr.join(' -> ');
    }
}
  
  
  const listA = LinkedList.fromDouble(3.14);
  const listB = LinkedList.fromDouble(2.71);
  const result = LinkedList.add(listA, listB);
  
//   console.log("List A (Binary):", listA.toBinaryString());
//   console.log("List B (Binary):", listB.toBinaryString());
//   console.log("Result (Binary):", result.toBinaryString());
  
  const resultDouble = result.toDouble();
  console.log("Result (Double):", resultDouble);
  

