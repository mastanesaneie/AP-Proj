#pragma once 
#include <chrono> 
#include <iostream> 
 
class Timer { 
    using Clock = std::chrono::steady_clock; 
    using TimePoint = Clock::time_point; 
 
    TimePoint start_time{}, end_time{}; 
    bool is_running = false; 
 
public: 
    void reset() { 
        start_time = end_time = TimePoint{}; 
        is_running = false; 
    } 
 
    void start() { 
        start_time = Clock::now(); 
        is_running = true; 
    } 
 
    void stop() { 
        if (is_running) { 
            end_time = Clock::now(); 
            is_running = false; 
        } 
    } 
 
    double elapsedMilliseconds() const { 
        return is_running ? std::chrono::duration<double, std::milli>(Clock::now() - start_time).count() 
                          : std::chrono::duration<double, std::milli>(end_time - start_time).count(); 
    } 
 
    friend std::ostream& operator<<(std::ostream& out, const Timer& timer) { 
        return out << timer.elapsedMilliseconds() << " ms"; 
    } 
};