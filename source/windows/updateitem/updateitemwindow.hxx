#ifndef UPDATEITEMWINDOW_HXX
#define UPDATEITEMWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class UpdateItemWindow;
}

class UpdateItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdateItemWindow(QWidget *parent = nullptr);
    ~UpdateItemWindow();

private:
    Ui::UpdateItemWindow *ui;
};

#endif // UPDATEITEMWINDOW_HXX
