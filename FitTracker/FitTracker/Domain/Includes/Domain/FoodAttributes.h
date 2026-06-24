#pragma once

#include <QString>

namespace Domain {
    // Class that contains all attributes of the food
    class FoodAttributes final {
    public:
        FoodAttributes() = default;
        ~FoodAttributes() = default;

        void setName(const QString& name);
        const QString& getName() const;

        void setFats(float value);
        float getFats() const;

        void setProteins(float value);
        float getProteins() const;

        void setCarbohydrates(float value);
        float getCarbohydrates() const;

        void setWeight(float value);
        float getWeight() const;

        float getCalories() const;

    private:
        QString name_;                  // Name of the food
        float fats_ = 0.0f;             // Fats value of the food per 100 g
        float proteins_ = 0.0f;         // Proteins value of the food per 100 g
        float carbohydrates_ = 0.0f;    // Carbohydrates value of the food per 100 g
        float weight_ = 0.0f;           // Weight value of the food
    };
} // namespace Domain