#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    languageActionGroup = new QActionGroup(this);
    languageActionGroup->addAction(ui->actionDE);
    languageActionGroup->addAction(ui->actionUS);
    languageActionGroup->setExclusive(true);
     ui->actionDE->setIcon(QIcon(":/pic/de3.png"));
     ui->actionUS->setIcon(QIcon(":/pic/us3.png"));
    // ui->actionDE->setCheckable(true);
    // ui->actionUS->setCheckable(true);
    // ui->actionDE->setChecked(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDE_triggered()
{

    if(translator.load(":/q_de.qm"))//
    {
        ui->actionDE->setChecked(true);
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        QSettings *myregistry1 = new QSettings("HKEY_CURRENT_USER\\Software\\QtApp", QSettings::NativeFormat);
        myregistry1->setValue("lang", "de");

    }

}


void MainWindow::on_actionUS_triggered()
{

    if(translator.load(":/q_us.qm"))//
    {
        ui->actionUS->setChecked(true);
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        QSettings *myregistry2 = new QSettings("HKEY_CURRENT_USER\\Software\\QtApp", QSettings::NativeFormat);
        myregistry2->setValue("lang", "us");
    }

}

