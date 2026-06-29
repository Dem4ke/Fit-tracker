#include "Domain/Day.h"
#include "Domain/Meal.h"

namespace Domain {
    Day::Day(quint64 id, QDate date)
        : id_(id)
        , date_(date) {}

    Day::Day(const Day& day)
        : id_(day.id_)
        , water_(day.water_)
        , weight_(day.weight_)
        , date_(day.date_)
        , note_(day.note_)
        , bodyMeasurements_(day.bodyMeasurements_)
        , targetNutrients_(day.targetNutrients_)
        , meals_(day.meals_) {}

    quint64 Day::getId() const {
        return id_;
    }

    const QDate& Day::getDate() const {
        return date_;
    }

    void Day::setWater(int value) {
        water_ = value;
    }

    int Day::getWater() const {
        return water_;
    }

    void Day::setWeight(float value) {
        weight_ = value;
    }

    float Day::getWeight() const {
        return weight_;
    }

    void Day::setNote(const QString& note) {
        note_ = note;
    }

    const QString& Day::getNote() const {
        return note_;
    }

    void Day::setBodyMeasurements(const BodyMeasurements& measurements) {
        bodyMeasurements_ = measurements;
    }

    const BodyMeasurements& Day::getBodyMeasurements() const {
        return bodyMeasurements_;
    }

    void Day::setTargetNutrients(const SummaryNutrients& target) {
        targetNutrients_ = target;
    }

    const SummaryNutrients& Day::getTargetNutrients() const {
        return targetNutrients_;
    }

    void Day::setMeals(const QVector<std::shared_ptr<Meal>>& meals) {
        meals_ = meals;
    }

    const QVector<std::shared_ptr<Meal>>& Day::getMeals() const {
        return meals_;
    }

    std::shared_ptr<Day> Day::clone() const {
        std::shared_ptr<Day> cloneDay = std::make_shared<Day>(*this);

        // It is a deep copy, so meals clone too
        QVector<std::shared_ptr<Meal>> meals;

        for (const auto& meal : meals_) {
            meals.append(meal->clone());
        }

        cloneDay->setMeals(meals);
        return cloneDay;
    }

    Day& Day::operator=(const Day& day) {
        id_ = day.id_;
        water_ = day.water_;
        weight_ = day.weight_;
        date_ = day.date_;
        note_ = day.note_;
        bodyMeasurements_ = day.bodyMeasurements_;
        targetNutrients_ = day.targetNutrients_;
        meals_ = day.meals_;

        return *this;
    }
} // namespace Domain