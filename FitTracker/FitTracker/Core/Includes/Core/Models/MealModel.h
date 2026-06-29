#pragma once

#include "Core/Models/FoodListModel.h"

#include <QObject>

namespace Domain {
    class Meal;
} // namespace Domain

namespace Core {
    // Model class that describes a meal for a QML
    class MealModel final : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            QString name
            READ getName
            WRITE setName
            NOTIFY nameChanged)

        Q_PROPERTY(
            FoodListModel* foods
            READ getFoods
            CONSTANT)

    public:
        MealModel(QObject* parent = nullptr);
        ~MealModel() override = default;

        void setMeal(const Domain::Meal& meal);
        Domain::Meal getMeal() const;

        void setName(const QString& name);
        const QString& getName() const;

        FoodListModel* getFoods() const;

    signals:
        void nameChanged();
        void fatsChanged();
        void proteinsChanged();
        void carbohydratesChanged();

    private:
        QString name_;                          // Name of the meal
        FoodListModel* foods_ = nullptr;        // List of the foods' models
    };
} // namespace Core