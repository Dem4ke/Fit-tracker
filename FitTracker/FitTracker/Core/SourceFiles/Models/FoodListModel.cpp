#include "Core/Models/FoodListModel.h"
#include "Core/Models/FoodModel.h"

namespace Core {
    FoodListModel::FoodListModel(QObject* parent)
        : QAbstractListModel(parent) {}

    int FoodListModel::rowCount(const QModelIndex& parent) const {
        if (parent.isValid()) {
            return 0;
        }

        return foods_.size();
    }

    QVariant FoodListModel::data(const QModelIndex& index, int role) const {
        if (!index.isValid() || index.row() >= foods_.size()) {
            return QVariant();
        }

        FoodModel* food = foods_[index.row()].get();

        if (role == static_cast<int>(FLM::Roles::FoodRole)) {
            return QVariant::fromValue(food);
        }

        return QVariant();
    }

    QHash<int, QByteArray> FoodListModel::roleNames() const {
        return {
            { static_cast<int>(FLM::Roles::FoodRole), "food" }
        };
    }

    // Create new food in application
    void FoodListModel::createFood(
        const QString& name,
        float fats,
        float proteins,
        float carbohydrates) {
        // TODO send request to the repository and data base to create new food
    }

    // Add chosen food from the list
    void FoodListModel::addFood(quint64 id) {
        // TODO send request to the repository to return a chosen food
    }

    void FoodListModel::removeFood(int row) {
        if (row < 0 || row >= rowCount()) {
            return;
        }

        beginRemoveRows(QModelIndex(), row, row);

        foods_.erase(foods_.begin() + row);

        endRemoveRows();
    }

    void FoodListModel::addFood(const std::shared_ptr<FoodModel>& food) {
        const int row = rowCount();
        beginRemoveRows(QModelIndex(), row, row);

        foods_.append(food);

        endInsertRows();
    }

    void FoodListModel::setFoods(const QVector<std::shared_ptr<Domain::IFood>>& foods) {
        beginResetModel();

        foods_.clear();

        // Create new foods' models
        for (auto& food : foods) {
            std::shared_ptr<FoodModel> foodModel = std::make_shared<FoodModel>();
            foodModel->setFood(food);

            foods_.append(foodModel);
        }

        endResetModel();
    }
} // namespace Core