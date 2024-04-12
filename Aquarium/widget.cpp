#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

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

void Widget::on_pushButton_3_clicked()
{
    ui->spinBoxBreite->setValue(1);
    ui->spinBoxHoehe->setValue(1);
    ui->spinBoxTiefe->setValue(1);
    ui->lineEditAntigenMenge->setText("0");
    ui->lineEditAnweisungL->setText("0");
    ui->lineEditAnweisungml->setText("0");
    ui->lineEditAquariumVolumenL->setText("0");
}


void Widget::on_pushButton_2_clicked()
{
    // if (ui->spinBoxBreite->value() == 0 || ui->spinBoxHoehe->value() == 0 || ui->spinBoxTiefe->value() == 0){
    //     QMessageBox::warning(this, "Fehler", "Aquariummaße sind nicht vollständig");
    //     return;
    // }

    bool ok;
    int Anweisungml = ui->lineEditAnweisungml->text().toInt(&ok);
    if (!ok){
        QMessageBox::warning(this, "Fehler", "Anweisung in ml ist keine Zahl");
        return;
    };

    int AnweisungL = ui->lineEditAnweisungL->text().toInt(&ok);
    if (!ok){
        QMessageBox::warning(this, "Fehler", "Anweisung in L ist keine Zahl");
        return;
    };

    int AquariumVolumenL = ui->spinBoxBreite->value() * ui->spinBoxHoehe->value() * ui->spinBoxTiefe->value()/1000;
    ui->lineEditAquariumVolumenL->setText(QString::number(AquariumVolumenL));

    int AntigenMenge = AquariumVolumenL*Anweisungml/AnweisungL;
    ui->lineEditAntigenMenge->setText(QString::number(AntigenMenge));

}

void Widget::tunwas()
{
qDebug() << "Hallo";

}

