#include "pause.h"
#include "ui_pause.h"
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QThread>

Pause::Pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);

}

Pause::~Pause()
{
    delete ui;
}

void Pause::setTime(QTime wait, QTime pause)
{


    this->pause = pause;
    this->wait = wait;
    ui->countDown->setTime(this->wait);
    ui->continueButton->setEnabled(false);
    ui->pushButton->setEnabled(true);
    this->timer = new QTimer();
}


void Pause::on_pushButton_clicked()
{
    if(!this->timer->isActive()){
        this->count = this->wait;
        this->timer->setInterval(1000);
        this->timer->setSingleShot(false);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(setDisplay()));
        this->timer->start();
        ui->pushButton->setEnabled(false);
    }
}

void Pause::setDisplay()
{
    if(count.second() > 0 || count.minute() > 0 || count.hour() > 0){
        count = count.addSecs(-1);
        ui->countDown->setTime(count);
    } else {
        ui->continueButton->setEnabled(true);
        this->timer->stop();
    }
}

void Pause::closeEvent(QCloseEvent *)
{
    qApp->quit();
}

void Pause::on_closeButton_clicked()
{
    this->close();
}

void Pause::on_continueButton_clicked()
{
    long time = pause.second() + pause.minute() * 60 + pause.hour() * 3600;
    this->hide();
    QThread::sleep(time);

    this->show();
    this->setTime(wait, pause);
}
