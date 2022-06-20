#ifndef ACCOUNTUPDATEWINDOW_HXX
#define ACCOUNTUPDATEWINDOW_HXX

#include <QDialog>

namespace Ui {
class AccountUpdateWindow;
}

class AccountUpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountUpdateWindow(QWidget *parent = nullptr);
    ~AccountUpdateWindow();

private:
    Ui::AccountUpdateWindow *ui;
};

#endif // ACCOUNTUPDATEWINDOW_HXX
