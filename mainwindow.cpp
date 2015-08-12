#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <QDialog>
#include <QDebug>

#include "fileinfo.h"
#include "helpdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open File"),
                                            "home/",
                                            tr("PWN Files (*.pwn)"));
    if(fileName.isNull()) return;
    ui->lineEdit->setText(fileName);
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("Click Action -> Check brackets to start process...");
    ReadFile(fileName);
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionCheck_triggered()
{
    if(GetFileName().isNull()){
        QMessageBox::information(this, "Curly Bracket Checker","No file load!");
        return;
    }
    int opened, closed, maxlines;
    opened = GetOpenedBracket();
    closed = GetClosedBracket();
    maxlines = GetMaxLines();
    ui->textBrowser->clear();
    QString Data = GetData();
    QString Info = "\n\nNumber of opened brackets: " + QString::number(opened)+\
            "\nNumber of closed brackets: " + QString::number(closed);
    QString output = Data + Info;
    ui->textBrowser->insertPlainText(output);
    QMessageBox::information(this, "Curly Bracket Checker","Done!");
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open File"),
                                            "C:/users/",
                                            tr("PWN Files (*.pwn)"));
    if(fileName.isNull()) return;
    ui->lineEdit->setText(fileName);
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("Click Action -> Check brackets to start process...");
    ReadFile(fileName);
}

void MainWindow::on_actionAbout_triggered()
{
     QMessageBox::information(this,
                             tr("Curly Bracket Checker"),
                             "Credit goes to Nikola Wiruspwns Butigan");
}

void MainWindow::on_actionHelp_triggered()
{
    helpDialog help;
    help.setModal(true);
    help.exec();
}
