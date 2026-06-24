#include "Domain/FoodAttributes.h"

namespace Domain {
    void FoodAttributes::setName(const QString& name) {
        name_ = name;
    }

    const QString& FoodAttributes::getName() const {
        return name_;
    }

    void FoodAttributes::setFats(float value) {
        fats_ = value;
    }

    float FoodAttributes::getFats() const {
        return fats_ * weight_;
    }

    void FoodAttributes::setProteins(float value) {
        proteins_ = value;
    }

    float FoodAttributes::getProteins() const {
        return proteins_ * weight_;
    }

    void FoodAttributes::setCarbohydrates(float value) {
        carbohydrates_ = value;
    }

    float FoodAttributes::getCarbohydrates() const {
        return carbohydrates_ * weight_;
    }

    void FoodAttributes::setWeight(float value) {
        weight_ = value;
    }

    float FoodAttributes::getWeight() const {
        return weight_;
    }

    // Calculate and return calories
    float FoodAttributes::getCalories() const {
        return (fats_ * 9.f + proteins_ * 4.f + carbohydrates_ * 4.f) * weight_;
    }
} // namespace Domain