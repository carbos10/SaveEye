#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>
#include <QTime>
#include <QTimer>

namespace Ui {
class Pause;
}

class Pause : public QDialog
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = 0);
    ~Pause();
    void setTime(QTime time, QTime pause);

private slots:
    void on_pushButton_clicked();
    void setDisplay();

    void on_closeButton_clicked();

    void on_continueButton_clicked();

private:
    Ui::Pause *ui;
    QTime pause;
    QTime wait;
    QTime count;
    QTimer *timer;

protected:
    void closeEvent(QCloseEvent*);
};

#endif // PAUSE_H
