#include <QApplication>
#include <QDebug>

#include "application.hxx"


int main(int argc, char *argv[]) {
    qDebug() << "App: this application will be started";

    QApplication app(argc, argv);
    Application application;
    int return_code = 0;

    application.run();

    return_code = app.exec();

    qDebug() << "App: this application was finished";

    return return_code;
}
