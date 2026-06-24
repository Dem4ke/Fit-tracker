#pragma once

#include "IFood.h"
#include "FoodAttributes.h"

namespace Domain {
    // Class that contains all information about the simple food (not composite)
    class SimpleFood final : public IFood {
    public:
        SimpleFood(quint64 id);
        SimpleFood(const SimpleFood& food);

        ~SimpleFood() override = default;

        quint64 getId() const override;

        void setFoodAttributes(const FoodAttributes& attributes) override;
        const FoodAttributes& getFoodAttributes() const override;

        std::shared_ptr<RecipeFood> getRecipe() override;

        std::shared_ptr<IFood> clone() const override;
        SimpleFood& operator=(const SimpleFood& food);

    private:
        quint64 id_ = 0;                // Unique identification number
        FoodAttributes attributes_;     // Attributes of this food
    };
} // namespace Domain