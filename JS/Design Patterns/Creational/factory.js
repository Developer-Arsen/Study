var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var Truck = /** @class */ (function () {
    function Truck() {
    }
    Truck.prototype.deliver = function () {
        console.log("truck is delivering");
    };
    return Truck;
}());
var Ship = /** @class */ (function () {
    function Ship() {
    }
    Ship.prototype.deliver = function () {
        console.log("ship is delivering");
    };
    return Ship;
}());
var Logistic = /** @class */ (function () {
    function Logistic() {
    }
    Logistic.prototype.makeDelivery = function () {
        var transport = this.factoryMethod();
        transport.deliver();
    };
    return Logistic;
}());
var RoadLogistic = /** @class */ (function (_super) {
    __extends(RoadLogistic, _super);
    function RoadLogistic() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    RoadLogistic.prototype.factoryMethod = function () {
        return new Truck();
    };
    return RoadLogistic;
}(Logistic));
var SeaLogistics = /** @class */ (function (_super) {
    __extends(SeaLogistics, _super);
    function SeaLogistics() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    SeaLogistics.prototype.factoryMethod = function () {
        return new Ship();
    };
    return SeaLogistics;
}(Logistic));
function clientCode(logistic) {
    logistic.makeDelivery();
}
clientCode(new SeaLogistics());
clientCode(new RoadLogistic());
