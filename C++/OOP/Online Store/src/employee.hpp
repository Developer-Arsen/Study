#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

#include "./cart.hpp"
#include "./roles.hpp"

class Employee
{
    Cart m_cart;
    ROLES m_role;

public:
    Employee() = delete;
    Employee(Cart &cart, ROLES role) : m_cart{cart}
    {
        m_role = role;
    }

    ROLES getRole() const
    {
        return m_role;
    }

    void showProduct() const
    {
        m_cart.displayProducts();
    }

    void makeDiscount()
    {
        m_cart.applyDiscount(getRole());
    }
};

#endif