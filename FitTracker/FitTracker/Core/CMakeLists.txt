set(LIBRARY_PUBLIC_HEADERS
    # Models
    Includes/Core/Models/DayModel.h
    Includes/Core/Models/MealModel.h
    Includes/Core/Models/FoodModel.h
    Includes/Core/Models/MealListModel.h
    Includes/Core/Models/FoodListModel.h
    Includes/Core/Models/WeekListModel.h

    # Repositories
    Includes/Core/Repositories/DayRepository.h
    Includes/Core/Repositories/MealRepository.h
    Includes/Core/Repositories/FoodRepository.h
)

set(LIBRARY_SOURCE_FILES
    # Models
    SourceFiles/Models/DayModel.cpp
    SourceFiles/Models/MealModel.cpp
    SourceFiles/Models/FoodModel.cpp
    SourceFiles/Models/MealListModel.cpp
    SourceFiles/Models/FoodListModel.cpp
    SourceFiles/Models/WeekListModel.cpp

    # Repositories
    SourceFiles/Repositories/DayRepository.cpp
    SourceFiles/Repositories/MealRepository.cpp
    SourceFiles/Repositories/FoodRepository.cpp
)

source_group(
  TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(FitTrackerCoreLib STATIC
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(Fit::Core ALIAS FitTrackerCoreLib)

target_include_directories(FitTrackerCoreLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes>
    $<INSTALL_INTERFACE:include>

  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles
)

target_link_libraries(FitTrackerCoreLib
    PRIVATE
        Qt6::Quick
        Qt6::Core
        Fit::Domain
)
