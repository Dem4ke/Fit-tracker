#pragma once

#include <memory>
#include <QMap>
#include <QQmlApplicationEngine>

namespace Core {
    class TableModel;

    // Class mediator to set models to use them in QML GUI
    // It has reference to engine by a dependency injection
    class ProjectDirector {
    public:
        ProjectDirector(QQmlApplicationEngine& engine);

    private:
        QQmlApplicationEngine& engine_;                         // Engine of QML to set information in it
        QMap<QString, TableModel*> tables_;     // All table models that used in GUI
    };
}// namespace Core