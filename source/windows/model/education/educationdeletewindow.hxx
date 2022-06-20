#ifndef EDUCATIONDELETEWINDOW_HXX
#define EDUCATIONDELETEWINDOW_HXX

#include <QDialog>

namespace Ui {
class EducationDeleteWindow;
}

class EducationDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationDeleteWindow(QWidget *parent = nullptr);
    ~EducationDeleteWindow();

private:
    Ui::EducationDeleteWindow *ui;
};

#endif // EDUCATIONDELETEWINDOW_HXX
