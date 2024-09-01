#include <iostream>
#include <vector>

#include "src/author.cpp"
#include "src/book.cpp"
#include "src/library.cpp"

using std::cout;
using std::endl;

int main () {
    Library lib;

    Book * ptr = new Book();
    std::cin >> *ptr;
    std::cout << *ptr;


    // cout << *ptr;
    // std::vector<std::shared_ptr<Author>> authors;
    // std::shared_ptr<Author> obj = std::make_shared<Author>("Arsen Mkhitaryan");
    // authors.push_back(obj);

    // Book * book1 (new Book("first girq", authors));
    // Book * book2 (new Book("second girq", authors));
    // Book * book3 (new Book("third girq", authors));

    // lib.add_book(book1);
    // lib.add_book(book2);
    // lib.add_book(book3);

    // Library lib2 = lib;
    // lib += lib2;

    // std::cout << lib << std::endl;
    // std::cout << lib2.get_books_count() << std::endl;

    
    // lib.list_books();
    // lib.view_book(2);
    // lib.view_book(1);
    // lib.delete_book(1);
    // lib.list_books();

}