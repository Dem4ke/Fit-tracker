#pragma once

#include <QObject>
#include <QDate>

namespace Domain {
    class Day;
} // namespace Domain

namespace Core {
    class MealListModel;

    // Model class that describes a day for a QML
    class DayModel : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            QDate date
            READ getDate
            NOTIFY dateChanged)

        Q_PROPERTY(
            MealListModel* meals
            READ getMeals
            CONSTANT)

    public:
        DayModel(QObject* parent = nullptr);
        ~DayModel() override = default;

        void setDay(const Domain::Day& day);
        const QDate& gatDate() const;

        MealListModel* getMeals() const;

    signals:
        void dateChanged();

    private:
        QDate date_;                            // Displayed day date
        MealListModel* meals_ = nullptr;        // Model of the list of meals
    };
} // namespace Core