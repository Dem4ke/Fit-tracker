#include "Core/Models/DayModel.h"
#include "Core/Models/MealListModel.h"

#include "Domain/Day.h"

namespace Core {
    DayModel::DayModel(QObject* parent)
        : QObject(parent)
        , meals_(new MealListModel(this)) {}

    void DayModel::setDay(const Domain::Day& day) {
        date_ = day.getDate();

        emit dateChanged();
    }

    const QDate& DayModel::gatDate() const {
        return date_;
    }

    MealListModel* DayModel::getMeals() const {
        return meals_;
    }
} // namespace Core

