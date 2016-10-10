#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>
#include <QThread>

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

void MainWindow::on_pushButton_clicked()
{
    pause = ui->pauseTimeEdit->time();
    wait = ui->waitTimeEdit->time();

    this->hide();
    QString temp = "Tra "+pause.toString("HH:mm:ss")+" verrai avvisato";
    QMessageBox::information(this, tr("Ok"), temp);

    long time = pause.second() + pause.minute() * 60 + pause.hour() * 3600;
    QThread::sleep(time);
    pauseDialog.show();
    pauseDialog.setTime(wait, pause);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qApp->quit();
}
