#pragma once

#include <memory>

namespace Domain {
    class Day;
} // namespace Domain

namespace Core {
    // Class that storage cached days and work with database
    class DayRepository final {
    public:
        DayRepository();
        ~DayRepository() = default;

        const std::shared_ptr<Domain::Day>& getDay() const;

    private:
        std::shared_ptr<Domain::Day> day_ = nullptr; // day for experiment
    };
} // namespace Core