#include <iostream>
#include <memory>


class IPaymentStrategy {
    public:
        virtual ~IPaymentStrategy(){}
        virtual void pay(int amount) const = 0;
};

class CreditCardPayment : public IPaymentStrategy {
    std::string name_;
    std::string number_;

    public:
        CreditCardPayment(const std::string& name, const std::string& number) : name_(name) , number_(number) {}

        void pay(int amount) const override {
            std::cout << "Paid " << amount << " using Credit Card. Card Holder: " << name_ << std::endl;
        }
};

class PayPalPayment : public IPaymentStrategy {
    std::string name_;
    std::string number_;

    public:
        PayPalPayment(const std::string& name, const std::string& number) : name_(name) , number_(number) {}

        void pay(int amount) const override {
            std::cout << "Paid " << amount << " using Pay Pal. Card Holder: " << name_ << std::endl;
        }
};

class Order {
    std::unique_ptr<IPaymentStrategy> strategy_;
    public:
        void setPaymentStrategy(std::unique_ptr< IPaymentStrategy> strategy) {
            strategy_ = std::move(strategy);
        }

        void processOrder(int amount) const {
            if (strategy_) {
                strategy_->pay(amount);
            } else {
                std::cout << "strategy is not set" << std::endl;
            }
        }
};

int main () {
    Order order;

    order.setPaymentStrategy(std::make_unique<PayPalPayment> ("Arsen", "4083"));
    order.processOrder(100);

    order.setPaymentStrategy(std::make_unique<CreditCardPayment> ("Arsen", "4083"));
    order.processOrder(900);

}

