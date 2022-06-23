#pragma once


#include <QDialog>

#include "models/resume.hxx"


namespace Ui { class ResumeCreateWindow; }


class ResumeCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeCreateWindow(QWidget *parent = nullptr);
    ~ResumeCreateWindow();

    Resume getObject();

private:
    Ui::ResumeCreateWindow *ui;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

