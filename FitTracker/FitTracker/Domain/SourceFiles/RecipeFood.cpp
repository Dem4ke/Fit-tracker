#include "Domain/RecipeFood.h"

namespace Domain {
    RecipeFood::RecipeFood(quint64 id)
        : id_(id) {}

    RecipeFood::RecipeFood(const RecipeFood& food)
        : id_(food.id_)
        , foodAttributes_(food.foodAttributes_)
        , recipeAttributes_(food.recipeAttributes_)
        , foods_(food.foods_) {}

    quint64 RecipeFood::getId() const {
        return id_;
    }

    void RecipeFood::setFoodAttributes(const FoodAttributes& attributes) {
        foodAttributes_ = attributes;
    }

    const FoodAttributes& RecipeFood::getFoodAttributes() const {
        return foodAttributes_;
    }

    std::shared_ptr<RecipeFood> RecipeFood::getRecipe() {
        return shared_from_this();
    }

    void RecipeFood::addFood(const std::shared_ptr<IFood>& food) {
        foods_.append(food);
    }

    void RecipeFood::removeFood(quint64 foodId) {
        int index = 0;

        for (auto& food : foods_) {
            if (food->getId() == foodId) {
                foods_.erase(foods_.cbegin() + index);
            }

            ++index;
        }
    }

    const std::shared_ptr<IFood>& RecipeFood::getFood(quint64 foodId) const {
        for (auto& food : foods_) {
            if (food->getId() == foodId) {
                return food;
            }
        }

        return nullptr;
    }

    void RecipeFood::setFoods(const QVector<std::shared_ptr<IFood>>& foods) {
        foods_ = foods;
    }

    const QVector<std::shared_ptr<IFood>>& RecipeFood::getFoods() const {
        return foods_;
    }

    void RecipeFood::setRecipeAttributes(const RecipeAttributes& attributes) {
        recipeAttributes_ = attributes;
    }

    const RecipeAttributes& RecipeFood::getRecipeAttributes() const {
        return recipeAttributes_;
    }

    std::shared_ptr<IFood> RecipeFood::clone() const {
        std::shared_ptr<RecipeFood> cloneRecipe = std::make_shared<RecipeFood>(*this);

        // It is a deep copy, so foods clone too
        QVector<std::shared_ptr<IFood>> foods;

        for (const auto& food : foods) {
            foods.append(food->clone());
        }

        cloneRecipe->setFoods(foods);
        return cloneRecipe;
    }

    RecipeFood& RecipeFood::operator=(const RecipeFood& food) {
        id_ = food.id_;
        foodAttributes_ = food.foodAttributes_;
        recipeAttributes_ = food.recipeAttributes_;
        foods_ = food.foods_;

        return *this;
    }
} // namespace Domain