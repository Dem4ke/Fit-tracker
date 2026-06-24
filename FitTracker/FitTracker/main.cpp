#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "UI/MainPageViewModel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    UI::MainPageViewModel mainPage;

    engine.rootContext()->setContextProperty(
        "mainPage",
        &mainPage);

    engine.loadFromModule("FitTracker", "Main");

    return app.exec();
}
