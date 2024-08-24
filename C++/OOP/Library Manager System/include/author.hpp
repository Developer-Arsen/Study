#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>

class Author
{
private:
    std::string m_name;
    int m_book_count;

public:
    Author() = default;
    Author(const std::string &);
    Author(const Author &) = default;

    std::string get_name() const;
    int get_book_count() const;
    void set_name(std::string &);
    void set_book_count(int);
};

#endif