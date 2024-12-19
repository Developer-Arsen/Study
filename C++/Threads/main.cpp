#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <condition_variable>
#include <queue>
#include <vector>
#include <unordered_set>
#include <functional>

std::mutex mtx;
std::string filename = "example.txt";
std::condition_variable cv;
bool readFlag = 0;

void read() {
    std::unique_lock<std::mutex>lock(mtx);
    cv.wait(lock, [=]{ return readFlag;});
    std::ifstream inputstream(filename);

    if (!inputstream) {
        abort();
    }

    std::string line;
    while(std::getline(inputstream, line)) {
        std::cout << line << "\n";

    }
}

void write() {
    std::unique_lock<std::mutex>lock(mtx);
    std::ofstream outputstream(filename);
    if (!outputstream) {
        abort();
    }
    for (int i  = 0 ; i < 5 ; ++i) {
        outputstream << "Thread 1 is running int" <<  i << "\n";
    }
    readFlag = 1;
    cv.notify_one();

}

class ThreadPool {
    private:
    std::vector<std::thread> threads;
    std::queue<std::function<void(void)>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    size_t threads_count;
    bool runState = false;

    public:
    ThreadPool(const size_t ct) {
        threads_count = ct;
        for (size_t i = 0 ; i < threads_count; ++i) {
            threads.emplace_back(&ThreadPool::thread_body, this);
        }
    }

    ~ThreadPool() {
        terminate();
        for (size_t i = 0 ; i < threads_count; ++i) {
            threads[i].join();
        }
    }

    void terminate() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            runState = false;
        }

        cv.notify_all();
    }

    void addtask(const std::function<void(void)>& fn) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                tasks.push(fn);
            }
            cv.notify_one();
    }

    private:

    void thread_body() {
        while (true) {
            std::function<void(void)> task;

            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&]{ return !runState || !tasks.empty(); });

                if (tasks.empty() || runState) {
                    break;
                }

                task = tasks.front();
                tasks.pop();
            }

            std::cout << std::this_thread::get_id() << ": ";
            task();
        }
    }


        
};

void even() {
    std::cout << "Even" << std::endl;
}

void odd() {
    std::cout << "Odd" << std::endl;
}


int main() {
   
   ThreadPool tp{3};

   tp.addtask([]{
    std::cout << "lyambda\n";
   });
}