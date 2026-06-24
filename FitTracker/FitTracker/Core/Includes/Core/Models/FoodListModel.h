#pragma once

#include <QAbstractListModel>

namespace Domain {
    class IFood;
} // namespace Domain

// FoodListModel namespace
namespace FLM {
    // Roles, that model describes and support
    enum class Roles : int {
        FoodRole = Qt::UserRole + 1,
    };
} // namespace FLM

namespace Core {
    class FoodModel;

    // Model class that describes a list of foods for a QML
    class FoodListModel final : public QAbstractListModel {
        Q_OBJECT

    public:
        FoodListModel(QObject* parent = nullptr);
        ~FoodListModel() override = default;

        // QAbstractListModel methods
        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant data(const QModelIndex& index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        // Own methods
        Q_INVOKABLE void createFood(
            const QString& name,
            float fats,
            float proteins,
            float carbohydrates
        );
        Q_INVOKABLE void addFood(quint64 id);
        Q_INVOKABLE void removeFood(int row);

        void addFood(const std::shared_ptr<FoodModel>& food);
        void setFoods(const QVector<std::shared_ptr<Domain::IFood>>& foods);

    private:
        QVector<std::shared_ptr<FoodModel>> foods_;      // All foods, that list contains
    };
} // namespace Core