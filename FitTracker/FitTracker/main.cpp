#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <Core/TableModel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);


    Core::TableModel* model = new Core::TableModel();
    model->addColumn(std::make_shared<Core::Column>("Name"));
    model->addColumn(std::make_shared<Core::Column>("Proteins"));
    model->addColumn(std::make_shared<Core::Column>("Fats"));
    model->addColumn(std::make_shared<Core::Column>("Carbohydrates"));
    model->addColumn(std::make_shared<Core::Column>("Calories"));

    QVariantMap row1;
    row1.insert("id", 1);
    row1.insert("Name", "Breakfast");
    row1.insert("Proteins", 20);
    row1.insert("Fats", 5);
    row1.insert("Carbohydrates", 30);
    row1.insert("Calories", 150);
    model->addRow(row1);

    QVariantMap row2;
    row2.insert("id", 2);
    row2.insert("Name", "Chicken, 100 g");
    row2.insert("Proteins", 15);
    row2.insert("Fats", 1);
    row2.insert("Carbohydrates", 15);
    row2.insert("Calories", 100);
    model->addRow(row2);

    QVariantMap row3;
    row3.insert("id", 3);
    row3.insert("Name", "Kiwi, 50 g");
    row3.insert("Proteins", 5);
    row3.insert("Fats", 4);
    row3.insert("Carbohydrates", 15);
    row3.insert("Calories", 50);
    model->addRow(row3);

    engine.rootContext()->setContextProperty("tableModel", model);

    engine.loadFromModule("FitTracker", "Main");

    return app.exec();
}
