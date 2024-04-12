#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSql>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>



QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    QSqlDatabase *db ;
    QSqlQuery *query;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void refreshui(int);
    void refreshui();

private slots:
    void rowlabelupdate();
    void on_pushButton_First_clicked();

    void on_pushButton_Previous_clicked();

    void on_pushButton_Next_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_Abbrechen_clicked();

    void on_pushButton_Viewmode_clicked();

    void on_pushButton_neumode_clicked();

    void on_pushButton_updatemode_clicked();

    void on_lineEdit_MitarbeiterNr_textChanged(const QString &arg1);

    void on_pushButton_Neu_clicked();

    void on_pushButton_Speichern_clicked();

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
