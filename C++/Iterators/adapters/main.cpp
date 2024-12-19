#include <iostream>
#include <vector>
#include <iterator>
#include <list>


int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};


    std::back_insert_iterator<std::vector<int>> back_it(vec);

    *back_it = 20;
    *back_it = 12;

    std::list<int> lst = {1,2,3};
    std::front_insert_iterator<std::list<int>> front_it(lst);

    *front_it = -1;

    std::ostream_iterator<int> out_it(std::cout, " ");

    // for (int x : vec) {
    //     *out_it = x;
    //     out_it++;
    // }

    // std::cout << "Enter numbers (Ctrl+D to end): ";
    // std::istream_iterator<int> in_it(std::cin) , end;
    // std::vector<int> vec2(in_it, end);

    // for (int x : vec2) {
    //     std::cout << x << std::endl;
    // }

    // while(true);

    std::vector<int> ars1 {1,2,3};
    std::vector<int> ars2;

    std::move_iterator<std::vector<int>::iterator> move_it(ars1.begin());
    std::move_iterator<std::vector<int>::iterator> move_end(ars1.end());

    std::copy(move_it, move_end, std::back_inserter(ars2));

    for (std::reverse_iterator<std::vector<int>::iterator> rit = ars2.rbegin(); rit != ars2.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    // for (std::reverse_iterator<std::vector<int>::iterator> rit = vec.rbegin(); rit != vec.rend(); ++rit) {
    //     std::cout << *rit << std::endl;
    // }

    // for(std::reverse_iterator<std::list<int>::iterator> rit = lst.begin(); rit != lst.rend(); ++rit) {
    //     std::cout << *rit << std::endl;
    // }
}