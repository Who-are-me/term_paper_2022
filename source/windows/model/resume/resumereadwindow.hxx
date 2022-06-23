#ifndef RESUMEREADWINDOW_HXX
#define RESUMEREADWINDOW_HXX

#include <QDialog>

#include "models/resume.hxx"

namespace Ui {
class ResumeReadWindow;
}

class ResumeReadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResumeReadWindow(QWidget *parent = nullptr);
    ~ResumeReadWindow();

    void setObject(Resume new_vacancy);
    Resume getObject();
    void update();

private:
    Ui::ResumeReadWindow *ui;
    Resume m_resume;
};

#endif // RESUMEREADWINDOW_HXX
