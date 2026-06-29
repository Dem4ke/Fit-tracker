#pragma once

#include <QAbstractListModel>
#include <QDate>

// WeekListModel namespace
namespace WLM {
    // Roles, that model describes and support
    enum class Roles : int {
        DateRole = Qt::UserRole + 1,    // Date description
        DayNameRole,                    // Name of the day
    };
} // namespace WLM

namespace Core {
    // Model class that describes a list of days (a week) for a QML
    class WeekListModel final : public QAbstractListModel {
        Q_OBJECT

    public:
        WeekListModel(QObject* parent = nullptr);
        ~WeekListModel() override = default;

        // QAbstractListModel methods
        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant data(const QModelIndex& index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        // Own methods
        Q_INVOKABLE void nextRow();
        Q_INVOKABLE void previousRow();

    private:
        int shownDaysCount_ = 7;    // A week days count
        QDate weekStartDate_;       // Start date of the shown week (week's monday)
    };
} // namespace Core