#pragma once

#include <QDialog>


namespace Ui { class RegisterWindow; }


// TODO register window, debug log
class RegisterWindow : public QDialog {
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    QString getPip();
    QString getCity();
    QString getLocation();
    QString getPhone();
    QString getEmail();
    QString getCompany();
    QString getDescription();
    QString getLogin();
    QString getPassword();

private:
    Ui::RegisterWindow *ui;

signals:
//    void showRegister();
    void backScreen();

private slots:
    void on_btn_back_released();
};

