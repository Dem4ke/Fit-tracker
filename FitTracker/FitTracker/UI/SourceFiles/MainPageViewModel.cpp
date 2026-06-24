#include "UI/MainPageViewModel.h"
#include "Core/Models/DayModel.h"

namespace UI {
    MainPageViewModel::MainPageViewModel(QObject* parent)
        : QObject(parent) {}

    void MainPageViewModel::setDisplayedDay(const std::shared_ptr<Core::DayModel>& day) {
        day_ = day;
    }

    Core::DayModel* MainPageViewModel::getDisplayedDay() const {
        return day_.get();
    }
} // namespace UI