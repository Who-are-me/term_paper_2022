#ifndef REMOVEITEMWINDOW_HXX
#define REMOVEITEMWINDOW_HXX

#include <QDialog>

namespace Ui {
class RemoveItemWindow;
}

class RemoveItemWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveItemWindow(QWidget *parent = nullptr);
    ~RemoveItemWindow();

private:
    Ui::RemoveItemWindow *ui;
};

#endif // REMOVEITEMWINDOW_HXX
