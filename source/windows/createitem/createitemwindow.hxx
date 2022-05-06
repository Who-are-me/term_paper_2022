#ifndef CREATEITEMWINDOW_HXX
#define CREATEITEMWINDOW_HXX

#include <QMainWindow>

namespace Ui {
class CreateItemWindow;
}

class CreateItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateItemWindow(QWidget *parent = nullptr);
    ~CreateItemWindow();

private:
    Ui::CreateItemWindow *ui;
};

#endif // CREATEITEMWINDOW_HXX
