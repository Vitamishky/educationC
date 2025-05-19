#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <atomic>
#include <cmath>
#include <chrono>

std::atomic<unsigned long> TOTAL_POINT_IN_CIRCLE(0);
unsigned long TOTAL_POINTS = 100000000;
int NUM_THREADS = std::thread::hardware_concurrency();

void monteCarlo(unsigned long pointsPerThread) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    unsigned long localCount = 0;

    for (unsigned long i = 0; i < pointsPerThread; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        if (x * x + y * y <= 1.0) {
            localCount++;
        }
    }

    TOTAL_POINT_IN_CIRCLE += localCount;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    unsigned long pointsPerThread = TOTAL_POINTS / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(monteCarlo, pointsPerThread);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    double piEstimate = 4.0 * TOTAL_POINT_IN_CIRCLE / TOTAL_POINTS;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Estimated value of π: " << piEstimate << std::endl;
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
    std::cout << "Number of threads: " << NUM_THREADS << std::endl;

    return 0;
}