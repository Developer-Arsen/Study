class SingleTon {
    static #_instance : SingleTon;
    private constructor(){}

    public static get instance() : SingleTon {
        if (SingleTon.#_instance) {
            SingleTon.#_instance = new SingleTon;
        }
        return SingleTon.#_instance;
    }

    public someBussinessLogic() {
        console.log("logic");
    }
}


let a = SingleTon.instance;
console.log(a)
// a.someBussinessLogic(); // Output: 'logic'
