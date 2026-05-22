#pragma once

#include <QAbstractTableModel>

namespace Core {
    // Interface of the column of the database table
    class IColumn {
    public:
        virtual ~IColumn() = default;

        virtual const QString& getName() const = 0;
        virtual QVariant getData(const QVariantMap& rowData, int role = Qt::DisplayRole) = 0;
    };

    // Standard column of table
    class Column final : public IColumn {
    public:
        Column(const QString& name);
        ~Column() = default;

        const QString& getName() const override;
        QVariant getData(const QVariantMap& rowData, int role = Qt::DisplayRole) override;
    private:
        QString name_;  // Name of the column
    };

    // Table model for database table representation
    /* model contains:
     * 1 - data of all rows as QHash with int key which represents row index of table
     * and QVariantMap as a row data (QVariantMap is QMap<QString, QVariant>)
     * 2 - array of interfaces that represent columns with its names
     */
    class TableModel final : public QAbstractTableModel {
        Q_OBJECT
    public:
        TableModel(QObject* parent = nullptr);
        ~TableModel() = default;

        // QAbstractTableModel methods
        int rowCount(const QModelIndex& parent) const override;
        int columnCount(const QModelIndex& parent) const override;
        QVariant data(const QModelIndex& index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        void addRow(const QVariantMap& rowData);
        void addColumn(const std::shared_ptr<IColumn> column);
        void addRole(const QString& role);

    private:
        QHash<int, QVariantMap> data_;                  // Data from database key is a row index, value is a row data
        QVector<std::shared_ptr<IColumn>> columns_;     // Columns of data table
        QVector<QString> roles_;                        // Roles that used as filters (they added after column roles)
    };
} // namespace Core