cmake_minimum_required(VERSION 3.16)

project(FitTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
        Core
        Quick
)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(${PROJECT_NAME}
    FitTracker/main.cpp
    FitTracker/ApplicationMediator.h
    FitTracker/ApplicationMediator.cpp
)

qt_add_qml_module(${PROJECT_NAME}
        URI ${PROJECT_NAME}
        QML_FILES
        FitTracker/UI/QML/Main.qml
        FitTracker/UI/QML/MainPage.qml
        FitTracker/UI/QML/WeightPage.qml
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# Hide console with Release version
set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE $<NOT:$<CONFIG:Debug>>
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Quick
        Qt6::Qml
        Fit::UI
        Fit::Domain
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#add_subdirectory(Tests)
add_subdirectory(FitTracker/Service)
add_subdirectory(FitTracker/Domain)
add_subdirectory(FitTracker/Core)
add_subdirectory(FitTracker/UI)

if (WIN32)
    # Find windeployqt inside Qt installation
    get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    add_custom_command(TARGET ${PROJECT_NAME}
            POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}"
            --no-translations
            --qmldir "${CMAKE_SOURCE_DIR}"
            "$<TARGET_FILE:${PROJECT_NAME}>"
            COMMENT "Running windeployqt..."
    )
endif()