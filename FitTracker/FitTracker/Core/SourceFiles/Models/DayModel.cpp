#include "Core/Models/DayModel.h"
#include "Domain/Day.h"

namespace Core {
    DayModel::DayModel(QObject* parent)
        : QObject(parent)
        , meals_(new MealListModel(this)) {}

    void DayModel::setDay(const Domain::Day& day) {
        date_ = day.getDate();

        emit dateChanged();
        emit weightChanged();
    }

    const QDate& DayModel::getDate() const {
        return date_;
    }

    float DayModel::getWeight() const {
        return weight_;
    }

    MealListModel* DayModel::getMeals() const {
        return meals_;
    }
} // namespace Core

