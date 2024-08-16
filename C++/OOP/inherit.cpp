#include <iostream>

class Base {
    public:
        void play() {
            std:: cout << "Base print" << std::endl;
        }
        void publicprint(int a, int b, int c) {
            std:: cout << "public print" << std::endl;
        }
    protected:
        void protectedprint() {
            std:: cout << "protected print" << std::endl;
        }
    private:
        void privateprint() {
            std:: cout << "private print" << std::endl;
        }
};

class Derived : private Base {
    public:
        void play() {
            std:: cout << "Derived print" << std::endl;
        }
        Derived() {
            
        }
};

int main () {
    Derived obj;
    obj.play();

    Base b;
    b.play();

    Derived * d = reinterpret_cast<Derived*>(&b);
    d->play();
    
}