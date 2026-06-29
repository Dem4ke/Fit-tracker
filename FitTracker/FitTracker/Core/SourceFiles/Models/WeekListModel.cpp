#include "Core/Models/WeekListModel.h"

namespace Core {
    WeekListModel::WeekListModel(QObject* parent)
        : QAbstractListModel(parent) {
        // Start with current week
        QDate today = QDate::currentDate();

        weekStartDate_ = today.addDays(-(today.dayOfWeek() - 1));
    }

    int WeekListModel::rowCount(const QModelIndex& parent) const {
        if (parent.isValid()) {
            return 0;
        }

        return shownDaysCount_;
    }

    QVariant WeekListModel::data(const QModelIndex& index, int role) const {
        if (!index.isValid() || index.row() >= shownDaysCount_) {
            return QVariant();
        }

        QDate chosenDate = weekStartDate_.addDays(index.row());

        switch (role) {
        case static_cast<int>(WLM::Roles::DateRole): {
            return chosenDate;
        }
        case static_cast<int>(WLM::Roles::DayNameRole): {
            return chosenDate.toString("ddd");
        }
        }

        return QVariant();
    }

    QHash<int, QByteArray> WeekListModel::roleNames() const {
        return {
            { static_cast<int>(WLM::Roles::DateRole), "date" },
            { static_cast<int>(WLM::Roles::DayNameRole), "dayName" }
        };
    }

    void WeekListModel::nextRow() {
        weekStartDate_ = weekStartDate_.addDays(shownDaysCount_);
        emit dataChanged(index(0), index(shownDaysCount_ - 1));
    }

    void WeekListModel::previousRow() {
        weekStartDate_ = weekStartDate_.addDays(-shownDaysCount_);
        emit dataChanged(index(0), index(shownDaysCount_ - 1));
    }
} // namespace Core