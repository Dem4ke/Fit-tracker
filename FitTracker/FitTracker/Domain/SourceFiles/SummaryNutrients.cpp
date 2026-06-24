#include "Domain/SummaryNutrients.h"

namespace Domain {
    void SummaryNutrients::setFats(float value) {
        fats_ = value;
    }

    float SummaryNutrients::getFats() const {
        return fats_;
    }

    void SummaryNutrients::setProteins(float value) {
        proteins_ = value;
    }

    float SummaryNutrients::getProteins() const {
        return proteins_;
    }

    void SummaryNutrients::setCarbohydrates(float value) {
        carbohydrates_ = value;
    }

    float SummaryNutrients::getCarbohydrates() const {
        return carbohydrates_;
    }

    // Calculate summary calories
    float SummaryNutrients::getCalories() const {
        return fats_ * 9.f + proteins_ * 4.f + carbohydrates_ * 4.f;
    }
} // namespace Domain