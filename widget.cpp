#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money+=n;
    ui->lcdNumber->display(QString::number(money));

}

void Widget::setControl()
{
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbIceTea->setEnabled(money>=200);

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    setControl();
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    setControl();
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    setControl();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    setControl();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    setControl();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    setControl();
}

void Widget::on_pbIceTea_clicked()
{
    changeMoney(-200);
    setControl();
}


void Widget::on_pbReset_clicked()
{
    int c_500=0;
    int c_100=0;
    int c_50=0;
    int c_10=0;
    if(money>=500){
        c_500=money/500;
        money-=c_500*500;
    }
    if(money>=100){
        c_100=money/100;
        money-=c_100*100;
    }
    if(money>=50){
        c_50=money/50;
        money-=c_50*50;
    }
    if(money>=10){
        c_10=money/10;
        money-=c_10*10;
    }
    setControl();
    QMessageBox msg;
    msg.information(nullptr,"Reset",QString("500: %1\n100: %2\n50: %3\n10: %4\n").arg(c_500).arg(c_100).arg(c_50).arg(c_10));

}
