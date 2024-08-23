#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <memory>
#include "../include/author.hpp"

class Book
{
    size_t m_id;
    std::string m_title;
    std::vector<std::shared_ptr<Author>> m_authors;

public:
    Book() = delete;
    Book(const std::string &, const std::vector<std::shared_ptr<Author>> &);
    Book(const std::string &, std::initializer_list<std::shared_ptr<Author>>);
    ~Book() = default;

    size_t get_id() const;
    std::string get_title() const;
    std::vector<std::shared_ptr<Author>> get_authors() const;

    void set_id(size_t);
    void set_title(const std::string &);
    void set_authors(std::vector<std::shared_ptr<Author>> &);
};

#endif