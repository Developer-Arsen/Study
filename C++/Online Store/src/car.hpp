#ifndef CAR_H
#define CAR_H
#include <iostream>

#include "./product.hpp"
#include "./roles.hpp"

class Car : public Product
{
public:
    Car() = delete;
    Car(double price, double discount, const std::string &name)
    {
        m_price = price;
        m_discount = discount;
        m_name = name;
    }
    void displayName() const override
    {
        Product::displayName();
        std::cout << "barlus es car nem price:" << m_price << "$" << std::endl;
    }

   void applyDiscount(const ROLES role) override {
        if (role == MIDDLE) changeDiscount(10);
        if (role == SENIOR) changeDiscount(50);
    }
};

#endif