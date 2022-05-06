#ifndef CONTROLLCURRENTPROFILEWINDOW_HXX
#define CONTROLLCURRENTPROFILEWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class ControllCurrentProfileWindow;
}

class ControllCurrentProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControllCurrentProfileWindow(QWidget *parent = nullptr);
    ~ControllCurrentProfileWindow();

private:
    Ui::ControllCurrentProfileWindow *ui;
};

#endif // CONTROLLCURRENTPROFILEWINDOW_HXX
