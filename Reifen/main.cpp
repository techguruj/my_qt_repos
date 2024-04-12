/*
Sie lesen in der Zeitung ein Angebot für Reifen und
überlegen, ob es sich jetzt lohnt die Reifen zu
wechseln. Sie beschlieBen dafur ein Programm zu
entwickeln. Sorgen Sie für die Eingaben, entwickeln Sie
Formeln und montieren Sie die berechneten Ergebnisse in
Ausgaben.

Beispiel:

     Eingabe                    :
    *Profiltiefe_neuer_Reifen   : 10
    *Profiltiefe_aktuell        : 3
    *Sicherheitsprofiltiefe     : 1.6
    *Gefahrene_Kilometer        : 70000
    *Jahreskilometerleistung    : 15000
     Ausgabe                    :
    *Verschleiß                 : 7 mm
    *Verschleiß_pro_km          : 0.0001 mm
    *Restprofil                 : 1.4 mm
    *Restkilometer              : 14000
    *Restlaufzeit               : 11.2 Monate

------------Berechnen------Beenden-----------
//QLabel  //QLineEdit  //QPushButton  //QVBoxLayout //QHBoxLayout  //->setText("")
//lineEditProfiltiefe_neuer_Reifen->clear();


 */



#include "reifen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    reifen w;
    w.show();
    return a.exec();
}




