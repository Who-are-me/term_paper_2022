#ifndef OWERVIEWUSERWINDOW_HXX
#define OWERVIEWUSERWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class OwerviewUserWindow;
}

class OwerviewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OwerviewUserWindow(QWidget *parent = nullptr);
    ~OwerviewUserWindow();

private:
    Ui::OwerviewUserWindow *ui;
};

#endif // OWERVIEWUSERWINDOW_HXX
