#ifndef ACCOUNTREADWINDOW_HXX
#define ACCOUNTREADWINDOW_HXX

#include <QDialog>

namespace Ui {
class AccountReadWindow;
}

class AccountReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountReadWindow(QWidget *parent = nullptr);
    ~AccountReadWindow();

private:
    Ui::AccountReadWindow *ui;
};

#endif // ACCOUNTREADWINDOW_HXX
