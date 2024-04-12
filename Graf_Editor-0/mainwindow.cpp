#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->addPermanentWidget(ui->btnZoomMinus);
    ui->statusbar->addPermanentWidget(ui->sldZoom);
    ui->statusbar->addPermanentWidget(ui->btnZoomPlus);
    ui->statusbar->addPermanentWidget(ui->lblZoom);
    ui->btnZoomPlus->setFixedSize(QSize(32,32));
    ui->btnZoomMinus->setFixedSize(QSize(32,32));
    ui->sldZoom->setFixedWidth(100);
    ui->lblZoom->setFixedWidth(45);
    //ui->statusbar->showMessage("Programm gestartet", 10000);
    filter = "Textdatei (*.txt) ;;C++ Codedatei (*.cpp) ;;C++ Headerdatei (*.h) ;; Comma Separated Values Datei (*.csv)";
    filepath = "c:/temp";
    setTitle();
    filename = "";
    dirty = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTitle(QString value)
{
    setWindowTitle("Graf's Editor - " + value);
}

bool MainWindow::checkDirty()
{
    bool ok = true;
    if(dirty)
    {
        QMessageBox::StandardButton reply =
            QMessageBox::question(this,"Daten wurden verändert", "Soll das Dokument gespeichert werden?", QMessageBox::Yes |
                                                                                                          QMessageBox::No  |
                                                                                                          QMessageBox::Cancel);
        if(reply == QMessageBox::Cancel)
        {
            ok = false;
        }
        else if(reply == QMessageBox::No)
        {
            ok = true;
        }
        else        //yes gewählt
        {
            if(filename != "")
            {
                //Speichern
                ok = save();
            }
            else
            {
                //Dateinamen holen und speichern
                ok = on_action_Speichern_unter_triggered();
            }
        }
    }
    return ok;
}

//----------------------------------------------------------DATEI-MENÜ
void MainWindow::on_action_Neues_Dokument_triggered()
{

    //Stelle fest, ob der Text verändert wurde.
    //Wenn ja, dann fragen, ob gespeichert werden soll.
    //Wenn ja, dann speichern veranlassen.
    if(checkDirty())        //Wenn gespeichert, oder kein Speichern erwünscht-->Alles Ok.
    {
        ui->textEdit->clear();      //Textedit leeren
        filename = "";
        setTitle();
    }
}


void MainWindow::on_action_Oeffnen_triggered()
{
    //Stelle fest, ob der Text verändert wurde.
    //Wenn ja, dann fragen, ob gespeichert werden soll.
    //Wenn ja, dann speichern veranlassen.
    if(checkDirty())        //Datei gespeichert, oder Speichern nicht erwünscht, oder nicht erforderlich...
    {
        //Dokument aus Datei laden
        filename = QFileDialog::getOpenFileName(this, "Datei öffnen", filepath, filter);    //Dateinamen holen
        if(filename != "")      //Dateiname gültig?  (Nicht Abbruch geklickt)
        {
            QFile file(filename);
            QTextStream puffer(&file);
            if(!file.open(QIODevice::ReadOnly))     //Datei öffnen
            {
                QMessageBox::warning(this, "Fehler beim Öffnen der Datei", "Möglicherweise haben Sie keine Berechtigung");
                return;
            }
            else
            {
                ui->textEdit->setText(puffer.readAll());        //Datei einlesen
                dirty = false;                                  //Datei ist sauber
                setTitle(filename);                             //Fenstertitel setzen
            }
        }
    }
}

bool MainWindow::save()
{
    bool ok = false;                //Merkvariable für Rückgabe
    QFile file(filename);           //Für Zugriff auf die Datei
    QTextStream puffer(&file);      //Zur Pufferung der Daten
    //Speichert die Daten
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,  "Datei kann nicht angelegt werden",
                                    "Konnte die Datei nicht speichern\nMöglicherweise verfügen Sie über keine Berechtigung");
        ok = false;
    }
    else
    {
        puffer << ui->textEdit->toPlainText();      //Daten schreiben
        file.close();
        ok = true;
        dirty = false;
        setTitle(filename);
    }
    return ok;
}

void MainWindow::on_action_Speichern_triggered()
{
    //Hat das Dokument bereits einen Namen?
    if(filename == "")   //...oder filename.isempty()
    {
        on_action_Speichern_unter_triggered();      //Dateinamen holen und speichern
    }
    else
    {
        save();    //Wenn ja, dann speichern.
    }
}


bool MainWindow::on_action_Speichern_unter_triggered()
{
    bool ok;
    //Hole neuen Dateinamen
    filename = QFileDialog::getSaveFileName(this, "Datei speichern", filepath, filter);
    if(filename != "")      //Haben wir jetzt einen Dateinamen, dann
    {
        //Speichern des Dokuments
        ok = save();
    }
    else
    {
        ok = false;     //Abbruch geklickt
    }
    return ok;
}


void MainWindow::on_action_Vorschau_triggered()
{
    //Druckvorschau anzeigen
}


void MainWindow::on_action_Druck_triggered()
{
    //Druck-Dialog anzeigen
    //Druck auslösen
}


void MainWindow::on_action_Beenden_triggered()
{
    //Stelle fest, ob der Text verändert wurde.
    //Wenn ja, dann fragen, ob gespeichert werden soll.
    //Wenn ja, dann speichern veranlassen.
    if(checkDirty())
    {
        //Programm beenden
        close();
    }
}

//----------------------------------------------------------BEARBEITEN-MENÜ
void MainWindow::on_action_Rueckgaengig_triggered()
{
    ui->textEdit->undo();       //Rückgängig
}


void MainWindow::on_action_Wiederholen_triggered()
{
    ui->textEdit->redo();       //Wiederherstellen
}


void MainWindow::on_action_Ausschneiden_triggered()
{
    ui->textEdit->cut();
    ui->statusbar->showMessage("Text in Zwischenablage ausgeschnitten",5000);
}


void MainWindow::on_action_Kopieren_triggered()
{
    ui->textEdit->copy();
    ui->statusbar->showMessage("Text in Zwischenablage kopiert",5000);
}


void MainWindow::on_action_Einfuegen_triggered()
{
    ui->textEdit->paste();
    ui->statusbar->showMessage("Text aus Zwischenablage eingefügt",5000);
}


void MainWindow::on_action_Suchen_triggered()
{
    //Dialog zum Suchen öffnen
}


void MainWindow::on_action_Ersetzen_triggered()
{
    //Dialog zum ERsetzen öffnen
}

//----------------------------------------------------------ANSICHT-MENÜ
void MainWindow::on_action_Schriftart_triggered()
{
    //Dialog zur Fonteinstellung öffnen
    //Einstellung zu textedit übertragen
}


void MainWindow::on_action_Vordergrund_triggered()
{
    //Dialog zur Farbeinstellung öffnen
    //Einstellung zu textedit übertragen
}

//----------------------------------------------------------EXTRAS-MENÜ
void MainWindow::on_action_Optionen_triggered()
{
    //Dialog öffnen
}


void MainWindow::on_action_Deutsch_triggered()
{
    //Spracheinstellung vornehmen
}


void MainWindow::on_action_Englisch_triggered()
{
    //Spracheinstellung vornehmen
}



void MainWindow::zoom(int wunschzoom)
{
    //Zoom einstellen

}

void MainWindow::on_action_100_triggered()
{
    zoom(100);
}


void MainWindow::on_action_200_triggered()
{
    zoom(200);
}


void MainWindow::on_action_300_triggered()
{
    zoom(300);
}


void MainWindow::on_action_400_triggered()
{
    zoom(400);
}


void MainWindow::on_action_800_triggered()
{
    zoom(800);
}


void MainWindow::on_action_1600_triggered()
{
    zoom(1600);
}


void MainWindow::on_action_3200_triggered()
{
    zoom(3200);
}

void MainWindow::on_btnZoomPlus_clicked()
{
    //Ausgehend vom aktuellen Zoom vergrößern
}


void MainWindow::on_btnMinus_clicked()
{
    //Ausgehend vom aktuellen Zoom verkleinern
}


void MainWindow::on_sldZoom_valueChanged(int value)
{
    zoom(value);
}


void MainWindow::on_textEdit_textChanged()
{
    dirty = true;
}

