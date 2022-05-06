cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME TermPaper)

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("Your build OS system ${CMAKE_HOST_SYSTEM_NAME}")

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_CXX_COMPILER "/bin/clang++")
    set(GCC_COVERAGE_COMPILE_FLAGS " -Ofast ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    message("Clang++ flags: ${CMAKE_CXX_FLAGS}")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS 	Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS 	Widgets Network)

set(PROJECT_SOURCES
    # sources
    source/main.cxx
    source/windows/startwindow/startwindow.cxx
    source/network/conector.cxx
    source/core/application.cxx
    source/database/database.cxx
    # headers
    source/windows/startwindow/startwindow.hxx
    source/network/conector.hxx
    source/core/application.hxx
    source/database/database.hxx
    # ui files
    source/windows/startwindow/startwindow.ui
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER storchak.vasil.app
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

target_include_directories(${PROJECT_NAME} PUBLIC source/windows)
