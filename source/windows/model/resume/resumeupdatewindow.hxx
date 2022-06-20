#ifndef RESUMEUPDATEWINDOW_HXX
#define RESUMEUPDATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class ResumeUpdateWindow;
}

class ResumeUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeUpdateWindow(QWidget *parent = nullptr);
    ~ResumeUpdateWindow();

private:
    Ui::ResumeUpdateWindow *ui;
};

#endif // RESUMEUPDATEWINDOW_HXX
