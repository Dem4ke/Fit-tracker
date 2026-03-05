set(LIBRARY_PUBLIC_HEADERS

)

set(LIBRARY_SOURCE_FILES

)

source_group(
  TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(FitTrackerServiceLib STATIC
    ${LIBRARY_SOURCE_FILES}
    ${LIBRARY_PUBLIC_HEADERS}
)

add_library(Fit::Service ALIAS FitTrackerServiceLib)

target_include_directories(FitTrackerServiceLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes>
    $<INSTALL_INTERFACE:include>

  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles
)

target_link_libraries(FitTrackerServiceLib
    PRIVATE

)
