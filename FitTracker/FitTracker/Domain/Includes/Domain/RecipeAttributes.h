#pragma once

#include <QString>

namespace Domain {
    // Class that contains all attributes of the recipe
    class RecipeAttributes final {
    public:
        RecipeAttributes() = default;
        ~RecipeAttributes() = default;

        void setPortionsCount(int value);
        int getPortionsCount() const;

        void setPreparingTime(float value);
        float getPreparingTime() const;

        void setCookingTipe(float value);
        float getCookingTipe() const;

        void setDescription(const QString& description);
        const QString& getDescription() const;

    private:
        int portionsCount_ = 0;         // Count of portions of the recipe food
        float preparingTime_ = 0.f;     // Time to prepare food for cooking
        float cookingTime_ = 0.f;       // Time to cook
        QString description_;           // Description of the recipe (steps to cook and start description)
    };
} // namespace Domain