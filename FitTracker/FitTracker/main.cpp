#include <QGuiApplication>
#include <Core/ProjectDirector.h>

#include "Core/ProjectDirector.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("FitTracker", "Main");

    Core::ProjectDirector projectDirector(engine);

    return app.exec();
}
