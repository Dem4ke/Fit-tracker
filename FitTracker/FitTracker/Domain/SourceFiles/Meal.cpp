#include "Domain/Meal.h"

#include "Domain/FoodAttributes.h"
#include "Domain/IFood.h"

namespace Domain {
    Meal::Meal(quint64 id)
        : id_(id) {}

    Meal::Meal(const Meal& meal)
        : id_(meal.id_)
        , name_(meal.name_)
        , foods_(meal.foods_) {}

    quint64 Meal::getId() const {
        return id_;
    }

    void Meal::setName(const QString& name) {
        name_ = name;
    }

    const QString& Meal::getName() const {
        return name_;
    }

    // Calculate and return summary nutrients of a day
    SummaryNutrients Meal::getSummaryNutrients() const {
        float summFats = 0.0f;
        float summProteins = 0.0f;
        float summCarbohydrates = 0.0f;

        for (const auto& food : foods_) {
            summFats += food->getFoodAttributes().getFats();
            summProteins += food->getFoodAttributes().getProteins();
            summCarbohydrates += food->getFoodAttributes().getCarbohydrates();
        }

        SummaryNutrients summaryNutrients;
        summaryNutrients.setFats(summFats);
        summaryNutrients.setProteins(summProteins);
        summaryNutrients.setCarbohydrates(summCarbohydrates);

        return summaryNutrients;
    }

    void Meal::addFood(const std::shared_ptr<IFood>& food) {
        foods_.append(food);
    }

    void Meal::removeFood(quint64 foodId) {
        int index = 0;

        for (auto& food : foods_) {
            if (food->getId() == foodId) {
                foods_.erase(foods_.cbegin() + index);
            }

            ++index;
        }
    }

    const std::shared_ptr<IFood>& Meal::getFood(quint64 foodId) const {
        for (auto& food : foods_) {
            if (food->getId() == foodId) {
                return food;
            }
        }

        return nullptr;
    }

    void Meal::setFoods(const QVector<std::shared_ptr<IFood>>& foods) {
        foods_ = foods;
    }

    const QVector<std::shared_ptr<IFood>>& Meal::getFoods() const {
        return foods_;
    }

    std::shared_ptr<Meal> Meal::clone() const {
        std::shared_ptr<Meal> cloneMeal = std::make_shared<Meal>(*this);

        // It is a deep copy, so foods clone too
        QVector<std::shared_ptr<IFood>> foods;

        for (const auto& food : foods) {
            foods.append(food->clone());
        }

        cloneMeal->setFoods(foods);
        return cloneMeal;
    }

    Meal& Meal::operator=(const Meal& meal) {
        id_ = meal.id_;
        name_ = meal.name_;
        foods_ = meal.foods_;

        return *this;
    }

} // namespace Domain