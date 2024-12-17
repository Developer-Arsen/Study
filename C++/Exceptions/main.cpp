#include <iostream>
#include <stdexcept>
class Qyastm : public std::logic_error {
    public:
        Qyastm(const std::string& msg) : std::logic_error(msg) {}
        Qyastm(const char * msg) : std::logic_error(msg) {}
        virtual ~Qyastm() = default;

        const  char * what() const noexcept override  {
            return "hello hello";
        }

};

class A
{
public:
    A(/* args */)=default;
    ~A() throw(std::runtime_error) {
        throw std::runtime_error("hello");
    };
};

void foo () {
    A a;
}

void too () {
    foo();
    throw 1;
}






int main () {
   
 try
 {
    foo();
 }
 catch(const std::runtime_error& e)
 {
    std::cerr << e.what() << '\n';
 }
 
    
}