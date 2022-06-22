#pragma once

#include <QDialog>


namespace Ui { class AccountDeleteWindow; }


class AccountDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDeleteWindow(QWidget *parent = nullptr);
    ~AccountDeleteWindow();

    void setLogin(QString new_login);
    void update();

private:
    Ui::AccountDeleteWindow *ui;
    QString login;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

