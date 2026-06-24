#include "Core/Models/MealModel.h"
#include "Domain/Meal.h"

namespace Core {
    MealModel::MealModel(QObject* parent)
        : QObject(parent)
        , foods_(new FoodListModel(this)) {}

    // Convert data from domain structure to the model
    void MealModel::setMeal(const Domain::Meal& meal) {
        // TODO finish convertation
        setName(meal.getName());
        foods_->setFoods(meal.getFoods());
    }

    // Convert model to domain structure
    Domain::Meal MealModel::getMeal() const {
        // TODO create convertation
        return Domain::Meal(0);
    }

    void MealModel::setName(const QString& name) {
        name_ = name;

        emit nameChanged();
    }

    const QString& MealModel::getName() const {
        return name_;
    }

    FoodListModel* MealModel::getFoods() const {
        return foods_;
    }
} // namespace Core