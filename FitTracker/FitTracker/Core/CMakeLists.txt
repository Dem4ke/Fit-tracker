set(LIBRARY_PUBLIC_HEADERS
    Includes/Core/TableModel.h
)

set(LIBRARY_SOURCE_FILES
    SourceFiles/TableModel.cpp
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
        Qt6::Core
)
