#pragma once

#include <QtTypes>
#include <memory>

namespace Domain {
    class FoodAttributes;
    class RecipeFood;

    // Interface of a component food class
    class IFood {
    public:
        virtual ~IFood() = default;

        virtual quint64 getId() const = 0;
        virtual void setFoodAttributes(const FoodAttributes& attributes) = 0;
        virtual const FoodAttributes& getFoodAttributes() const = 0;
        virtual std::shared_ptr<RecipeFood> getRecipe() = 0;

        virtual std::shared_ptr<IFood> clone() const = 0;
    };
} // namespace Domain