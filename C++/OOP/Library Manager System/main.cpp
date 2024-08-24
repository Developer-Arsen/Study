#include <iostream>
#include <vector>

#include "src/author.cpp"
#include "src/book.cpp"
#include "src/library.cpp"

using std::cout;
using std::endl;

int main () {
    Library lib;

    std::vector<std::shared_ptr<Author>> authors;
    std::shared_ptr<Author> obj = std::make_shared<Author>("Arsen Mkhitaryan");
    authors.push_back(obj);

    std::shared_ptr<Book> book1 = std::make_shared<Book>("first girq", authors);
    std::shared_ptr<Book> book2 = std::make_shared<Book>("second girq", authors);
    std::shared_ptr<Book> book3 = std::make_shared<Book>("third girq", authors);

    lib.add_book(book1);
    lib.add_book(book2);
    lib.add_book(book3);


    lib.list_books();
    lib.view_book(2);
    lib.view_book(1);
    lib.delete_book(1);
    lib.list_books();

}