#include "Domain/RecipeAttributes.h"

namespace Domain {
    void RecipeAttributes::setPortionsCount(int value) {
        portionsCount_ = value;
    }

    int RecipeAttributes::getPortionsCount() const {
        return portionsCount_;
    }

    void RecipeAttributes::setPreparingTime(float value) {
        preparingTime_ = value;
    }

    float RecipeAttributes::getPreparingTime() const {
        return preparingTime_;
    }

    void RecipeAttributes::setCookingTipe(float value) {
        cookingTime_ = value;
    }

    float RecipeAttributes::getCookingTipe() const {
        return cookingTime_;
    }

    void RecipeAttributes::setDescription(const QString& description) {
        description_ = description;
    }

    const QString& RecipeAttributes::getDescription() const {
        return description_;
    }
} // namespace Domain