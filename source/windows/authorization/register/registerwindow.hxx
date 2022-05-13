#pragma once

#include <QDialog>


namespace Ui { class RegisterWindow; }


// TODO register window, debug log
class RegisterWindow : public QDialog {
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private:
    Ui::RegisterWindow *ui;

signals:
//    void showRegister();

private slots:
};

