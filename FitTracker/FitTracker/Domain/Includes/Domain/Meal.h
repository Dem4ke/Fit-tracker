#pragma once

#include "SummaryNutrients.h"

#include <QString>
#include <QVector>
#include <QtTypes>

namespace Domain {
    class IFood;

    // Class that contains all information about the meal
    class Meal final {
    public:
        Meal(quint64 id);
        Meal(const Meal& meal);

        ~Meal() = default;

        quint64 getId() const;

        void setName(const QString& name);
        const QString& getName() const;

        SummaryNutrients getSummaryNutrients() const;

        void addFood(const std::shared_ptr<IFood>& food);
        void removeFood(quint64 foodId);
        const std::shared_ptr<IFood>& getFood(quint64 foodId) const;

        void setFoods(const QVector<std::shared_ptr<IFood>>& foods);
        const QVector<std::shared_ptr<IFood>>& getFoods() const;

        std::shared_ptr<Meal> clone() const;
        Meal& operator=(const Meal& meal);

    private:
        quint64 id_ = 0;                        // Unique identification number
        QString name_;                          // Name of the meal

        QVector<std::shared_ptr<IFood>> foods_; // Food, that meal contains
    };
} // namespace Domain