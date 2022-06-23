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

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

#endif // RESUMEUPDATEWINDOW_HXX
