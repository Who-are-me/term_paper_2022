#ifndef VACANCYCREATEWINDOW_HXX
#define VACANCYCREATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class VacancyCreateWindow;
}

class VacancyCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyCreateWindow(QWidget *parent = nullptr);
    ~VacancyCreateWindow();

private:
    Ui::VacancyCreateWindow *ui;
};

#endif // VACANCYCREATEWINDOW_HXX
