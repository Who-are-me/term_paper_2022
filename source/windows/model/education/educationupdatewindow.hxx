#ifndef EDUCATIONUPDATEWINDOW_HXX
#define EDUCATIONUPDATEWINDOW_HXX

#include <QDialog>

#include "models/education.hxx"

namespace Ui {
class EducationUpdateWindow;
}

class EducationUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EducationUpdateWindow(QWidget *parent = nullptr);
    ~EducationUpdateWindow();

    void setObject(Education new_vacancy);
    Education getObject();
    void update();

private:
    Ui::EducationUpdateWindow *ui;
    Education m_education;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

#endif // EDUCATIONUPDATEWINDOW_HXX
