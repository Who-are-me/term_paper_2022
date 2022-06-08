#pragma once

#include <QMainWindow>


namespace Ui {class ControlAllProfilesWindow;}


class ControlAllProfilesWindow : public QMainWindow {
    Q_OBJECT

public:
    ControlAllProfilesWindow(QWidget *parent = nullptr);
    ~ControlAllProfilesWindow();

private:
    Ui::ControlAllProfilesWindow *ui;
};

