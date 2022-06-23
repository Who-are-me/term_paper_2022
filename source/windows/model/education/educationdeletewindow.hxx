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

    void setEducationId(int new_id);
    void update();

private:
    Ui::EducationDeleteWindow *ui;
    int id;

private slots:
    void on_btn_ok_released();
    void on_btn_cancel_released();

signals:
    void pushOk();
    void pushCancel();
};

#endif // EDUCATIONDELETEWINDOW_HXX
