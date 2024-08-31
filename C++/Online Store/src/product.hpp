#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

#include "./roles.hpp"

class Product
{
protected:
    size_t m_id;
    double m_price;
    double m_discount;
    std::string m_name;

    void changeDiscount(double discount) {
        m_discount = discount;
    }

public:
    virtual void displayName() const = 0;
    virtual void applyDiscount(const ROLES) = 0;


    void setId(size_t id)
    {
        m_id = id;
    }

    static bool checkCanBeDiscounted(const ROLES role)
    {
        if (role == JUNIOR)
            return false;
        return true;
    }
};

void Product::displayName() const
{
    std::cout <<"Your Discount % is:" << m_discount << "  " << "id:" << m_id << " ";
}

#endif