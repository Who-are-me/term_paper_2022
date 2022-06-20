#ifndef RESUMECREATEWINDOW_HXX
#define RESUMECREATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class ResumeCreateWindow;
}

class ResumeCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeCreateWindow(QWidget *parent = nullptr);
    ~ResumeCreateWindow();

private:
    Ui::ResumeCreateWindow *ui;
};

#endif // RESUMECREATEWINDOW_HXX
