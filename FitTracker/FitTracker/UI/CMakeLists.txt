set(LIBRARY_PUBLIC_HEADERS
    # View Models
    Includes/UI/MainPageViewModel.h
)

set(LIBRARY_SOURCE_FILES
    SourceFiles/MainPageViewModel.cpp
)

source_group(
  TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(FitTrackerUiLib STATIC
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(Fit::UI ALIAS FitTrackerUiLib)

target_include_directories(FitTrackerUiLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes>
    $<INSTALL_INTERFACE:include>

  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles
)

target_link_libraries(FitTrackerUiLib
    PRIVATE
        Qt6::Core

    PUBLIC
        Fit::Core
)
