#pragma once

#include <QObject>
#include <QDebug>

#include "start/startwindow.hxx"

// debug Application
#define D_APP	qDebug() << "Application: "


class Application : public QObject {
    Q_OBJECT

public:
    Application();
    ~Application();

    bool run();

private:
    StartWindow *w_start;

    bool init();

private slots:

};

