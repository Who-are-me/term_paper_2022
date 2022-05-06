#ifndef EXPOSEITEMWINDOW_HXX
#define EXPOSEITEMWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class ExposeItemWindow;
}

class ExposeItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExposeItemWindow(QWidget *parent = nullptr);
    ~ExposeItemWindow();

private:
    Ui::ExposeItemWindow *ui;
};

#endif // EXPOSEITEMWINDOW_HXX
