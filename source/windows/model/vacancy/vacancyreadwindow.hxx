#pragma once

#include <QDialog>

#include "models/vacancy.hxx"


namespace Ui { class VacancyReadWindow; }


class VacancyReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyReadWindow(QWidget *parent = nullptr);
    ~VacancyReadWindow();

    void setObject(Vacancy new_vacancy);
    void update();

private:
    Ui::VacancyReadWindow *ui;
    Vacancy m_vacancy;
};

