#ifndef VACANCYREADWINDOW_HXX
#define VACANCYREADWINDOW_HXX

#include <QDialog>

namespace Ui {
class VacancyReadWindow;
}

class VacancyReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyReadWindow(QWidget *parent = nullptr);
    ~VacancyReadWindow();

private:
    Ui::VacancyReadWindow *ui;
};

#endif // VACANCYREADWINDOW_HXX
