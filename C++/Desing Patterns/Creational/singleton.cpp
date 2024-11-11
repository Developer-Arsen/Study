#include <iostream>
#include <thread>
#include <mutex>

class SingleTon {
    std::string _val;
    static SingleTon* _singleton;
    static std::mutex mtx;

    protected:
        SingleTon(const std::string& value) : _val(value) {}
    public:
        SingleTon(const SingleTon&) = delete;
        void operator=(const SingleTon&) = delete;

        static SingleTon* GetInstance(const std::string&);

        std::string value() const {
            return _val;
        }
};

SingleTon* SingleTon::_singleton = nullptr;
std::mutex SingleTon::mtx;

SingleTon* SingleTon::GetInstance(const std::string& value) {
    
    std::lock_guard<std::mutex> lock(mtx);
    if (_singleton == nullptr) {
        _singleton = new SingleTon(value);
    }

    return _singleton;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingleTon* singleton = SingleTon::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingleTon* singleton = SingleTon::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
