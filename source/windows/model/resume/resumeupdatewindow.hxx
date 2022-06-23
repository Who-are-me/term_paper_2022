#ifndef RESUMEUPDATEWINDOW_HXX
#define RESUMEUPDATEWINDOW_HXX

#include <QDialog>

#include "models/resume.hxx"

namespace Ui {
class ResumeUpdateWindow;
}

class ResumeUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeUpdateWindow(QWidget *parent = nullptr);
    ~ResumeUpdateWindow();

    void setObject(Resume new_object);
    Resume getObject();
    void update();

private:
    Ui::ResumeUpdateWindow *ui;
    Resume m_resume;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

#endif // RESUMEUPDATEWINDOW_HXX
