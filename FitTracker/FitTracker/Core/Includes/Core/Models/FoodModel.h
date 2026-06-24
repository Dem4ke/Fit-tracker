#pragma once

#include "Domain/FoodAttributes.h"

#include <QObject>

namespace Domain {
    class IFood;
} // namespace Domain

namespace Core {
    // Model class that describes food for a QML
    class FoodModel final : public QObject {
        Q_OBJECT

        Q_PROPERTY(
            QString name
            READ getName
            WRITE setName
            NOTIFY nameChanged)

        Q_PROPERTY(
            float fats
            READ getFats
            WRITE setFats
            NOTIFY fatsChanged)

        Q_PROPERTY(
            float proteins
            READ getProteins
            WRITE setProteins
            NOTIFY proteinsChanged)

        Q_PROPERTY(
            float carbohydrates
            READ getCarbohydrates
            WRITE setCarbohydrates
            NOTIFY carbohydratesChanged)

        Q_PROPERTY(
            float weight
            READ getWeight
            WRITE setWeight
            NOTIFY weightChanged)

    public:
        FoodModel(QObject* parent = nullptr);
        ~FoodModel() override = default;

        void setFood(const std::shared_ptr<Domain::IFood>& food);
        std::shared_ptr<Domain::IFood> getFood() const;

        // Properties' methods
        void setName(const QString& name);
        const QString& getName() const;

        void setFats(float value);
        float getFats() const;

        void setProteins(float value);
        float getProteins() const;

        void setCarbohydrates(float value);
        float getCarbohydrates() const;

        void setWeight(float value);
        float getWeight() const;

    signals:
        void nameChanged();
        void fatsChanged();
        void proteinsChanged();
        void carbohydratesChanged();
        void weightChanged();

    private:
        Domain::FoodAttributes foodAttributes_;     // Food that model describes
    };
} // namespace Core