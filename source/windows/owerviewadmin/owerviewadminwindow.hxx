#ifndef OWERVIEWADMINWINDOW_HXX
#define OWERVIEWADMINWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class OwerviewAdminWindow;
}

class OwerviewAdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OwerviewAdminWindow(QWidget *parent = nullptr);
    ~OwerviewAdminWindow();

private:
    Ui::OwerviewAdminWindow *ui;
};

#endif // OWERVIEWADMINWINDOW_HXX
