#ifndef ACCOUNTCREATEWINDOW_HXX
#define ACCOUNTCREATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class AccountCreateWindow;
}

class AccountCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountCreateWindow(QWidget *parent = nullptr);
    ~AccountCreateWindow();

private:
    Ui::AccountCreateWindow *ui;
};

#endif // ACCOUNTCREATEWINDOW_HXX
