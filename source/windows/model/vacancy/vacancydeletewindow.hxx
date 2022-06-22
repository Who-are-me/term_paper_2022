#pragma once

#include <QDialog>


namespace Ui { class VacancyDeleteWindow; }


class VacancyDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyDeleteWindow(QWidget *parent = nullptr);
    ~VacancyDeleteWindow();

    void setVacancyId(int new_id);
    void update();

private:
    Ui::VacancyDeleteWindow *ui;
    int id;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

