#ifndef AIZO_COUNTER_H
#define AIZO_COUNTER_H

#include <windows.h>
#include <chrono>
/**
 * Counter class that counts time
 */
class Counter {
private:
    std::chrono::high_resolution_clock::time_point startTime; //start time point
    std::chrono::high_resolution_clock::time_point endTime; //end time point
    double elapsedTime{}; // time between start and end points
public:
    void start(); //starts clock
    void stop(); //stops clock
    [[nodiscard]] double getElapsedTime() const; //returns value of time passed between start and end point in milliseconds
};


#endif
