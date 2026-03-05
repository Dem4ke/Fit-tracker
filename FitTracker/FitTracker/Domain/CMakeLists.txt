set(LIBRARY_PUBLIC_HEADERS
    Includes/Domain/Project.h
)

set(LIBRARY_SOURCE_FILES
    SourceFiles/Project.cpp
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

)
