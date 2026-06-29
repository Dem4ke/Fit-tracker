#include "UI/MainPageViewModel.h"

namespace UI {
    MainPageViewModel::MainPageViewModel(QObject* parent)
        : QObject(parent)
        , weekList_(new Core::WeekListModel(this)) {}

    void MainPageViewModel::setDisplayedDay(const std::shared_ptr<Core::DayModel>& day) {
        day_ = day;

        emit displayedDayChanged();
    }

    Core::DayModel* MainPageViewModel::getDisplayedDay() const {
        return day_.get();
    }

    Core::WeekListModel* MainPageViewModel::getWeekList() const {
        return weekList_;
    }

    void MainPageViewModel::setNewDay(const QDate& date) {
        emit dayChangeRequest(date);
    }
} // namespace UI