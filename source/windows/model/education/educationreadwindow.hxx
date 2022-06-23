#pragma once

#include <QDialog>

#include "models/education.hxx"


namespace Ui { class EducationReadWindow; }


class EducationReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationReadWindow(QWidget *parent = nullptr);
    ~EducationReadWindow();

    void setObject(Education new_vacancy);
    void update();

private:
    Ui::EducationReadWindow *ui;
    Education m_education;
};

