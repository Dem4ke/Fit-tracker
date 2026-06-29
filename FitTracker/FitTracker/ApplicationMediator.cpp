#include "ApplicationMediator.h"

#include "UI/MainPageViewModel.h"
#include "Core/Repositories/DayRepository.h"

#include <QQmlContext>

namespace FitTracker {
    ApplicationMediator::ApplicationMediator(QObject* parent, QQmlApplicationEngine& engine)
        : QObject(parent)
        , engine_(engine) {

        // Load and setup QML elements
        UI::MainPageViewModel* mainPage = new UI::MainPageViewModel(this);

        engine.rootContext()->setContextProperty(
            "mainPage",
            mainPage);

        // Load data from database to repository
        Core::DayRepository dayRepository;

        // Setup startup day element
        std::shared_ptr<Core::DayModel> dayModel = std::make_shared<Core::DayModel>();
        dayModel->setDay(*dayRepository.getDay());

        mainPage->setDisplayedDay(dayModel);

        engine.loadFromModule("FitTracker", "Main");

        //connect(mainPage, &UI::MainPageViewModel::dayChangeRequest);
    }
} // namespace FitTracker