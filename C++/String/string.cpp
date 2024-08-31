#include <iostream>
#include <stdio.h>

class String
{
    char *m_str;
    size_t size;

public:
    String() : m_str(nullptr), size(0) {};
    String(const char * ptr) {
        if (ptr == nullptr) {
            std::cerr<< "Null has been sent" << std::endl;
            return;
        }

        size_t i = 0;
        while (ptr[i++]);
        if (i == 0) {
            std::cerr<< "string is empty" << std::endl;
            return ;
        }

        m_str = new char[++i];
        size_t j = 0;
        while(ptr[j]) {
            m_str[j] = ptr[j++];
            std::cout << m_str[j-1]  << ptr[j-1] << std::endl;
        }
        // std::cout << j << std::endl;

        // m_str[j] = '\0';
        // printf("%s \n", m_str);

        // std::cout << m_str << std::endl;
    };
};