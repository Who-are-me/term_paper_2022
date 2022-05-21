cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME TermPaper)

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if(UNIX)
    set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast -Wall ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${GCC_COVERAGE_COMPILE_FLAGS}" )
endif(UNIX)

message("\nConfigure information:")
message("Path to autogen files: \t" ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include/)
message("Your build OS: \t\t${CMAKE_HOST_SYSTEM_NAME}")
message("C++ compile:  \t\t${CMAKE_CXX_COMPILER}")
message("Clang++ flags:\t\t${CMAKE_CXX_FLAGS}")
message("Qt version: \t\t${QT_VERSION_MAJOR}")
message("End indormation:\n")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS 	Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS 	Widgets Network)

set(PROJECT_SOURCES
    # SOURCES ###########################################################
    source/main.cxx
    # core
    source/core/application.cxx
    source/core/log.cxx
    # database
    source/database/database.cxx
    # network
    source/network/conector.cxx
    source/network/cookiesmanager.cxx
    source/network/dao/dao.cxx
    source/network/dao/networkdao.cxx
    source/network/dao/accountdao.cxx
    source/network/dao/educationdao.cxx
    source/network/dao/resumedao.cxx
    source/network/dao/vacancydao.cxx
    source/network/models/account.cxx
    source/network/models/education.cxx
    source/network/models/resume.cxx
    source/network/models/vacancy.cxx
    # windows
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
    # HEADERS ############################################################
    # core
    source/core/application.hxx
    source/core/log.hxx
    # database
    source/database/database.hxx
    # network
    source/network/conector.hxx
    source/network/cookiesmanager.hxx
    source/network/dao/dao.hxx
    source/network/dao/networkdao.hxx
    source/network/dao/accountdao.hxx
    source/network/dao/educationdao.hxx
    source/network/dao/resumedao.hxx
    source/network/dao/vacancydao.hxx
    source/network/models/account.hxx
    source/network/models/education.hxx
    source/network/models/resume.hxx
    source/network/models/vacancy.hxx
    # windows
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
    # UI FILES ############################################################
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
    # RESOURCE #############################################################
    resource.qrc
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
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include)




