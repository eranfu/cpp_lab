#include <mutex>
#include <thread>
#include <iostream>

int main() {
    int32_t value = 0;
    std::mutex mutex;

    std::thread t([&]() {
        while (value < 100) {
            auto guard = std::lock_guard(mutex);
            ++value;
            std::cout << value << std::endl;
        }
    });

    while (value < 100) {
        auto guard = std::lock_guard(mutex);
        ++value;
        std::cout << value << std::endl;
    }
    t.join();
    return 0;
}
