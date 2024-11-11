#include <iostream>
#include <memory>

class Coffee {
    public:
        virtual std::string getDescription() const = 0;
        virtual double getCost() const = 0;
        virtual ~Coffee(){};
};

class BasicCoffee: public Coffee {
    public:
    std::string getDescription() const override {
        return "Basic Coffee";
    }

    double getCost() const override {
        return 2.0;  // Basic coffee cost
    }
};

class CoffeeDecorator : public Coffee {
    protected:
    std::shared_ptr<Coffee> coffee_;
    public:
        CoffeeDecorator(std::shared_ptr<Coffee> cof) : coffee_(std::move(cof)){}

        std::string getDescription() const override {
            return coffee_->getDescription();
        }

        double getCost() const override {
            return coffee_->getCost();
        }
};

class MilkDecorator : public CoffeeDecorator {
    public:
        MilkDecorator(std::shared_ptr<Coffee> cof) : CoffeeDecorator(std::move(cof)) {}

        std::string getDescription() const override {
            return coffee_->getDescription() + ", Milk";
        }

        double getCost() const override {
            return coffee_->getCost() + 0.5;
        }
};

    
class SugarDecorator : public CoffeeDecorator {
    public:
        SugarDecorator(std::shared_ptr<Coffee> cof) : CoffeeDecorator(std::move(cof)) {}

        std::string getDescription() const override {
            return coffee_->getDescription() + ", Sugar";
        }

        double getCost() const override {
            return coffee_->getCost() + 0.3;
        }       
};

int main () {
    std::shared_ptr<Coffee> coffee = std::make_shared<BasicCoffee>();
    std::cout << coffee->getDescription() << " - $" << coffee->getCost() << std::endl;

    coffee = std::make_shared<SugarDecorator>(coffee);
    std::cout << coffee->getDescription() << " - $" << coffee->getCost() << std::endl;
    
    coffee = std::make_shared<MilkDecorator>(coffee);
    std::cout << coffee->getDescription() << " - $" << coffee->getCost() << std::endl;
    
}
