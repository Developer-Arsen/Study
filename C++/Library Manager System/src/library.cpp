#include <iostream>
#include <vector>
#include <optional>

#include "../include/library.hpp"

Library::Library() : m_book_count{0} {}
Library::Library(const std::vector<Book *> &books) : m_books{books}, m_book_count{books.size()} {}

Library::Library(const Library& library) 
    : Library{}
{
    std::cout <<library.m_book_count << std::endl;
    for (size_t i = 0; i < library.m_book_count; i++)
    {
        Book * ptr = new Book(*library.m_books[i]);
        add_book(ptr);
    }
}

Library::~Library()
{
    for (size_t i = 0; i < m_books.size(); i++)
    {
        delete m_books[i];
    }
    m_book_count = 0;
}

void Library::add_book(Book *book)
{
    book->set_id(m_book_index);
    m_books.push_back(book);
    m_book_index++;
    m_book_count++;
}

void Library::view_book(size_t id) const
{
    Book *tmp = find_book_by_id(id);

    if (!tmp)
    {
        std::cerr << "invalid id" << std::endl;
        return;
    }

    std::cout << "------------BOOK-----------" << std::endl;
    std::cout << "Id:" << tmp->get_id() << std::endl;
    std::cout << "Title: " << tmp->get_title() << std::endl
              << std::endl
              << std::endl;
}

void Library::update_book(size_t id, const std::string &title)
{
    Book *tmp = find_book_by_id(id);

    if (!tmp)
    {
        std::cerr << "invalid id" << std::endl;
        return;
    }

    tmp->set_title(title);
}

void Library::delete_book(size_t id)
{
    Book *tmp = nullptr;

    for (size_t i = 0; i < m_books.size(); i++)
    {
        if (id == m_books[i]->get_id())
        {
            tmp = m_books[i];
            m_books.erase(m_books.begin() + i);
            break;
        }
    }

    if (!tmp)
    {
        std::cerr << "invalid id" << std::endl;
        return;
    }

    delete tmp;
    m_book_count--;
    m_book_index--;
    
}

void Library::list_books() const
{
    std::cout << "------------BOOKS-----------" << std::endl;

    for (size_t i = 0; i < m_books.size(); i++)
    {
        std::cout << "Id:" << m_books[i]->get_id() << std::endl;
        std::cout << "Title: " << m_books[i]->get_title() << std::endl
                  << std::endl;
    }

    std::cout << "---------BOOKS END-----------" << std::endl
              << std::endl
              << std::endl;
}

std::optional<Book *> Library::search_by_title(const std::string &title) const
{
    for (size_t i = 0; i < m_books.size(); i++)
    {
        if (m_books[i]->get_title() == title)
        {
            return m_books[i];
        }
    }
    return nullptr;
}

int Library::get_books_count() const
{
    return m_book_count;
}

Book *Library::find_book_by_id(size_t id) const
{
    for (size_t i = 0; i < m_books.size(); i++)
    {
        if (id == m_books[i]->get_id())
        {
            return m_books[i];
        }
    }

    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const Library &library)
{
    os << "------------BOOKS-----------" << std::endl;
    for (size_t i = 0; i < library.m_books.size(); i++)
    {
        os << "Id:" << library.m_books[i]->get_id() << std::endl;
        os << "Title: " << library.m_books[i]->get_title() << std::endl;
    }
    os << "---------BOOKS END-----------" << std::endl;

    return os;
}