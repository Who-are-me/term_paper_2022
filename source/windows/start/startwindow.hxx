#pragma once

#include <QMainWindow>
#include <QDebug>

#include "filter/filterwindow.hxx"
#include "authorization/authorizationwindow.hxx"

#define D_SW	qDebug() << "StartWindow: "


namespace Ui { class StartWindow; }


class StartWindow : public QMainWindow {
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private:
    Ui::StartWindow 	*ui;
    AuthorizationWindow *w_auth;
    FilterWindow		*w_filter;

    bool createWindowAuthorization();
    bool createWindowFilter();
    void configureWindowAuthorization();
    void configureWindowFilter();

private slots:
    void on_btn_login_released();
    void on_btn_filter_released();
};
