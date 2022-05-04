#include <QApplication>

#include "startwindow/startwindow.hxx"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    StartWindow start_window;

    start_window.show();
    start_window.setWindowTitle("Storchak Vasil");
    start_window.resize(320, 320);

    return app.exec();
}
