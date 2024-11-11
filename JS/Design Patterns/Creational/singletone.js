var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var __classPrivateFieldSet = (this && this.__classPrivateFieldSet) || function (receiver, state, value, kind, f) {
    if (kind === "m") throw new TypeError("Private method is not writable");
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a setter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot write private member to an object whose class did not declare it");
    return (kind === "a" ? f.call(receiver, value) : f ? f.value = value : state.set(receiver, value)), value;
};
var _a, _SingleTon__instance;
var SingleTon = /** @class */ (function () {
    function SingleTon() {
    }
    Object.defineProperty(SingleTon, "instance", {
        get: function () {
            if (__classPrivateFieldGet(_a, _a, "f", _SingleTon__instance)) {
                __classPrivateFieldSet(_a, _a, new _a, "f", _SingleTon__instance);
            }
            return __classPrivateFieldGet(_a, _a, "f", _SingleTon__instance);
        },
        enumerable: false,
        configurable: true
    });
    SingleTon.prototype.someBussinessLogic = function () {
        console.log("logic");
    };
    return SingleTon;
}());
_a = SingleTon;
_SingleTon__instance = { value: void 0 };
var a = SingleTon.instance;
console.log(a);
// a.someBussinessLogic(); // Output: 'logic'
