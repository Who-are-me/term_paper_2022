#ifndef CONTROLLCURRENTPROFILEWINDOW_HXX
#define CONTROLLCURRENTPROFILEWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class ControlCurrentProfilesWindow;
}

class ControlCurrentProfilesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlCurrentProfilesWindow(QWidget *parent = nullptr);
    ~ControlCurrentProfilesWindow();

private:
    Ui::ControlCurrentProfilesWindow *ui;
};

#endif // CONTROLLCURRENTPROFILEWINDOW_HXX
