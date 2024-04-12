#include "reifen.h"


reifen::reifen(QWidget *parent)
    : QWidget(parent)
{
    labelEingabe                    =new QLabel;
    labelProfiltiefe_neuer_Reifen   =new QLabel;
    labelProfiltiefe_aktuell        =new QLabel;
    labelSicherheitsprofiltiefe     =new QLabel;
    labelGefahrene_Kilometer        =new QLabel;
    labelJahreskilometerleistung    =new QLabel;
    labelAusgabe                    =new QLabel;
    labelVerschleiß                 =new QLabel;
    labelVerschleiß_pro_km          =new QLabel;
    labelRestprofil                 =new QLabel;
    labelRestkilometer              =new QLabel;
    labelRestlaufzeit               =new QLabel;

    lineEditProfiltiefe_neuer_Reifen    =new QLineEdit;
    lineEditProfiltiefe_aktuell         =new QLineEdit;
    lineEditSicherheitsprofiltiefe      =new QLineEdit;
    lineEditGefahrene_Kilometer         =new QLineEdit;
    lineEditJahreskilometerleistung     =new QLineEdit;
    lineEditVerschleiß                  =new QLineEdit;
    lineEditVerschleiß_pro_km           =new QLineEdit;
    lineEditRestprofil                  =new QLineEdit;
    lineEditRestkilometer               =new QLineEdit;
    lineEditRestlaufzeit                =new QLineEdit;

    buttonClear        =new  QPushButton;
    buttonBerechnen    =new  QPushButton;
    buttonBeenden      =new  QPushButton;

    hboxeingabe                     = new QHBoxLayout;
    hboxProfiltiefe_neuer_Reifen    = new QHBoxLayout;
    hboxProfiltiefe_aktuell         = new QHBoxLayout;
    hboxSicherheitsprofiltiefe      = new QHBoxLayout;
    hboxGefahrene_Kilometer         = new QHBoxLayout;
    hboxJahreskilometerleistung     = new QHBoxLayout;
    hboxausgabe                     = new QHBoxLayout;
    hboxVerschleiß                  = new QHBoxLayout;
    hboxVerschleiß_pro_km           = new QHBoxLayout;
    hboxRestprofil                  = new QHBoxLayout;
    hboxRestkilometer               = new QHBoxLayout;
    hboxRestlaufzeit                = new QHBoxLayout;
    hboxbuttons                     = new QHBoxLayout;

    vboxalles= new QVBoxLayout(this);

    setWindowTitle("Reifen-Berechnung");

    labelEingabe                    ->setText("Eingabe:");
    labelProfiltiefe_neuer_Reifen   ->setText("Profiltiefe neuer Reifen");
    labelProfiltiefe_aktuell        ->setText("Profiltiefe aktuell     ");
    labelSicherheitsprofiltiefe     ->setText("Sicherheitsprofiltiefe  ");
    labelGefahrene_Kilometer        ->setText("Gefahrene Kilometer     ");
    labelJahreskilometerleistung    ->setText("Jahreskilometerleistung ");
    labelAusgabe                    ->setText("Ausgabe:");
    labelVerschleiß                 ->setText("Verschleiß              ");
    labelVerschleiß_pro_km          ->setText("Verschleiß pro km       ");
    labelRestprofil                 ->setText("Restprofil              ");
    labelRestkilometer              ->setText("Restkilometer           ");
    labelRestlaufzeit               ->setText("Restlaufzeit            ");

    labelEingabe                    ->setFixedWidth(130);
    labelProfiltiefe_neuer_Reifen   ->setFixedWidth(130);
    labelProfiltiefe_aktuell        ->setFixedWidth(130);
    labelSicherheitsprofiltiefe     ->setFixedWidth(130);
    labelGefahrene_Kilometer        ->setFixedWidth(130);
    labelJahreskilometerleistung    ->setFixedWidth(130);
    labelAusgabe                    ->setFixedWidth(130);
    labelVerschleiß                 ->setFixedWidth(130);
    labelVerschleiß_pro_km          ->setFixedWidth(130);
    labelRestprofil                 ->setFixedWidth(130);
    labelRestkilometer              ->setFixedWidth(130);
    labelRestlaufzeit               ->setFixedWidth(130);

    buttonClear        ->setText("Clear");
    buttonBerechnen    ->setText("Berechnen");
    buttonBeenden      ->setText("Beenden");

    hboxeingabe                    ->addWidget(labelEingabe);
    hboxeingabe                    ->addStretch();
    hboxProfiltiefe_neuer_Reifen   ->addWidget(labelProfiltiefe_neuer_Reifen);
    hboxProfiltiefe_neuer_Reifen   ->addWidget(lineEditProfiltiefe_neuer_Reifen);
    hboxProfiltiefe_aktuell        ->addWidget(labelProfiltiefe_aktuell);
    hboxProfiltiefe_aktuell        ->addWidget(lineEditProfiltiefe_aktuell);
    hboxSicherheitsprofiltiefe     ->addWidget(labelSicherheitsprofiltiefe);
    hboxSicherheitsprofiltiefe     ->addWidget(lineEditSicherheitsprofiltiefe);
    hboxGefahrene_Kilometer        ->addWidget(labelGefahrene_Kilometer);
    hboxGefahrene_Kilometer        ->addWidget(lineEditGefahrene_Kilometer);
    hboxJahreskilometerleistung    ->addWidget(labelJahreskilometerleistung);
    hboxJahreskilometerleistung    ->addWidget(lineEditJahreskilometerleistung);
    hboxausgabe                    ->addWidget(labelAusgabe);
    hboxausgabe                    ->addStretch();
    hboxVerschleiß                 ->addWidget(labelVerschleiß);
    hboxVerschleiß                 ->addWidget(lineEditVerschleiß);
    hboxVerschleiß_pro_km          ->addWidget(labelVerschleiß_pro_km);
    hboxVerschleiß_pro_km          ->addWidget(lineEditVerschleiß_pro_km);
    hboxRestprofil                 ->addWidget(labelRestprofil);
    hboxRestprofil                 ->addWidget(lineEditRestprofil);
    hboxRestkilometer              ->addWidget(labelRestkilometer);
    hboxRestkilometer              ->addWidget(lineEditRestkilometer);
    hboxRestlaufzeit               ->addWidget(labelRestlaufzeit);
    hboxRestlaufzeit               ->addWidget(lineEditRestlaufzeit);
    hboxbuttons                    ->addWidget(buttonClear);
    hboxbuttons                    ->addWidget(buttonBerechnen);
    hboxbuttons                    ->addWidget(buttonBeenden);



    vboxalles                     ->addLayout(hboxeingabe);
    vboxalles                     ->addLayout(hboxProfiltiefe_neuer_Reifen);
    vboxalles                     ->addLayout(hboxProfiltiefe_aktuell);
    vboxalles                     ->addLayout(hboxSicherheitsprofiltiefe);
    vboxalles                     ->addLayout(hboxGefahrene_Kilometer);
    vboxalles                     ->addLayout(hboxJahreskilometerleistung);
    vboxalles                     ->addLayout(hboxausgabe);
    vboxalles                     ->addLayout(hboxVerschleiß);
    vboxalles                     ->addLayout(hboxVerschleiß_pro_km);
    vboxalles                     ->addLayout(hboxRestprofil);
    vboxalles                     ->addLayout(hboxRestkilometer);
    vboxalles                     ->addLayout(hboxRestlaufzeit);
    vboxalles                     ->addLayout(hboxbuttons);

    setLayout(vboxalles);

connect(buttonClear,SIGNAL(clicked()),this,SLOT(clear()));
connect(buttonBerechnen,SIGNAL(clicked()),this,SLOT(berechnen()));
connect(buttonBeenden,SIGNAL(clicked()),this,SLOT(close()));



}


reifen::~reifen() {}

void reifen::clear()
{
    lineEditProfiltiefe_neuer_Reifen   ->clear();
    lineEditProfiltiefe_aktuell        ->clear();
    lineEditSicherheitsprofiltiefe     ->clear();
    lineEditGefahrene_Kilometer        ->clear();
    lineEditJahreskilometerleistung    ->clear();
    lineEditVerschleiß                 ->clear();
    lineEditVerschleiß_pro_km          ->clear();
    lineEditRestprofil                 ->clear();
    lineEditRestkilometer              ->clear();
    lineEditRestlaufzeit               ->clear();
}


void reifen::berechnen()
{
   double   Profiltiefe_neuer_Reifen;
   double   Profiltiefe_aktuell;
   double   Sicherheitsprofiltiefe;
   int      Gefahrene_Kilometer;
   int      Jahreskilometerleistung;

   double   Verschleiß;
   double   Verschleiß_pro_km;
   double   Restprofil;
   int      Restkilometer;
   double   Restlaufzeit;

   bool     eingabe_ok;


   Profiltiefe_neuer_Reifen = lineEditProfiltiefe_neuer_Reifen->text().toDouble(&eingabe_ok);
   if (!eingabe_ok) {
       QMessageBox::warning(this,"Fehler","Profiltiefe neuer Reifen ist keine gueltige Zahl");
       return;
   }

   Profiltiefe_aktuell = lineEditProfiltiefe_aktuell->text().toDouble(&eingabe_ok);
   if (!eingabe_ok) {
       QMessageBox::information(this,"Fehler","Profiltiefe aktuell ist keine gueltige Zahl");
       return;
   }

   Sicherheitsprofiltiefe = lineEditSicherheitsprofiltiefe->text().toDouble(&eingabe_ok);
   if (!eingabe_ok) {
       QMessageBox::critical(this,"Fehler","Sicherheitsprofiltiefe ist keine gueltige Zahl");
       return;
   }

   Gefahrene_Kilometer = lineEditGefahrene_Kilometer->text().toInt(&eingabe_ok);
   if (!eingabe_ok) {
       QMessageBox::warning(this,"Fehler","Gefahrene Kilometer ist keine gueltige Zahl");
       return;
   }

   Jahreskilometerleistung = lineEditJahreskilometerleistung->text().toInt(&eingabe_ok);
   if (!eingabe_ok) {
       QMessageBox::warning(this,"Fehler","Jahreskilometerleistung ist keine gueltige Zahl");
       return;
   }

   lineEditProfiltiefe_neuer_Reifen ->setText(QString::number(Profiltiefe_neuer_Reifen,'f',1));
   lineEditProfiltiefe_aktuell      ->setText(QString::number(Profiltiefe_aktuell,'f',1));
   lineEditSicherheitsprofiltiefe   ->setText(QString::number(Sicherheitsprofiltiefe,'f',1));
   lineEditGefahrene_Kilometer      ->setText(QString::number(Gefahrene_Kilometer));
   lineEditJahreskilometerleistung  ->setText(QString::number(Jahreskilometerleistung));

   Verschleiß = Profiltiefe_neuer_Reifen - Profiltiefe_aktuell;
   lineEditVerschleiß->setText(QString::number(Verschleiß)+" mm");

   Verschleiß_pro_km = Verschleiß / Gefahrene_Kilometer;
   lineEditVerschleiß_pro_km->setText(QString::number(Verschleiß_pro_km,'f',4)+" mm");

   Restprofil = Profiltiefe_aktuell - Sicherheitsprofiltiefe;
   lineEditRestprofil->setText(QString::number(Restprofil,'f',1)+" mm");

   Restkilometer = Restprofil / Verschleiß_pro_km;
   lineEditRestkilometer->setText(QString::number(Restkilometer)+" km");

   Restlaufzeit = (double)Restkilometer / (double)Jahreskilometerleistung * 12;
   lineEditRestlaufzeit->setText(QString::number(Restlaufzeit,'f',1)+" Monate");


}



