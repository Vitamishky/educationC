#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <chrono>

int calculateResult() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    
    std::shared_future<int> sharedFuture = future.share();
    
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back([&sharedFuture, i]() {
            std::cout << "Thread " << i << " waiting result..." << std::endl;
            int result = sharedFuture.get();
            std::cout << "Thread " << i << " result: " << result << std::endl;
        });
    }
    
    std::thread calculationThread([&promise]() {
        int result = calculateResult();
        promise.set_value(result);
    });
    
    for (auto& thread : threads) {
        thread.join();
    }
    calculationThread.join();
    
    return 0;
}
