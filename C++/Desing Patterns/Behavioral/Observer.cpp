#include <iostream>
#include <vector>
#include <algorithm>

void prt() {
    std::cout << "yaaay console.log(aaaa)" << std::endl;

}

struct IListener {
    public:
    virtual ~IListener(){};
    virtual void onButtonClicked() const = 0;
};

class ConcreteListener : public IListener {
    void (*fn_) ();
    public:
        ConcreteListener(void (*fn) ()) : fn_(fn) {}
        void onButtonClicked () const override {
            if (fn_) {  
                fn_();  
            }
        }
};

void exampleFunction() {
    std::cout << "Callback function called!" << std::endl;
}

class Button {
    std::vector<IListener*> listeners;
    public:

    void addListener(IListener* listener) {
        listeners.push_back(listener);
    }

    void removeListener(IListener* listener) {
        auto it = std::remove(listeners.begin(), listeners.end(), listener);
        listeners.erase(it, listeners.end());
    }

    void click () {
        std::cout << "button Clicked" << std::endl;
        for( IListener* listener : listeners) {
            listener->onButtonClicked();
        }
    }
};

int main () {
    Button * btn = new Button();

    btn->addListener(new ConcreteListener(exampleFunction));
    btn->addListener(new ConcreteListener(exampleFunction));
    btn->addListener(new ConcreteListener(exampleFunction));
    btn->addListener(new ConcreteListener(exampleFunction));
    btn->click();
}
