#pragma once

#include "Core/Models/DayModel.h"
#include "Core/Models/WeekListModel.h"

#include <QObject>
#include <memory>

namespace UI {
    // View model for main page QML ui view
    class MainPageViewModel : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            Core::DayModel* day
            READ getDisplayedDay
            NOTIFY displayedDayChanged)

        Q_PROPERTY(
            Core::WeekListModel* weekList
            READ getWeekList
            CONSTANT)

    public:
        MainPageViewModel(QObject* parent = nullptr);
        ~MainPageViewModel() override = default;

        void setDisplayedDay(const std::shared_ptr<Core::DayModel>& day);
        Core::DayModel* getDisplayedDay() const;
        Core::WeekListModel* getWeekList() const;

        Q_INVOKABLE void setNewDay(const QDate& date);

    signals:
        // Set QML information about day changes
        void displayedDayChanged();
        // Request to find a new day by the date
        void dayChangeRequest(const QDate& date);

    private:
        std::shared_ptr<Core::DayModel> day_ = nullptr;        // Current day which displayed
        Core::WeekListModel* weekList_ = nullptr;              // Current day which displayed
    };
} // namespace UI