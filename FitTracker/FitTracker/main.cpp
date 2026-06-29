#include <QGuiApplication>
#include "ApplicationMediator.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    FitTracker::ApplicationMediator appMediator(nullptr, engine);

    return app.exec();
}
