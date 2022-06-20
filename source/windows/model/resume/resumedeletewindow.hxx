#ifndef RESUMEDELETEWINDOW_HXX
#define RESUMEDELETEWINDOW_HXX

#include <QDialog>

namespace Ui {
class ResumeDeleteWindow;
}

class ResumeDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeDeleteWindow(QWidget *parent = nullptr);
    ~ResumeDeleteWindow();

private:
    Ui::ResumeDeleteWindow *ui;
};

#endif // RESUMEDELETEWINDOW_HXX
