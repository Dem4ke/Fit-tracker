#include "Core/Repositories/DayRepository.h"
#include "Domain/Day.h"
#include "Domain/Meal.h"
#include "Domain/IFood.h"
#include "Domain/SimpleFood.h"
#include "Domain/FoodAttributes.h"

namespace Core {
    DayRepository::DayRepository() {
        // Creation of the simple test day
        QDate date(2026, 6, 25);

        day_ = std::make_shared<Domain::Day>(1, date);
        day_->setWater(1000);
        day_->setWeight(78.1);
        day_->setNote("That was a great day to work with my dad in the garage, i drunk so much water");

        QVector<std::shared_ptr<Domain::Meal>> meals;

        std::shared_ptr<Domain::Meal> meal1 = std::make_shared<Domain::Meal>(1);
        meal1->setName("Meal1");

        std::shared_ptr<Domain::SimpleFood> simpleFood1 = std::make_shared<Domain::SimpleFood>(1);
        Domain::FoodAttributes attributes1;
        attributes1.setName("Banana");
        attributes1.setFats(10.5);
        attributes1.setProteins(50.1);
        attributes1.setCarbohydrates(16.2);
        attributes1.setWeight(99.5);
        simpleFood1->setFoodAttributes(attributes1);

        meal1->addFood(simpleFood1);

        std::shared_ptr<Domain::Meal> meal2 = std::make_shared<Domain::Meal>(2);
        meal2->setName("Meal2");

        std::shared_ptr<Domain::SimpleFood> simpleFood2 = std::make_shared<Domain::SimpleFood>(2);
        Domain::FoodAttributes attributes2;
        attributes2.setName("Pie");
        attributes2.setFats(40.5);
        attributes2.setProteins(20.1);
        attributes2.setCarbohydrates(44.2);
        attributes2.setWeight(500);
        simpleFood2->setFoodAttributes(attributes2);

        meal2->addFood(simpleFood2);

        meals.append(meal1);
        meals.append(meal2);

        day_->setMeals(meals);
    }

    const std::shared_ptr<Domain::Day>& DayRepository::getDay() const {
        return day_;
    }
} // namespace Core