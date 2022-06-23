#pragma once


#include <QDialog>

#include "models/education.hxx"


namespace Ui { class EducationCreateWindow; }


class EducationCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationCreateWindow(QWidget *parent = nullptr);
    ~EducationCreateWindow();

    Education getObject();

private:
    Ui::EducationCreateWindow *ui;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

