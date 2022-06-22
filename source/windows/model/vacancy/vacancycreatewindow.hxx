#pragma once


#include <QDialog>

#include "models/vacancy.hxx"


namespace Ui { class VacancyCreateWindow; }


class VacancyCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyCreateWindow(QWidget *parent = nullptr);
    ~VacancyCreateWindow();

    Vacancy getObject();

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

private:
    Ui::VacancyCreateWindow *ui;

signals:
    void pushOk();
    void pushCancel();
};

