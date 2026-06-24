#include "Domain/SimpleFood.h"

namespace Domain {
    SimpleFood::SimpleFood(quint64 id)
        : id_(id) {}

    SimpleFood::SimpleFood(const SimpleFood& food)
        : id_(food.id_)
        , attributes_(food.attributes_) {}

    quint64 SimpleFood::getId() const {
        return id_;
    }

    void SimpleFood::setFoodAttributes(const FoodAttributes& attributes) {
        attributes_ = attributes;
    }

    const FoodAttributes& SimpleFood::getFoodAttributes() const {
        return attributes_;
    }

    // That class specify a simple food, so it cannot be cast to the recipe
    std::shared_ptr<RecipeFood> SimpleFood::getRecipe() {
        return nullptr;
    }

    std::shared_ptr<IFood> SimpleFood::clone() const {
        return std::make_shared<SimpleFood>(*this);
    }

    SimpleFood& SimpleFood::operator=(const SimpleFood& food) {
        id_ = food.id_;
        attributes_ = food.attributes_;

        return *this;
    }
} // namespace Domain