#pragma once

#include "IFood.h"
#include "FoodAttributes.h"
#include "RecipeAttributes.h"

#include <QVector>

namespace Domain {
    // Class that contains all information about the recipe food (composite)
    class RecipeFood final : public IFood, public std::enable_shared_from_this<RecipeFood> {
    public:
        RecipeFood(quint64 id);
        RecipeFood(const RecipeFood& food);

        ~RecipeFood() override = default;

        // IFood's methods
        quint64 getId() const override;

        void setFoodAttributes(const FoodAttributes& attributes) override;
        const FoodAttributes& getFoodAttributes() const override;

        std::shared_ptr<RecipeFood> getRecipe() override;

        // Own methods
        void addFood(const std::shared_ptr<IFood>& food);
        void removeFood(quint64 foodId);
        const std::shared_ptr<IFood>& getFood(quint64 foodId) const;

        void setFoods(const QVector<std::shared_ptr<IFood>>& foods);
        const QVector<std::shared_ptr<IFood>>& getFoods() const;

        void setRecipeAttributes(const RecipeAttributes& attributes);
        const RecipeAttributes& getRecipeAttributes() const;

        std::shared_ptr<IFood> clone() const override;
        RecipeFood& operator=(const RecipeFood& food);

    private:
        quint64 id_ = 0;                        // Unique identification number
        FoodAttributes foodAttributes_;         // Summary attributes of all contained foods
        RecipeAttributes recipeAttributes_;     // Attributes of this recipe

        QVector<std::shared_ptr<IFood>> foods_; // Food, that recipe contains
    };
} // namespace Domain