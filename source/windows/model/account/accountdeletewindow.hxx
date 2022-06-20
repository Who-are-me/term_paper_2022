#ifndef ACCOUNTDELETEWINDOW_HXX
#define ACCOUNTDELETEWINDOW_HXX

#include <QDialog>

namespace Ui {
class AccountDeleteWindow;
}

class AccountDeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDeleteWindow(QWidget *parent = nullptr);
    ~AccountDeleteWindow();

private:
    Ui::AccountDeleteWindow *ui;
};

#endif // ACCOUNTDELETEWINDOW_HXX
