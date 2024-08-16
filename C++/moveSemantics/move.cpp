#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> create() {
    std::vector<std::string> coll;
    coll.reserve(3);
    std::string s = "data";
    coll.push_back(s);
    coll.push_back(s + s);
    coll.push_back(std::move(s));

    return coll;
}


static int count;
class a {
    public:
    const static int count {10};
};

int main() {
    std::vector<std::string> v;
    v = create();

    std::string s {"hello"};

    s = std::move(s);
    std::cout << count << std::endl;
}