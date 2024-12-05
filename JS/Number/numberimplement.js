class SyntaxError {
    constructor(message, index) {
        this.message = message;
        this.index = index;
    }
}

class EcmaScript {
    static ToNumber(arg) {
        let type = typeof arg;
        if (type === 'number') { return arg; }
        if (type === 'bigint' || type === 'symbol') { throw new TypeError(`Can not convert ${type} to number`); }
        if (type === 'undefined') { return NaN; }
        if (arg === null || arg === false) { return +0; }
        if (arg === true) { return 1; }
        if (type === 'string') { return EcmaScript.StringToNumber(arg) }
        if (type === 'object') {
            let primitive = EcmaScript.ToPrimitive(arg, 'NUMBER');
            return EcmaScript.ToNumber(primitive);
        }
    }
    
    static StringToNumber(arg) {
        let text = EcmaScript.StringToCodePoints(arg);
        let literal = EcmaScript.ParseText(text, 'StringNumericLiteral');
        console.log(literal);
        
        if (Array.isArray(literal) && literal.length == 0) {
            return NaN;
        }

        return literal ? literal.value : NaN;
    }

    static StringToCodePoints(string) {
        let codePoints = [];
        let size = string.length;
        let position = 0;
    
        while (position < size) {
            let cp = string.codePointAt(position); 
            codePoints.push(cp);
            position += (cp >= 0x10000 ? 2 : 1);  
        }
    
        return codePoints;
    }

    static ParseText(text, goalSymbol) {
        let index = 0;
        console.log(text);
    
        function parseNumber() {
            let token = text[index];
            if (token === undefined) return null;
    
            let numStr = '';
            while (index < text.length ) {
                if (!/[0-9.-]/.test(String.fromCodePoint(text[index]))) {
                    return [];
                }
                
                numStr += String.fromCodePoint(text[index]);
                index++;
            }
    
            if (numStr === 'Infinity') {
                return { value: Infinity };
            }
            if (numStr === '-Infinity') {
                return { value: -Infinity };
            }
            if (numStr === 'NaN') {
                return { value: NaN };
            }
            
            let num = parseFloat(numStr);
            
            if (!isNaN(num)) {
                return { value: num };
            }
    
            return null; 
        }
    
        const result = parseNumber();
        
        return result ? result : [];  
    }
    

    static ToPrimitive(arg, type) {
        if (type === 'string') {
            return arg.toString();
        }
        return arg.valueOf();
    }
   
}


function MyNumber(arg) {
    if (!arguments.length) {
        return 0;
    }

    if (!new.target) {
        return EcmaScript.ToNumber(arg);
    }
    
    this.value = EcmaScript.ToNumber(arg);
 
}

MyNumber.parseFloat = (string) => {
    string = string.trim();

    let num = parseFloat(string);

    if (isNaN(num)) {
        return NaN;
    }

    return num;
}

MyNumber.parseInt = (string, radix) => {
    if (radix < 2 || radix > 36) {
        throw new RangeError("Radix must be between 2 and 36");
    }

    string = string.trim();
    let num = parseInt(string, radix);

    if (isNaN(num)) {
        return NaN;
    }

    return num;
}

new MyNumber();



console.log(MyNumber.parseInt('10'));         
console.log(MyNumber.parseInt('10', 2));      
console.log(MyNumber.parseInt('10', 16));     
console.log(MyNumber.parseInt('10abc'));      
console.log(MyNumber.parseInt('abc10'));      
console.log(MyNumber.parseInt('0x10', 16));   
console.log(MyNumber.parseInt('  123  '));    
console.log(MyNumber.parseInt('101010', 2));  
console.log(Number('5n'), MyNumber('5asdn'));
