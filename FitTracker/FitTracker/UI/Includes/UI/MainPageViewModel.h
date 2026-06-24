#pragma once

#include <QObject>
#include <memory>

namespace Core {
    class DayModel;
} // namespace Core

namespace UI {
    // View model for main page QML ui view
    class MainPageViewModel : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            Core::DayModel* day
            READ getDisplayedDay
            NOTIFY displayedDayChanged)

    public:
        MainPageViewModel(QObject* parent = nullptr);
        ~MainPageViewModel() override = default;

        void setDisplayedDay(const std::shared_ptr<Core::DayModel>& day);
        Core::DayModel* getDisplayedDay() const;

    signals:
        void displayedDayChanged();

    private:
        std::shared_ptr<Core::DayModel> day_ = nullptr;        // Current day which displayed
    };
} // namespace UI