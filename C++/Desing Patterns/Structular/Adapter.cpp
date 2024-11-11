#include <iostream>

class IPaymentSystem {
    public:
        virtual ~IPaymentSystem(){}
        virtual void pay() const = 0;
        virtual void minus() const = 0;
};


class DebitCard : public IPaymentSystem {
    public:
        void pay()  const {
            std::cout << "Debit card payment" << std::endl;
        }

        void minus ()  const {
            std::cout << "minus from balance" << std::endl;
        }
};

class CreditCard : public IPaymentSystem {
    public:
        void pay() const {
            std::cout << "CreditCard card payment" << std::endl;
        }

        void minus ()  const {
            std::cout << "minus from balance" << std::endl;
        }
};

class IOnlinePayment {
    public:
        virtual ~IOnlinePayment(){}
        virtual void cashout() = 0;
};

class PayPal : public IOnlinePayment {
    public:
        void cashout() {
            std::cout << "paypal cashout" << std::endl;
        }
};

class SystemPaymentAdapter : public IPaymentSystem {
    IOnlinePayment& onlinePaymentAdapter_;

    public:
        SystemPaymentAdapter(IOnlinePayment &adapter) : onlinePaymentAdapter_(adapter) {}
        
    void pay() const {
        std::cout << "payment of systempayment adapter" << std::endl;
        onlinePaymentAdapter_.cashout();
        this->minus();
    }

    void minus ()  const {
        std::cout << "minus from balance" << std::endl;
    }
};

int main () {

}