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

    void setResumeId(int new_id);
    void update();

private:
    Ui::ResumeDeleteWindow *ui;
    int id;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

#endif // RESUMEDELETEWINDOW_HXX
