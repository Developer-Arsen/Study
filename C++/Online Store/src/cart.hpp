#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>

#include "./product.hpp"
#include "./roles.hpp"

class Cart
{
private:
    size_t m_index{0};
    std::vector<Product *> m_products;
    bool isDiscounted{false};

public:
    Cart() = default;
    Cart(const std::vector<Product *> &products)
    {
        for (size_t i = 0; i < products.size(); i++)
        {
            m_index++;
            (products[i])->setId(m_index);
        }

        m_products = products;
    }
    Cart(const Cart &cart)
    {
        for (int i = 0; i < cart.m_products.size(); ++i)
        {

            m_products.push_back(cart.m_products[i]);
        }
    }

    void addProduct(Product *product)
    {
        m_products.push_back(product);
    }

    void displayProducts() const
    {
        std::cout << "---------Products---------" << std::endl;
        for (int i = 0; i < m_products.size(); ++i)
        {
            m_products[i]->displayName();
        }
    }

    void applyDiscount(const ROLES role)
    {
        if (isDiscounted || !Product::checkCanBeDiscounted(role))
            return;

        for (int i = 0; i < m_products.size(); ++i)
        {
            m_products[i]->applyDiscount(role);
        }

        isDiscounted = true;
    }
};

#endif