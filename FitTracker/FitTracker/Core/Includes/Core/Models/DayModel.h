#pragma once

#include "Core/Models/MealListModel.h"

#include <QObject>
#include <QDate>

namespace Domain {
    class Day;
} // namespace Domain

namespace Core {
    // Model class that describes a day for a QML
    class DayModel : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            QDate date
            READ getDate
            NOTIFY dateChanged)

        Q_PROPERTY(
            float weight
            READ getWeight
            NOTIFY weightChanged)

        Q_PROPERTY(
            MealListModel* meals
            READ getMeals
            CONSTANT)

    public:
        DayModel(QObject* parent = nullptr);
        ~DayModel() override = default;

        void setDay(const Domain::Day& day);

        const QDate& getDate() const;
        float getWeight() const;
        MealListModel* getMeals() const;

    signals:
        void dateChanged();
        void weightChanged();

    private:
        QDate date_;                            // Displayed day date
        float weight_ = 0.0f;                   // Measured weight
        MealListModel* meals_ = nullptr;        // Model of the list of meals
    };
} // namespace Core