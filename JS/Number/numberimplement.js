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
        if (type === 'bigint' || type === 'symbol') { return TypeError(`Can not convert ${type} to number`); }
        if (type === 'undefined') { return NaN; }
        if (arg === null || arg === false) { return +0; }
        if (arg === true) { return 1; }
        if (type === 'string') { return EcmaScript.StringToNumber(arg) }
        if (type === 'object') {
            let primitive = EcmaScript.ToPrimitive(arg, 'NUMBER');
            EcmaScript.ToNumber(primitive);
        }
    }
    
    static StringToNumber(arg) {
       let text = EcmaScript.StringToCodePoints(arg);
       let literal = EcmaScript.ParseText(text, 'StringNumericLiteral');

       if (Array.isArray(literal) && literal.length > 0) {
           return NaN;
       }
   
       return literal.value;
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
    
        function parseNumber() {
            let token = text[index];
            if (token === undefined) return null;
    
            let numStr = '';
            while (index < text.length && /[0-9.-]/.test(String.fromCodePoint(text[index]))) {
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
    
}

console.log(Number('5n'), MyNumber('5asdn'));
