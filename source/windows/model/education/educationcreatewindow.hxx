#ifndef EDUCATIONCREATEWINDOW_HXX
#define EDUCATIONCREATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class EducationCreateWindow;
}

class EducationCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationCreateWindow(QWidget *parent = nullptr);
    ~EducationCreateWindow();

private:
    Ui::EducationCreateWindow *ui;
};

#endif // EDUCATIONCREATEWINDOW_HXX
