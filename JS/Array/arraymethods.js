

class MyArray {
    #arr = [];

    constructor(arr = []) {
        if (arr && !Array.isArray(arr)) {
            throw new Error("You must specify array");
        }

        this.fill(arr);
    }

    validFunction(fn) {
        if (typeof fn === "function") return true;
    }

    fill(arr) {
        for (let i = 0; i < arr.length; ++i) {
            this.#arr[i] = arr[i];
        }
    }

    push(val) {
        this.#arr[this.#arr.length] = val;
        return this.#arr.length;
    }

    pop() {
        if (this.#arr.length) {
            return this.#arr[this.#arr.length - 2];
        }
    }

    shift() {
        for (let i = 0; i < this.#arr.length - 1; ++i) {
            let tmp = this.#arr[i];
            this.#arr[i] = this.#arr[i + 1];
            this.#arr[i + 1] = tmp;
        }
        this.#arr.length--;

        return this.#arr.length;
    }

    unshift(...args) {
        let step = args.length;

        if (step) {
            for (let i = this.#arr.length + step - 1; i > step - 1; --i) {
                this.#arr[i] = this.#arr[i - step];
            }

            for (let i = 0; i < step; i++) {
                this.#arr[i] = args[i];
            }
        }

        return this.#arr.length;
    }

    concat(...args) {
        for (let i = 0; i < args.length; ++i) {
            if (Array.isArray(args[i])) {
                for (let j = 0; j < args[i].length; ++j) {
                    this.#arr[this.#arr.length] = args[i][j];
                }
            }
        }
        return this.#arr.length;
    }

    join() {
        let str = "";

        for (let i = 0 ; i < this.#arr.length; ++i) {
            str += this.#arr[i];
        }

    }

    map(fn) {
        if (!this.validFunction(fn)) return false;

        let tmparr = [];

        for (let i = 0; i < this.#arr.length; ++i) {
            tmparr[i] = fn(this.#arr[i]);
        }

        return tmparr;
    }

    filter(fn) {
        if (!this.validFunction(fn)) return false;

        let tmparr = [];
        let index = 0;
        for (let i = 0; i < this.#arr.length; ++i) {
            if (fn(this.#arr[i])) {
                tmparr[index++] = this.#arr[i]
            }
        }

        return tmparr;
    }

    find(fn) {
        if (!this.validFunction(fn)) return false;

        for (let i = 0; i < this.#arr.length; ++i) {
            if (fn(this.#arr[i])) {
                return this.#arr[i];
            }
        }
    }

    reduce(fn, initval = 0) {
        if (!this.validFunction(fn)) return false;

        let aggr = initval;

        for (let i = 0; i < this.#arr.length; ++i) {
            aggr = fn(aggr, this.#arr[i])
        }

        return aggr;
    }

    some (fn) {
        if (!this.validFunction(fn)) return false;

        for (let i = 0; i < this.#arr.length; ++i) {
            if(fn(this.#arr[i])) return true;
        }

        return false;
    }

    every (fn) {
        if (!this.validFunction(fn)) return false;
    
        for (let i = 0; i < this.#arr.length; ++i) {
            if (!fn(this.#arr[i])) return false;
        }

        return true;
    }

    flat() {

    }

    indexOf(elem) {
        for (let i = 0; i < this.#arr.length; ++i) {
            if (this.#arr[i] == elem) return i;
        }

        return -1;
    }

    includes(elem) {
        for (let i = 0; i < this.#arr.length; ++i) {
            if (this.#arr[i] == elem) return true;
        }

        return false;
    }

    getArr() {
        return this.#arr;
    }

    printArr() {
        for (let i = 0; i < this.#arr.length; ++i) {
            console.log(this.#arr[i]);
        }

        return this.#arr.length;
    }
}

let x = new MyArray([1, 2, 3, 4]);
// x.shift();
// x.push(4);
// x.pop(4);
// x.unshift(5,6,7)
// x.concat([10,10,10],[20,20,20])


console.log(x.getArr())
// console.log(x.map((num) => num * 2))
// console.log(x.filter((num) => num == 2))
// console.log(x.find((num) => num % 2 == 0))
// console.log(x.reduce((accumulator, currentValue) => accumulator + currentValue, 0));
// console.log(x.every(num => num > 0));
// console.log(x.some(age => age > 5));
// console.log(x.indexOf(4));
console.log(x.includes(4));





