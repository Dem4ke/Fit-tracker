set(LIBRARY_PUBLIC_HEADERS
    # Interfaces
    Includes/Domain/IFood.h

    # Real objects
    Includes/Domain/Day.h
    Includes/Domain/BodyMeasurements.h
    Includes/Domain/SummaryNutrients.h
    Includes/Domain/Meal.h
    Includes/Domain/SimpleFood.h
    Includes/Domain/RecipeFood.h
    Includes/Domain/FoodAttributes.h
    Includes/Domain/RecipeAttributes.h
)

set(LIBRARY_SOURCE_FILES
    SourceFiles/Day.cpp
    SourceFiles/BodyMeasurements.cpp
    SourceFiles/SummaryNutrients.cpp
    SourceFiles/Meal.cpp
    SourceFiles/SimpleFood.cpp
    SourceFiles/RecipeFood.cpp
    SourceFiles/FoodAttributes.cpp
    SourceFiles/RecipeAttributes.cpp
)

source_group(
  TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(FitTrackerDomainLib STATIC
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(Fit::Domain ALIAS FitTrackerDomainLib)

target_include_directories(FitTrackerDomainLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes>
    $<INSTALL_INTERFACE:include>

  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles
)

target_link_libraries(FitTrackerDomainLib
    PRIVATE
        Qt6::Core
)
