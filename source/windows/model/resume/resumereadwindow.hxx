#ifndef RESUMEREADWINDOW_HXX
#define RESUMEREADWINDOW_HXX

#include <QDialog>

namespace Ui {
class ResumeReadWindow;
}

class ResumeReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeReadWindow(QWidget *parent = nullptr);
    ~ResumeReadWindow();

private:
    Ui::ResumeReadWindow *ui;
};

#endif // RESUMEREADWINDOW_HXX
