#ifndef Library_H
#define Library_H

#include <iostream>
#include <vector>
#include <optional>

#include "./book.hpp"

class Library
{
    size_t m_book_index{1};
    size_t m_book_count;
    std::vector<Book *> m_books;

private:
    Book *find_book_by_id(size_t) const;

public:
    Library();
    Library(const std::vector<Book *> &);
    Library(const Library &) = default;
    ~Library();

    // CRUD OPERATIONS
    void add_book(Book *);
    void view_book(size_t) const;
    void update_book(size_t, const std::string &);
    void delete_book(size_t);

    std::optional<Book *> search_by_title(const std::string &) const;
    void list_books() const;
    int get_books_count() const;

    friend std::ostream &operator<<(std::ostream &os, const Library &library);
};

#endif
