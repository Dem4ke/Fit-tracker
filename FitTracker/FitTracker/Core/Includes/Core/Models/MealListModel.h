#pragma once

#include <QAbstractListModel>

namespace Domain {
    class Meal;
} // namespace Domain

// MealListModel namespace
namespace MLM {
    // Roles, that model describes and support
    enum class Roles : int {
        MealRole = Qt::UserRole + 1,
    };
} // namespace MLM

namespace Core {
    class MealModel;

    // Model class that describes a list of MealModels for a QML
    class MealListModel final : public QAbstractListModel {
        Q_OBJECT

    public:
        MealListModel(QObject* parent = nullptr);
        ~MealListModel() override = default;

        // QAbstractListModel methods
        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant data(const QModelIndex& index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        // Own methods
        Q_INVOKABLE void addMeal();
        Q_INVOKABLE void removeMeal(int row);

        void setMeals(const QVector<std::shared_ptr<Domain::Meal>>& meals);

    private:
        QVector<std::shared_ptr<MealModel>> meals_;     // All meals, that list contains
    };
} // namespace Core