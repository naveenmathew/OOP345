#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <chrono>
#include <iostream>
#include <string>

namespace seneca {
    struct Task {
        std::string name;
        std::string units;
        std::chrono::steady_clock::duration duration;
    };

    class TimedTask {
        size_t current_record;
        std::chrono::steady_clock::time_point start;
        std::chrono::steady_clock::time_point end;
        Task tasks[10];
    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* task_name);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);
    };
}

#endif
