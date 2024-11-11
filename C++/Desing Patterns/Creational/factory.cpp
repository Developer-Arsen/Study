#include <iostream>

class Transport {
    public:
        virtual ~Transport(){};
        virtual void deliver() const = 0;
};

class Truck : public Transport {
    public:
        void deliver() const override {
            std::cout << "truck is delivering" << std::endl;
        }
};

class Ship : public Transport {
    public:
        void deliver() const override {
            std::cout << "Ship is delivering" << std::endl;
        }
};

class Logistic {
    public:
        virtual ~Logistic(){}
        virtual Transport*  FactoryMehtod() const = 0;

        void makeDelivery() const {
            Transport * transp = this->FactoryMehtod();
            transp->deliver();
            delete transp;
        }
};

class SeaLogistic : public Logistic {
    public:
        Transport* FactoryMehtod() const override {
            return new Ship();
        }
};

class RoadLogistic : public Logistic {
    public:
        Transport* FactoryMehtod() const override {
            return new Truck();
        }
};

int main()
{
    Logistic* lod = new RoadLogistic();
    lod->makeDelivery();
    delete lod;
    lod = new SeaLogistic();
    lod ->makeDelivery();
    

    return 0;
}