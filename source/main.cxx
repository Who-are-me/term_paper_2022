#include <QApplication>
#include <QDebug>
#include <QString>


#include "application.hxx"
#include "log.hxx"


#define PATH_TO_STYLE "./resource/style/Yashi.qss"


int main(int argc, char *argv[]) {
    Log::info("App: this application will be started");

    QApplication q_app(argc, argv);
    Application application;
    int return_code = 0;

    q_app.setStyleSheet(application.loadStyle(PATH_TO_STYLE));
    application.run();

    return_code = q_app.exec();

    Log::info("App: this application was finished with return code: " + QString::number(return_code));

    return 0;
}


// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to-do fix list
// FIXED fix crashed program then is close
// FIXME fix save and load cookie from disk
// FIXME fix qt style for mac and fix qt style for QTableView
// TODO remake this windows =>
// 		source/windows/exposeitem/exposeitemwindow.cxx
//    	source/windows/removeitem/removeitemwindow.cxx
//    	source/windows/updateitem/updateitemwindow.cxx
//    	source/windows/createitem/createitemwindow.cxx
// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
