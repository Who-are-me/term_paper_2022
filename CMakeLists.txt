cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME TermPaper)

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

# set Qt SDK
set(CMAKE_PREFIX_PATH /opt/qt/5.15.2/gcc_64)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("Path to autogen files " ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include/)
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
    source/core/application.cxx
    source/database/database.cxx
    source/network/conector.cxx
    source/windows/start/startwindow.cxx
    source/windows/authorization/authorizationwindow.cxx
    source/windows/owerviewuser/owerviewuserwindow.cxx
    source/windows/owerviewadmin/owerviewadminwindow.cxx
    source/windows/filter/filterwindow.cxx
    source/windows/controlcurrentprofiles/controlcurrentprofileswindow.cxx
    source/windows/controlallprofiles/controlallprofileswindow.cxx
    source/windows/exposeitem/exposeitemwindow.cxx
    source/windows/removeitem/removeitemwindow.cxx
    source/windows/updateitem/updateitemwindow.cxx
    source/windows/createitem/createitemwindow.cxx
    source/windows/authorization/register/registerwindow.cxx
    # headers
    source/core/application.hxx
    source/database/database.hxx
    source/network/conector.hxx
    source/windows/start/startwindow.hxx
    source/windows/authorization/authorizationwindow.hxx
    source/windows/owerviewuser/owerviewuserwindow.hxx
    source/windows/owerviewadmin/owerviewadminwindow.hxx
    source/windows/filter/filterwindow.hxx
    source/windows/controlcurrentprofiles/controlcurrentprofileswindow.hxx
    source/windows/controlallprofiles/controlallprofileswindow.hxx
    source/windows/exposeitem/exposeitemwindow.hxx
    source/windows/removeitem/removeitemwindow.hxx
    source/windows/updateitem/updateitemwindow.hxx
    source/windows/createitem/createitemwindow.hxx
    source/windows/authorization/register/registerwindow.hxx
    # ui files
    source/windows/start/startwindow.ui
    source/windows/authorization/authorizationwindow.ui
    source/windows/owerviewuser/owerviewuserwindow.ui
    source/windows/owerviewadmin/owerviewadminwindow.ui
    source/windows/filter/filterwindow.ui
    source/windows/controlcurrentprofiles/controlcurrentprofileswindow.ui
    source/windows/controlallprofiles/controlallprofileswindow.ui
    source/windows/exposeitem/exposeitemwindow.ui
    source/windows/removeitem/removeitemwindow.ui
    source/windows/updateitem/updateitemwindow.ui
    source/windows/createitem/createitemwindow.ui
    source/windows/authorization/register/registerwindow.ui
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

target_include_directories(${PROJECT_NAME} PUBLIC source/core)
target_include_directories(${PROJECT_NAME} PUBLIC source/database)
target_include_directories(${PROJECT_NAME} PUBLIC source/network)
target_include_directories(${PROJECT_NAME} PUBLIC source/windows)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/)




