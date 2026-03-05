#include <Core/TableModel.h>

namespace Core {
    //-----------------------------------------------------------------
    // COLUMN

    // Default constructor
    Column::Column(const QString& name)
        : name_(name) {}

    // Getter for a name of column
    const QString& Column::getName() const {
        return name_;
    }

    // Data extraction from row
    QVariant Column::getData(const QVariantMap& rowData, int role) {
        return rowData.value(getName());
    }

    //-----------------------------------------------------------------
    // TABLE MODEL
    TableModel::TableModel(QObject* parent)
        : QAbstractTableModel(parent) {}

    int TableModel::rowCount(const QModelIndex& parent) const {
        return data_.count();
    }

    int TableModel::columnCount(const QModelIndex& parent) const {
        return columns_.count();
    }

    // Get data from model by its role
    QVariant TableModel::data(const QModelIndex& index, int role) const {
        if (!index.isValid()) {
            return QVariant();
        }

        // Set column of index
        int column = index.column();

        // If it's a new role, column calculates to a valid value
        if (role > Qt::UserRole) {
            column = role - Qt::UserRole;
        }

        // Temporary role sets as display
        role = Qt::DisplayRole;

        // Get row from data
        QVariantMap rowData = data_.value(index.row());

        // Return data
        return columns_.at(column)->getData(rowData, role);
    }

    // Get role names from model
    QHash<int, QByteArray> TableModel::roleNames() const {
        // Set default roles
        QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();

        // Set started role by first available role
        int role = Qt::UserRole + 1;

        // Add new roles by columns
        for (auto& col : columns_) {
            roles.insert(role, col->getName().toUtf8());
            ++role;
        }

        return roles;
    }

    // Add new row
    void TableModel::addRow(const QVariantMap& rowData) {
        int id = rowData.value("id").toInt();

        beginInsertRows(QModelIndex(), data_.count(), data_.count());
        data_.insert(id, rowData);
        endInsertRows();
    }

    // Add new column
    void TableModel::addColumn(const std::shared_ptr<IColumn> column) {
        columns_.push_back(column);
    }
} // namespace Core