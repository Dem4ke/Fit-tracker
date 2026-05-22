#include <Core/ProjectDirector.h>
#include <Core/TableModel.h>
#include <QQmlContext>

namespace Core {
    ProjectDirector::ProjectDirector(QQmlApplicationEngine& engine)
        : engine_(engine) {
        // Get data from database

        // Create models

        // Send models to GUI viewer (engine)
        TableModel* model = new TableModel();
        model->addColumn(std::make_shared<Core::Column>("Name"));
        model->addColumn(std::make_shared<Core::Column>("Proteins"));
        model->addColumn(std::make_shared<Core::Column>("Fats"));
        model->addColumn(std::make_shared<Core::Column>("Carbohydrates"));
        model->addColumn(std::make_shared<Core::Column>("Calories"));
        model->addRole("Meal");

        QVariantMap row1;
        row1.insert("id", 0);
        row1.insert("Meal", 1);
        row1.insert("Name", "Breakfast");
        row1.insert("Proteins", 20);
        row1.insert("Fats", 5);
        row1.insert("Carbohydrates", 30);
        row1.insert("Calories", 150);
        model->addRow(row1);

        QVariantMap row2;
        row2.insert("id", 1);
        row2.insert("Meal", 2);
        row2.insert("Name", "Chicken, 100 g");
        row2.insert("Proteins", 15);
        row2.insert("Fats", 1);
        row2.insert("Carbohydrates", 15);
        row2.insert("Calories", 100);
        model->addRow(row2);

        QVariantMap row3;
        row3.insert("id", 2);
        row3.insert("Meal", 3);
        row3.insert("Name", "Kiwi, 50 g");
        row3.insert("Proteins", 5);
        row3.insert("Fats", 4);
        row3.insert("Carbohydrates", 15);
        row3.insert("Calories", 50);
        model->addRow(row3);

        engine_.rootContext()->setContextProperty("tableModel", model);
    }

}// namespace Core