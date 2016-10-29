#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pacmanexec.h"
#include "uihelper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_mirrorUpdateButton_clicked();

    void on_softwareUpdateButton_clicked();

    void on_gotoIndex2Button_clicked();

    void on_chromeCheckbox_clicked();

    void on_installSoftwareButton_clicked();

    void on_gotoIndex3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    UnixCommand *m_unixCommand;
    PacmanExec *m_pacmanExec;
};

#endif // MAINWINDOW_H
