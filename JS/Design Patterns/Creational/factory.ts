interface Transport {
    deliver : () => void;
}

class Truck implements Transport {
    public deliver() : void {
        console.log("truck is delivering");
    }
}

class Ship implements Transport {
    public deliver () : void {
        console.log("ship is delivering");
    }
}

abstract class Logistic {
    public abstract factoryMethod() : Transport;

    public makeDelivery() : void {
        const transport = this.factoryMethod();
        transport.deliver();
    }
}

class RoadLogistic extends Logistic {
    public factoryMethod(): Transport {
        return new Truck();
    }
}

class SeaLogistics extends Logistic {
    public factoryMethod(): Transport {
        return new Ship();
    }
}


function clientCode(logistic : Logistic) {
    logistic.makeDelivery();
}

clientCode(new SeaLogistics())
clientCode(new RoadLogistic())