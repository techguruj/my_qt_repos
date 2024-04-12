#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <dlgoptionen.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    registry = new QSettings("HKEY_CURRENT_USER/Software/Graf_Editor", QSettings::IniFormat);
    QString lang = registry->value("lang").toString();
    qDebug() << "MainWindow: " << lang;
    adjustLanguage(lang);

    ui->statusbar->addPermanentWidget(ui->btnZoomMinus);
    ui->statusbar->addPermanentWidget(ui->sldZoom);
    ui->statusbar->addPermanentWidget(ui->btnZoomPlus);
    ui->statusbar->addPermanentWidget(ui->lblZoom);
    ui->btnZoomPlus->setFixedSize(QSize(32,32));
    ui->btnZoomMinus->setFixedSize(QSize(32,32));
    ui->sldZoom->setFixedWidth(100);
    ui->lblZoom->setFixedWidth(45);
    //ui->statusbar->showMessage("Programm gestartet", 10000);
    filter = tr("Textdatei (*.txt) ;;C++ Codedatei (*.cpp) ;;C++ Headerdatei (*.h) ;; Comma Separated Values Datei (*.csv)");
    filepath = "c:/temp";
    setTitle();
    filename = "";
    dirty = false;
    printer.setPrinterName("default");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adjustLanguage(QString lang)
{
    ui->action_Deutsch->setChecked(false);      //Alle Häkchen im Menü Extras-Spracheinstellung ausschalten
    ui->action_Englisch->setChecked(false);

    if(lang == "de")                            //Häkchen für gewünschte Sprache setzen
        ui->action_Deutsch->setChecked(true);
    else if(lang == "en")
        ui->action_Englisch->setChecked(true);
}

void MainWindow::setTitle(QString value)
{
    setWindowTitle("Graf's Editor - " + value);
}

bool MainWindow::checkDirty()
{
    bool ok = true;
    if(dirty)           //Wenn das Dokument geändert wurde, ...
    {
        QMessageBox::StandardButton reply =         //...fragen ob gespeichert werden soll
            QMessageBox::question(this, tr("Daten wurden verändert"), tr("Soll das Dokument gespeichert werden?"), QMessageBox::Yes |
                                                                                                          QMessageBox::No  |
                                                                                                          QMessageBox::Cancel);
        if(reply == QMessageBox::Cancel)        //Bei Abbruch, nichts tun --> false weitergeben
        {
            ok = false;
        }
        else if(reply == QMessageBox::No)       //Speichern nicht gewünscht
        {
            ok = true;
        }
        else                                    //yes Speichern gewählt
        {
            if(filename != "")
            {
                //Speichern
                ok = save();                    //Speicherung durchführen
            }
            else
            {
                ok = on_action_Speichern_unter_triggered();         //Dateinamen holen und speichern
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
        filename = QFileDialog::getOpenFileName(this, tr("Datei öffnen"), filepath, filter);    //Dateinamen holen
        if(filename != "")      //Dateiname gültig?  (Nicht Abbruch geklickt)
        {
            QFile file(filename);
            QTextStream puffer(&file);
            if(!file.open(QIODevice::ReadOnly))     //Datei öffnen
            {
                QMessageBox::warning(this, tr("Fehler beim Öffnen der Datei"), tr("Möglicherweise haben Sie keine Berechtigung"));
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
    bool ok = false;                                //Merkvariable für Rückgabe
    QFile file(filename);                           //Für Zugriff auf die Datei
    QTextStream puffer(&file);                      //Zur Pufferung der Daten
    //Speichert die Daten
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,  tr("Datei kann nicht angelegt werden"),
                             tr("Konnte die Datei nicht speichern\nMöglicherweise verfügen Sie über keine Berechtigung"));
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
    if(filename == "")                              //...oder filename.isempty()
    {
        on_action_Speichern_unter_triggered();      //Dateinamen holen und speichern
    }
    else
    {
        save();                                     //Wenn ja, dann speichern.
    }
}

bool MainWindow::on_action_Speichern_unter_triggered()
{
    bool ok;
    //Hole neuen Dateinamen
    filename = QFileDialog::getSaveFileName(this, tr("Datei speichern"), filepath, filter);
    if(filename != "")                              //Haben wir jetzt einen Dateinamen, dann
    {
        ok = save();                                //Speichern des Dokuments
    }
    else
    {
        ok = false;                                 //Abbruch geklickt
    }
    return ok;
}

void MainWindow::on_action_Vorschau_triggered()
{
    //Druckvorschau anzeigen
    QPrintPreviewDialog dialog(&printer, this);
    QTextDocument document;
    document.setPlainText(ui->textEdit->toPlainText());
    connect(&dialog,    &QPrintPreviewDialog::paintRequested, [&](QPrinter *previewprinter){document.print(previewprinter);});
    dialog.exec();
}

void MainWindow::on_action_Druck_triggered()
{
    //Druck-Dialog anzeigen
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() == QDialog::Rejected) return;
    //Druck auslösen
    ui->textEdit->print(&printer);
}
void MainWindow::on_action_Direkt_Drucken_triggered()
{
     ui->textEdit->print(&printer);
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
    ui->statusbar->showMessage(tr("Text in Zwischenablage ausgeschnitten"),5000);
}

void MainWindow::on_action_Kopieren_triggered()
{
    ui->textEdit->copy();
    ui->statusbar->showMessage(tr("Text in Zwischenablage kopiert"),5000);
}

void MainWindow::on_action_Einfuegen_triggered()
{
    ui->textEdit->paste();
    ui->statusbar->showMessage(tr("Text aus Zwischenablage eingefügt"),5000);
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
    DlgOptionen *dlg_optionen = new DlgOptionen;
    dlg_optionen->exec();
}

void MainWindow::on_action_Deutsch_triggered()
{
    //Spracheinstellung vornehmen
    registry->setValue("lang","de");
    QMessageBox::information(this, tr("Sprache umgestellt"), tr("Damit die Einstellung wirkt, starten Sie die Anwendung neu"));
    adjustLanguage("de");
}

void MainWindow::on_action_Englisch_triggered()
{
    //Spracheinstellung vornehmen
    registry->setValue("lang","en");
    QMessageBox::information(this, tr("Sprache umgestellt"), tr("Damit die Einstellung wirkt, starten Sie die Anwendung neu"));
    adjustLanguage("en");
}

void MainWindow::zoom(int wunschzoom)
{
    //Zoom einstellen
    if(wunschzoom > aktueller_zoom)
    {
        ui->textEdit->zoomIn((wunschzoom - aktueller_zoom) * 2);
    }
    else
    {
        ui->textEdit->zoomOut((aktueller_zoom - wunschzoom) * 2);
    }
    aktueller_zoom = wunschzoom;
    ui->lblZoom->setText(QString::number(aktueller_zoom * 100) + "%");
    ui->sldZoom->setValue(aktueller_zoom);
}

void MainWindow::on_action_100_triggered()
{
    zoom(1);
}

void MainWindow::on_action_200_triggered()
{
    zoom(2);
}

void MainWindow::on_action_300_triggered()
{
    zoom(3);
}

void MainWindow::on_action_400_triggered()
{
    zoom(4);
}

void MainWindow::on_action_800_triggered()
{
    zoom(8);
}

void MainWindow::on_action_1600_triggered()
{
    zoom(16);
}

void MainWindow::on_action_3200_triggered()
{
    zoom(32);
}

void MainWindow::on_btnZoomPlus_clicked()
{
    //Ausgehend vom aktuellen Zoom vergrößern
    zoom(aktueller_zoom + 1);
}

void MainWindow::on_btnZoomMinus_clicked()
{
    //Ausgehend vom aktuellen Zoom verkleinern
    zoom(aktueller_zoom - 1);
}

void MainWindow::on_sldZoom_valueChanged(int value)
{
    zoom(value);
}

void MainWindow::on_textEdit_textChanged()
{
    dirty = true;
}


