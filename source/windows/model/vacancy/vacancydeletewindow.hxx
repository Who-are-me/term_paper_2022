#ifndef VACANCYDELETEWINDOW_HXX
#define VACANCYDELETEWINDOW_HXX

#include <QDialog>

namespace Ui {
class VacancyDeleteWindow;
}

class VacancyDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyDeleteWindow(QWidget *parent = nullptr);
    ~VacancyDeleteWindow();

private:
    Ui::VacancyDeleteWindow *ui;
};

#endif // VACANCYDELETEWINDOW_HXX
