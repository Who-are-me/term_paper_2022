#ifndef EDUCATIONUPDATEWINDOW_HXX
#define EDUCATIONUPDATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class EducationUpdateWindow;
}

class EducationUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationUpdateWindow(QWidget *parent = nullptr);
    ~EducationUpdateWindow();

private:
    Ui::EducationUpdateWindow *ui;
};

#endif // EDUCATIONUPDATEWINDOW_HXX
