#include "dialog_starter.h"
#include "ui_dialog_starter.h"

#include <QMovie>
#include <QTimer>

Dialog_Starter::Dialog_Starter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_Starter)
{
    ui->setupUi(this);
    this->setFixedWidth(600);
    this->setFixedHeight(400);
    setWindowFlags(Qt:: SplashScreen) ;

    QTimer::singleShot(5900, this, SLOT(close()));

    QMovie *movie = new QMovie(":/pics/Progressbar800x600.gif");
    movie->start();
    ui->label->setMovie(movie);
    ui->label->setScaledContents(true);
}

Dialog_Starter::~Dialog_Starter()
{
    delete ui;
}
