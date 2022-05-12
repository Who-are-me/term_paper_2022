#include <QApplication>
#include <QDebug>
#include <QString>

#include "application.hxx"


int main(int argc, char *argv[]) {
    qDebug() << "App: this application will be started";

    QApplication app(argc, argv);
    Application application;
    int return_code = 0;

    application.run();

    return_code = app.exec();

    // FIXME `double free or corruption (fasttop)`
    qDebug() << "App: this application was finished return code: " + QString::number(return_code);

    return 0;
}
