#pragma once

#include <QMainWindow>


namespace Ui { class ControlCurrentProfilesWindow; }


class ControlCurrentProfilesWindow : public QMainWindow {
    Q_OBJECT

public:
    ControlCurrentProfilesWindow(QWidget *parent = nullptr);
    ~ControlCurrentProfilesWindow();

private:
    Ui::ControlCurrentProfilesWindow *ui;
};

