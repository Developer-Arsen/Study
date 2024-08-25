#ifndef LAPTOP_H
#define LAPTOP_H
#include <iostream>

#include "./product.hpp"
#include "./roles.hpp"

class Laptop : public Product
{
public:
    Laptop() = delete;
    Laptop(double price, double discount, const std::string &name)
    {
        m_price = price;
        m_discount = discount;
        m_name = name;
    }
    void displayName() const override {
        Product::displayName();
        std::cout << "barlus es laptopt nem price:" << m_price << "$" << std::endl;
    }

    void applyDiscount(const ROLES role) override {
        if (role == MIDDLE) changeDiscount(10);
        if (role == SENIOR) changeDiscount(50);
    }
};

#endif