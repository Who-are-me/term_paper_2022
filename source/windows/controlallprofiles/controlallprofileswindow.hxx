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

private slots:
    void on_btn_create_account_released();
    void on_btn_read_account_released();
    void on_btn_update_account_released();
    void on_btn_delete_account_released();

signals:
    void createAccount();
    void readAccount();
    void updateAccount();
    void deleteAccount();
};

