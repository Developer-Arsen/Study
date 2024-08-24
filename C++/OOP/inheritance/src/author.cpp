#include "../include/author.hpp"
#include <iostream>

Author::Author(const std::string &name) : m_name{name} {}

std::string Author::get_name() const
{
    return m_name;
}

int Author::get_book_count() const
{
    return m_book_count;
}

void Author::set_name(std::string &name)
{
    m_name = name;
}
