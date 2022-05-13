#pragma once

#include <QMainWindow>


namespace Ui { class StartWindow; }


class StartWindow : public QMainWindow {
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private:
    Ui::StartWindow	*ui;

signals:
    void showAuth();
    void showFilter();

public slots:
    void on_btn_login_released();
    void on_btn_filter_released();
};
