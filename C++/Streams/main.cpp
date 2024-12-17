#include <iostream>
#include <fstream>
#include <string>

int main () {


    const std::string filename = "example.txt";

    {
        std::ofstream outputStream(filename);
        if (!outputStream) {
            std::cerr << "Error opening file for writing" << std::endl;
            return 1;
        }

        outputStream << "Hello WOrld" << std::endl;
        outputStream << "nor tox" << std::endl;
    }

    {
        std::ifstream inputStream(filename);
        if (!inputStream) {
            std::cerr << "chem kara bacem" << std::endl;
            return 1;
        }

        std::string line;
        while(std::getline(inputStream, line)) {
            std::cout << line << std::endl;
        }
    }
}