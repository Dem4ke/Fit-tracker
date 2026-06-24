#include "Core/Models/FoodModel.h"
#include "Domain/IFood.h"
#include "Domain/FoodAttributes.h"

namespace Core {
    FoodModel::FoodModel(QObject* parent)
        : QObject(parent) {}

    void FoodModel::setFood(const std::shared_ptr<Domain::IFood>& food) {
        foodAttributes_ = food->getFoodAttributes();
    }

    std::shared_ptr<Domain::IFood> FoodModel::getFood() const {
        // TODO create food creation and returning
        return nullptr;
    }

    void FoodModel::setName(const QString& name) {
        foodAttributes_.setName(name);
        emit nameChanged();
    }

    const QString& FoodModel::getName() const {
        return foodAttributes_.getName();
    }

    void FoodModel::setFats(float value) {
        foodAttributes_.setFats(value);
        emit fatsChanged();
    }

    float FoodModel::getFats() const {
        return foodAttributes_.getFats();
    }

    void FoodModel::setProteins(float value) {
        foodAttributes_.setProteins(value);
        emit proteinsChanged();
    }

    float FoodModel::getProteins() const {
        return foodAttributes_.getProteins();
    }

    void FoodModel::setCarbohydrates(float value) {
        foodAttributes_.setCarbohydrates(value);
        emit carbohydratesChanged();
    }

    float FoodModel::getCarbohydrates() const {
        return foodAttributes_.getCarbohydrates();
    }

    void FoodModel::setWeight(float value) {
        foodAttributes_.setWeight(value);
        emit weightChanged();
    }

    float FoodModel::getWeight() const {
        return foodAttributes_.getWeight();
    }
} // namespace Core