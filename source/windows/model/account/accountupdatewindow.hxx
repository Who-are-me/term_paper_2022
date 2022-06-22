#pragma once

#include <QDialog>

#include "log.hxx"
#include "models/account.hxx"


namespace Ui { class AccountUpdateWindow; }


class AccountUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountUpdateWindow(QWidget *parent = nullptr);
    ~AccountUpdateWindow();

    void setObject(Account new_account);
    Account getObject();
    void update();

private:
    Ui::AccountUpdateWindow *ui;
    Account m_account;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

