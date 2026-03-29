#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

int main() {
    const uint64_t count = 20000000; 
    
    std::vector<uint64_t> values;
    values.reserve(count * 2);

    auto timeNow = std::chrono::high_resolution_clock::now();

    for (uint64_t i = 0; i < count; i++) {
        values.push_back(i);
    }

    for (uint64_t i = count; i > 0; i--) {
        values.push_back(i);
    }

    auto timeExec = std::chrono::high_resolution_clock::now() - timeNow;
    double ms = std::chrono::duration<double, std::milli>(timeExec).count();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "time exec in milliseconds: " << ms << "\n";

    volatile uint64_t antiTrapaca = values.front() + values.back();
    (void)antiTrapaca;

    return 0;
}