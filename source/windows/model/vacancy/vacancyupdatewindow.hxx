#ifndef VACANCYUPDATEWINDOW_HXX
#define VACANCYUPDATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class VacancyUpdateWindow;
}

class VacancyUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyUpdateWindow(QWidget *parent = nullptr);
    ~VacancyUpdateWindow();

private:
    Ui::VacancyUpdateWindow *ui;
};

#endif // VACANCYUPDATEWINDOW_HXX
