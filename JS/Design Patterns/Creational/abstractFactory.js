var ModernChair = /** @class */ (function () {
    function ModernChair() {
    }
    ModernChair.prototype.sit = function () {
        console.log(" I am siting on modern chair");
    };
    return ModernChair;
}());
var ArtChair = /** @class */ (function () {
    function ArtChair() {
    }
    ArtChair.prototype.sit = function () {
        console.log(" I am siting on art chair");
    };
    return ArtChair;
}());
var ModernTable = /** @class */ (function () {
    function ModernTable() {
    }
    ModernTable.prototype.draw = function () {
        console.log("I am drawing in modern table ");
    };
    return ModernTable;
}());
var ArtTable = /** @class */ (function () {
    function ArtTable() {
    }
    ArtTable.prototype.draw = function () {
        console.log("I am drawing in art table ");
    };
    return ArtTable;
}());
var ModernFactory = /** @class */ (function () {
    function ModernFactory() {
    }
    ModernFactory.prototype.createChair = function () {
        return new ModernChair();
    };
    ModernFactory.prototype.createTable = function () {
        return new ModernTable();
    };
    return ModernFactory;
}());
var ArtFactory = /** @class */ (function () {
    function ArtFactory() {
    }
    ArtFactory.prototype.createChair = function () {
        return new ArtChair();
    };
    ArtFactory.prototype.createTable = function () {
        return new ArtTable();
    };
    return ArtFactory;
}());
new ArtFactory().createChair().sit();
new ModernFactory().createChair().sit();
