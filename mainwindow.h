#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionOpen_File_triggered();

    void on_actionExit_triggered();

    void on_actionCheck_triggered();

    void on_pushButton_clicked();

    void on_actionAbout_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
