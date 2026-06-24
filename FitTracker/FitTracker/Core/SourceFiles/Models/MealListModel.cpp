#include "Core/Models/MealListModel.h"
#include "Core/Models/MealModel.h"

namespace Core {
    MealListModel::MealListModel(QObject* parent)
        : QAbstractListModel(parent) {}

    int MealListModel::rowCount(const QModelIndex& parent) const {
        if (parent.isValid()) {
            return 0;
        }

        return meals_.size();
    }

    QVariant MealListModel::data(const QModelIndex& index, int role) const {
        if (!index.isValid() || index.row() >= meals_.size()) {
            return QVariant();
        }

        MealModel* meal = meals_[index.row()].get();

        if (role == static_cast<int>(MLM::Roles::MealRole)) {
            return QVariant::fromValue(meal);
        }

        return QVariant();
    }

    QHash<int, QByteArray> MealListModel::roleNames() const {
        return {
            { static_cast<int>(MLM::Roles::MealRole), "meal" }
        };
    }

    void MealListModel::addMeal() {
        const int row = rowCount();

        beginInsertRows(QModelIndex(), row, row);

        meals_.append(std::make_shared<MealModel>());

        // TODO create some information setup

        endInsertRows();
    }

    void MealListModel::removeMeal(int row) {
        if (row < 0 || row >= rowCount()) {
            return;
        }

        beginRemoveRows(QModelIndex(), row, row);

        meals_.erase(meals_.begin() + row);

        endRemoveRows();
    }

    void MealListModel::setMeals(const QVector<std::shared_ptr<Domain::Meal>>& meals) {
        beginResetModel();

        meals_.clear();

        // Create new meals' models
        for (auto& meal : meals) {
            std::shared_ptr<MealModel> mealModel = std::make_shared<MealModel>();
            mealModel->setMeal(*meal);

            meals_.append(mealModel);
        }

        endResetModel();
    }
} // namespace Core