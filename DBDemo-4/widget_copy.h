#ifndef WIDGET_COPY_H
#define WIDGET_COPY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "form_arbeien.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget_copy; }
QT_END_NAMESPACE

#include "enums.h"

class WIDGET_copy : public QWidget
{
    Q_OBJECT

    QSqlDatabase *db;       //Für Verbindungsaufbau
    QSqlQuery    *query;    //Für versenden einer Abfrage und zurückerhalten des Ergebnisses (Dynaset)
    int           _currentrecord;    //Auf welchem DS stehen wir
    int           _numrecords;        //Wie viele DS haben wir
    Modus         _modus;

    void refreshUi();
    void holeDaten();
    void switchButtons(TastenKombi kombi = TastenKombi::normal);
    void switchButtonsOff();

public:
    WIDGET_copy::Widget_copy(QWidget *parent = nullptr);
    WIDGET_copy::~Widget_copy();

private slots:
    void on_btnFirst_clicked();
    void on_btnPrevious_clicked();
    void on_btnNext_clicked();
    void on_btnLast_clicked();
    void on_btnNew_clicked();
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
    void on_leMVorname_textChanged(const QString &arg1);
    void on_leMAbtNr_textChanged(const QString &arg1);
    void on_leMNachname_textChanged(const QString &arg1);

    void on_pushButton_zuAbteilung_clicked();

    void on_pushButton_zuMitarbeiter_clicked();

    void on_pushButton_ZuFormArbeiten_clicked();

private:
    Ui::Widget_copy *ui;
};
#endif // WIDGET_COPY_H
