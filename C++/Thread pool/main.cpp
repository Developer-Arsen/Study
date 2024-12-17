#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <thread>
#include <queue>

class ThreadPool {
public:
    ThreadPool(size_t count) : threads_count(count) {
        for (int i = 0; i < count; ++i) {
            threads.emplace_back(&ThreadPool::thread_body, this);
        }
    }
    ~ThreadPool() {
        terminate();
        cv.notify_all();
        for (int i = 0; i < threads_count; ++i) {
            threads[i].join();
        }
    }

    void terminate() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            terminate_val = true;
        }
        cv.notify_all();
    }

    void add_task(const std::function<void(void)> &task) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            tasks.push(task);
        }
        cv.notify_one();
    }
private:
    std::queue<std::function<void(void)>> tasks;
    std::vector<std::thread> threads;
    std::mutex mtx;
    std::condition_variable cv;
    const size_t threads_count;
    bool terminate_val = false;

    void thread_body() {
        while (true) {
            std::function<void(void)> task;

            {
                std::unique_lock<std::mutex> lock(mtx);

                cv.wait(lock, [&] { return terminate_val || !tasks.empty(); });

                if (terminate_val && tasks.empty()) {
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
    const size_t pool_size = 5;

    ThreadPool tp(pool_size);
    tp.add_task([] {
        std::cout << "Lambda" << std::endl;
    });

    tp.add_task(odd);
    tp.add_task(even);

    tp.terminate();

    return 0;
}