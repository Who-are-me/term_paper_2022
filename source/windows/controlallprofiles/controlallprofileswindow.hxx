#ifndef CONTROLLALLPROFILEWINDOW_HXX
#define CONTROLLALLPROFILEWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class ControlAllProfilesWindow;
}

class ControlAllProfilesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlAllProfilesWindow(QWidget *parent = nullptr);
    ~ControlAllProfilesWindow();

private:
    Ui::ControlAllProfilesWindow *ui;
};

#endif // CONTROLLALLPROFILEWINDOW_HXX
