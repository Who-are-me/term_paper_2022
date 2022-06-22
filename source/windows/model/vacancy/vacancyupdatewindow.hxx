#pragma once

#include <QDialog>

#include "models/vacancy.hxx"


namespace Ui { class VacancyUpdateWindow; }


class VacancyUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyUpdateWindow(QWidget *parent = nullptr);
    ~VacancyUpdateWindow();

    void setObject(Vacancy new_vacancy);
    Vacancy getObject();
    void update();

private:
    Ui::VacancyUpdateWindow *ui;
    Vacancy m_vacancy;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

