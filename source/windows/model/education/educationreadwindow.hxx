#ifndef EDUCATIONREADWINDOW_HXX
#define EDUCATIONREADWINDOW_HXX

#include <QDialog>

namespace Ui {
class EducationReadWindow;
}

class EducationReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationReadWindow(QWidget *parent = nullptr);
    ~EducationReadWindow();

private:
    Ui::EducationReadWindow *ui;
};

#endif // EDUCATIONREADWINDOW_HXX
