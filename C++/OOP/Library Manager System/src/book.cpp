#include <vector>
#include <iostream>

#include "../include/book.hpp"

Book::Book(const std::string &title, const std::vector<std::shared_ptr<Author>> &authors) : m_id{0}, m_title{title}, m_authors{authors} {}
Book::Book(const std::string &title, std::initializer_list<std::shared_ptr<Author>> authors) : m_id{0}, m_title{title}
{
    for (const auto &author : authors)
    {
        m_authors.push_back(author);
    }
}

size_t Book::get_id() const
{
    return m_id;
}

std::string Book::get_title() const
{
    return m_title;
}

std::vector<std::shared_ptr<Author>> Book::get_authors() const
{
    return m_authors;
}

void Book::set_id(size_t id)
{
    m_id = id;
}

void Book::set_title(const std::string &title)
{
    m_title = title;
}

void Book::set_authors(std::vector<std::shared_ptr<Author>> &authors)
{
    m_authors = authors;
}