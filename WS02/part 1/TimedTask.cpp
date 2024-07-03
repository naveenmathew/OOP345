#include <iomanip>
#include "TimedTask.h"


namespace seneca {

    TimedTask::TimedTask() : current_record(0) {}

    void TimedTask::startClock() {
        start = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        end = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* task_name) {
        if (current_record < 10) {
            tasks[current_record].name = task_name;
            tasks[current_record].units = "nanoseconds";
            tasks[current_record].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            ++current_record;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedTask& tt) {
        os << "--------------------------\n"
           << "Execution Times:\n"
           << "--------------------------\n";
        for (size_t i = 0; i < tt.current_record; ++i) {
            os << std::setw(21) << std::left << tt.tasks[i].name
               << std::setw(13) << std::right << tt.tasks[i].duration.count() << ' '
               << tt.tasks[i].units << '\n';
        }
        os << "--------------------------\n";
        return os;
    }
}
