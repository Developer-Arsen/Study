function checkPrototypeChain(obj) {
    
    let count = 0;
    let proto = Object.getPrototypeOf(obj);

    while (proto) {
        count++;
        proto = Object.getPrototypeOf(proto);
    }
    return count;
}

class A {};
class B extends A {};
class C extends B {};
// console.log(checkPrototypeChain(new C()));


function analyzeSparseArray(arr) {
    let undefinedCount = 0;    
    let nullCount = 0;    
    let sparseCount = 0;    

    let tmp = {
        nullCount,
        undefinedCount,
        sparseCount,
    }

    for (let i = 0 ; i < arr.length; ++i) {
        if (Array.isArray(arr[i])) {
            const { nullCount, undefinedCount, sparseCount} = analyzeSparseArray(arr[i]);
            tmp.nullCount += nullCount;
            tmp.undefinedCount += undefinedCount;
            tmp.sparseCount += sparseCount;
        }

        if (!(i in arr)) {
            tmp.sparseCount++;
        }
        if (arr[i] === null ){
            tmp.nullCount++;
        }
        if (i in arr && arr[i] === undefined) {
            tmp.undefinedCount++;
        }
    } 
    
    return tmp;
}

console.log(analyzeSparseArray([1,2,,3, undefined, null, [,,,]]));
 

function testJSONSerialization(obj) {
    let keys = Object.keys(obj);
    keys.forEach(key => {
        if (key in obj && obj[key] === undefined) {
            obj[key] = null;
        }
        if (obj[key] && !Array.isArray(obj) && typeof obj[key] == 'object') {
            testJSONSerialization(obj[key]);
        }
    });
    return JSON.stringify(obj);
}



// console.log(testJSONSerialization({
//     a: 1,
//     b: undefined,
//     c: null,
//     d: {
//         a: 1,
//         b: undefined,
//         c: null
//     }
// }));

function deepDiffChecker(obj1, obj2, path = "") {
    const differences = [];

    const keys = new Set([...Object.keys(obj1 || {}), ...Object.keys(obj2 || {})]);

    for (const key of keys) {
        const newPath = path ? `${path}.${key}` : key;
        const value1 = obj1?.[key];
        const value2 = obj2?.[key];

        if (!(key in obj1)) {
            differences.push(`missing in obj1 : ${newPath}`)
        } else if (!(key in obj2)) {
            differences.push(`missing in obj2 : ${newPath}`)
        } else if (value1 === null && value2 === undefined || value1 === undefined && value2 === null) {
            differences.push(`null vs undefined ${newPath}`)
        } else if (value1 && value2 && typeof value1 === 'object' && typeof value2 === 'object') {
            differences.push(...deepDiffChecker(value1, value2, newPath));
        } else if ( value1 !== value2) {
            differences.push(`Mismatch at ${newPath} : obj1:${value1}  obj2:${value2}`)
        }
    }

    return differences;
}

const obj1 = {
    a: null,
    b: 2,
    c: { d: 4, e: null },
    f: 6,
};

const obj2 = {
    a: undefined,
    b: 2,
    c: { d: 5, e: undefined },
    g: 7,
};

console.log(deepDiffChecker(obj1, obj2));

class Node  {
    constructor (val) {
        this.value = val;
        this.next = null;
    }
}

class LinkedList {
    constructor () {
       this.head = null;
       this.tail = null;
       this.length = 0;
    }

    append(val) {
        const node = new Node(val);
        if (!this.head) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.length++;
    }

    prepand(val) {
        const node = new Node(val);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            node.next = this.head;
            this.head = node;

        }
        this.length++;
    }

    remove(val) {
        if (!this.head) return;

        if (this.head.value === val) {
            this.head = this.head.next;
            this.length--;
            if (this.length === 0) {
                this.tail = null;
            }
            return;
        }

        let current = this.head;
        while (current.next && current.next.value !== val) {
            current = current.next;
        }

        if (current.next) {
            current.next = current.next.next;
            this.length--;
            if (!current.next) {
                this.tail = current;
            }
        }
    }

    search(val) {
        let current = this.head;
        let index = 0;

        while (current) {
            if (current.val === val) {
                return index;
            }

            current = current.next;
            index++;
        }
        
        return index;
    }

    insert(val, index) {
        if (index < 0 || index > this.length) {
            throw new Error("Index out of bounds");
        }

        const newNode = new Node(val);

        if (index === 0) {
            this.prepand(val);
            return;
        }

        if (index === this.length) {
            this.append(val);
            return;
        }

        let current = this.head;
        let previous = null;
        let currentIndex = 0;

        while (currentIndex < index) {
            previous = current;
            current = current.next;
            currentIndex++;
        }

        previous.next = newNode;
        newNode.next = current;
        this.length++;
    }

    reverse() {
        let prev = null;
        let current = this.head;
        let next = null;

        this.tail = this.head;

        while (current) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        this.head = prev;
    }

    size() {
        return this.length;
    }

    toString() {
        let result = [];
        let current = this.head;

        while (current) {
            result.push(current.value);
            current = current.next;
        }

        return result.join(" -> ");
    }
}


// const list = new LinkedList();
// list.append(1);
// list.append(2);
// list.append(3);
// list.prepand(0);
// list.remove(2);
// list.reverse();
// console.log(list.toString()); 
// console.log("Size:", list.size()); 
// console.log("Search 1:", list.search(1));