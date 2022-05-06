#ifndef CONTROLLALLPROFILEWINDOW_HXX
#define CONTROLLALLPROFILEWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class ControllAllProfileWindow;
}

class ControllAllProfileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControllAllProfileWindow(QWidget *parent = nullptr);
    ~ControllAllProfileWindow();

private:
    Ui::ControllAllProfileWindow *ui;
};

#endif // CONTROLLALLPROFILEWINDOW_HXX
