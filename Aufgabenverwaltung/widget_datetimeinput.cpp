#include "widget_datetimeinput.h"
#include "ui_widget_datetimeinput.h"
#include <QDateTime>
#include "database_scheduler.h"

Widget_DatetimeInput::Widget_DatetimeInput(QWidget *parent, QString anweisung)
    : QWidget(parent)
    , ui(new Ui::Widget_DatetimeInput)
{
    ui->setupUi(this);
    //temp_Datetime=QDateTime::fromString("30/12/9999 23:59:59", "dd/MM/yyyy HH:mm:ss");
    temp_Datetime = QDateTime();//Constructs a null datetime
    //temp_Datetime->QDateTime();
    qDebug()<<temp_Datetime.toString();
    setWindowIcon(QIcon(":/pics/datetime.png"));
    ui->label->setText(anweisung);
    on_pushButton_Heute_clicked();
}

Widget_DatetimeInput::~Widget_DatetimeInput()
{
    delete ui;
}

void Widget_DatetimeInput::on_calendarWidget_selectionChanged()
{
    ui->dateTimeEdit->setDate(ui->calendarWidget->selectedDate());
}


void Widget_DatetimeInput::on_dateTimeEdit_dateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
}


void Widget_DatetimeInput::on_pushButton_Uebernehmen_clicked()
{

    temp_Datetime=ui->dateTimeEdit->dateTime();
    qDebug()<<temp_Datetime.toString();
    this->close();
}


void Widget_DatetimeInput::on_pushButton_Heute_clicked()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

