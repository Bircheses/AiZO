#ifndef AIZO_COUNTER_H
#define AIZO_COUNTER_H

#include <windows.h>
#include <chrono>

class Counter {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    double elapsedTime{};
public:
    void start();
    void stop();
    [[nodiscard]] double getElapsedTime() const;
};


#endif
