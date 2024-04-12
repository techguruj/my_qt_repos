#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

enum Tasten
{
    e_first = 1,
    e_prevoius = 2,
    e_next = 4,
    e_last = 8,
    e_new = 16,
    e_save = 32,
    e_cancel = 64
};                          //schalteButtons(Tasten::e_save+ Tasten::e_cancel)

enum TastenKombi
{
    edit = Tasten::e_save + Tasten::e_cancel,
    normal = Tasten::e_first + Tasten::e_prevoius + Tasten::e_next + Tasten::e_last + Tasten::e_new
};


enum Modus
{
    neutral,
    neu,
    update
};

class Widget : public QWidget
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
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnFirst_clicked();
    void on_btnPrevious_clicked();
    void on_btnNext_clicked();
    void on_btnLast_clicked();
    void on_btnNew_clicked();
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
    void on_leMName_textChanged(const QString &arg1);
    void on_leMVorname_textChanged(const QString &arg1);
    void on_leMAbtNr_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
