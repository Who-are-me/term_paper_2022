#pragma once

#include <QDialog>

#include "log.hxx"
#include "models/account.hxx"


namespace Ui { class AccountReadWindow; }


class AccountReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountReadWindow(QWidget *parent = nullptr);
    ~AccountReadWindow();

    void setObject(Account new_account);
    void update();

private:
    Ui::AccountReadWindow *ui;
    Account m_account;
};

