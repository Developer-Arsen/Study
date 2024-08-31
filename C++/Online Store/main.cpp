#include <iostream>
#include <vector>

#include "src/cart.hpp"
#include "src/laptop.hpp"
#include "src/car.hpp"
#include "src/employee.hpp"


using std::cout;
using std::endl;

int main () {

    Laptop * lap = new Laptop(1000, 1,"lap");
    Car * bmw = new Car(10000,1,"lap");

    std::vector<Product*> products{lap, bmw};

    Cart store(products);
    store.displayProducts();
    cout<<endl<<endl;

    Employee arsen(store, MIDDLE);
    arsen.showProduct();
    arsen.makeDiscount();
    cout<<endl<<endl;

    arsen.showProduct();


}