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

    friend std::istream &operator>>(std::istream &, Author &);
    friend std::ostream &operator<<(std::ostream &, const Author &);
};

std::istream &operator>>(std::istream &istr, Author &author)
{
    std::string fullname;
    int count;

    std::cout << "enter fullname" << std::endl;
    istr >> fullname;
    std::cout << "enter count" << std::endl;
    istr >> count;

    // validations
    author.m_name = std::move(fullname);
    author.m_book_count = count;

    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const Author &author)
{
    std::cout << "--------autor --------" << std::endl;
    std::cout << "Fullname: " << author.get_name() << std::endl;
    std::cout << "Books Count: " << author.get_book_count() << std::endl;
    std::cout << "--------autor --------" << std::endl;

    return ostr;
}

#endif