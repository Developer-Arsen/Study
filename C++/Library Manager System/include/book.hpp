#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "../include/author.hpp"

class Book
{
    size_t m_id;
    std::string m_title;
    std::vector<std::shared_ptr<Author>> m_authors;

public:
    Book() = default;
    Book(const std::string &, const std::vector<std::shared_ptr<Author>> &);
    Book(const std::string &, std::initializer_list<std::shared_ptr<Author>>);
    // Book(const Book&);
    ~Book() = default;

    size_t get_id() const;
    std::string get_title() const;
    std::vector<std::shared_ptr<Author>> get_authors() const;

    void set_id(size_t);
    void set_title(const std::string &);
    void set_authors(std::vector<std::shared_ptr<Author>> &);

    friend std::istream &operator>>(std::istream &, Book &);
    friend std::ostream &operator<<(std::ostream &, const Book &);
};

std::istream &operator>>(std::istream &istr, Book &book)
{
    std::string title;
    std::vector<std::string> authors;
    std::string authorsInput;

    std::cout << "enter title" << std::endl;
    std::getline(istr, title);

    std::cout << "enter authors seperate them with comma" << std::endl;
    std::getline(istr, authorsInput);

    std::stringstream ss(authorsInput);
    std::string author;
    while (std::getline(ss, author, ','))
    {
        author.erase(0, author.find_first_not_of(" \t"));
        author.erase(author.find_last_not_of(" \t") + 1);
        if (!author.empty())
        {
            authors.push_back(author);
        }
    }

    for (size_t i = 0; i < authors.size(); i++)
    {
        book.m_authors.push_back(std::make_shared<Author>(authors[i]));
    }

    book.m_title = std::move(title);
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const Book &book)
{
    std::cout << "--------book --------" << std::endl;
    std::cout << "Title: " << book.get_title() << std::endl;
    for (size_t i = 0; i < book.m_authors.size(); i++)
    {
        std::cout << "Author:  " << book.m_authors[i]->get_name() << std::endl;
    }

    std::cout << "--------book --------" << std::endl;

    return ostr;
}

#endif