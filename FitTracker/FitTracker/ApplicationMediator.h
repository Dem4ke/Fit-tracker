#pragma once

#include <QQmlApplicationEngine>

namespace FitTracker {
    // Mediator class for Core and UI structures
    class ApplicationMediator final : public QObject {
    public:
        ApplicationMediator(QObject* parent, QQmlApplicationEngine& engine);

    private:
        QQmlApplicationEngine& engine_;     // QML engine for c++/qml integrations
    };
} // namespace FitTracker