#pragma once

#include "BodyMeasurements.h"
#include "SummaryNutrients.h"

#include <QtTypes>
#include <QDate>

namespace Domain {
    class Meal;

    // Class that contains all information about the day
    class Day final {
    public:
        Day(quint64 id, QDate date);
        Day(const Day& day);

        ~Day() = default;

        quint64 getId() const;
        const QDate& getDate() const;

        void setWater(int value);
        int getWater() const;

        void setWeight(float value);
        float getWeight() const;

        void setNote(const QString& note);
        const QString& getNote() const;

        void setBodyMeasurements(const BodyMeasurements& measurements);
        const BodyMeasurements& getBodyMeasurements() const;

        void setTargetNutrients(const SummaryNutrients& target);
        const SummaryNutrients& getTargetNutrients() const;

        void setMeals(const QVector<std::shared_ptr<Meal>>& meals);
        const QVector<std::shared_ptr<Meal>>& getMeals() const;

        std::shared_ptr<Day> clone() const;
        Day& operator=(const Day& day);

    private:
        quint64 id_ = 0;                        // Unique identification number
        int water_ = 0.0f;                      // Value of the drunk water in ml
        float weight_ = 0.0f;                   // Value of the measured weight in kg
        QDate date_;                            // Date of the day
        QString note_;                          // User notes of the day

        BodyMeasurements bodyMeasurements_;     // Body measurements at this day
        SummaryNutrients targetNutrients_;      // Target day nutrients
        QVector<std::shared_ptr<Meal>> meals_;  // Meals, that day contains
    };
} // namespace Domain