#include <iostream>

struct Gen {
    virtual void print() {
        std::cout << "general exception" << std::endl;
    }
};

struct Soft : Gen {
    void print() override {
        std::cout << "Soft exception" << std::endl;
    }
};

template<typename T>
void foo(T) {
    std::cout << 1 << std::endl;
}

template<>
void foo(int) {
    std::cout << 2 << std::endl;
}

void foo(int) {
    std::cout << 3 << std::endl;
}


int main () {

    foo(0.0);
    foo(1);
    foo<>(1);

    // try {
    //     foo();
    // } catch(Gen e) {
    //     e.print();
    // }

    auto prime = [num=2]() mutable {
        while (true) {
            num++;
            int kes = num / 2;

            if (kes < 2) return num;
            int flag = 1;
            for (int i = 2; i*i <= num; ++i) {
                if (num % i == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return num;
        }
        return num;
    };  

    std::cout << prime() << std::endl;
    std::cout << prime() << std::endl;
    std::cout << prime() << std::endl;
}