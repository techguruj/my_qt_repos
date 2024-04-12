#ifndef REIFEN_H
#define REIFEN_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMessageBox>

class reifen : public QWidget
{
    Q_OBJECT;
    QLabel *labelEingabe;
    QLabel *labelProfiltiefe_neuer_Reifen;
    QLabel *labelProfiltiefe_aktuell;
    QLabel *labelSicherheitsprofiltiefe;
    QLabel *labelGefahrene_Kilometer;
    QLabel *labelJahreskilometerleistung;
    QLabel *labelAusgabe;
    QLabel *labelVerschleiß;
    QLabel *labelVerschleiß_pro_km;
    QLabel *labelRestprofil;
    QLabel *labelRestkilometer;
    QLabel *labelRestlaufzeit;

    QLineEdit *lineEditProfiltiefe_neuer_Reifen;
    QLineEdit *lineEditProfiltiefe_aktuell;
    QLineEdit *lineEditSicherheitsprofiltiefe;
    QLineEdit *lineEditGefahrene_Kilometer;
    QLineEdit *lineEditJahreskilometerleistung;
    QLineEdit *lineEditVerschleiß;
    QLineEdit *lineEditVerschleiß_pro_km;
    QLineEdit *lineEditRestprofil;
    QLineEdit *lineEditRestkilometer;
    QLineEdit *lineEditRestlaufzeit;

    QPushButton *buttonClear;
    QPushButton *buttonBerechnen;
    QPushButton *buttonBeenden;


    QHBoxLayout *hboxeingabe;
    QHBoxLayout *hboxProfiltiefe_neuer_Reifen;
    QHBoxLayout *hboxProfiltiefe_aktuell;
    QHBoxLayout *hboxSicherheitsprofiltiefe;
    QHBoxLayout *hboxGefahrene_Kilometer;
    QHBoxLayout *hboxJahreskilometerleistung;
    QHBoxLayout *hboxausgabe;
    QHBoxLayout *hboxVerschleiß;
    QHBoxLayout *hboxVerschleiß_pro_km;
    QHBoxLayout *hboxRestprofil;
    QHBoxLayout *hboxRestkilometer;
    QHBoxLayout *hboxRestlaufzeit;
    QHBoxLayout *hboxbuttons;

    QVBoxLayout *vboxalles;




public:
    reifen(QWidget *parent = nullptr); //
    ~reifen();
private slots:
    void berechnen();
    void clear();

};



#endif // REIFEN_H
