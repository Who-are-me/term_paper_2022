#pragma once


#include <QDialog>
#include <QAbstractButton>

#include "models/account.hxx"


namespace Ui { class AccountCreateWindow; }


class AccountCreateWindow : public QDialog {
    Q_OBJECT

public:
    explicit AccountCreateWindow(QWidget *parent = nullptr);
    ~AccountCreateWindow();

    Account getObject();

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

private:
    Ui::AccountCreateWindow *ui;

signals:
    void pushOk();
    void pushCancel();
};

