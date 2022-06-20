#pragma once


#include <QMainWindow>


namespace Ui { class FilterWindow; }


class FilterWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = nullptr);
    ~FilterWindow();

private:
    Ui::FilterWindow *ui;
};

