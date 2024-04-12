#include "dlgsuchen_ersetzen.h"
#include "ui_dlgsuchen_ersetzen.h"

DlgSuchen_Ersetzen::DlgSuchen_Ersetzen(QWidget *parent, bool erweitert, QTextEdit * mainwindow_textedit) :
    QDialog(parent),
    ui(new Ui::DlgSuchen_Ersetzen)
{
    ui->setupUi(this);

    on_btnErweitern_clicked(erweitert);
    textEditAusMainWindow = mainwindow_textedit;
}

DlgSuchen_Ersetzen::~DlgSuchen_Ersetzen()
{
    delete ui;
}

void DlgSuchen_Ersetzen::on_btnErweitern_clicked(bool erweitern)
{
    ui->btnErweitern->setChecked(erweitern);
    if(ui->btnErweitern->isChecked())
        setFixedHeight(600);
    else
        setFixedHeight(360);
}

bool DlgSuchen_Ersetzen::on_btnSuchen_clicked(bool rueckwaerts_beachten) // Variable erhält als default true
{
    ui->btnSuchen->setText("Weitersuchen");
    QTextDocument::FindFlags findflags;

    //-------------------------------------------------------Suchoptionen einstellen
    //Nur wenn nicht aus <on_btnAllesErsetzen_clicked> aufgerufen wurde beachten
    if(rueckwaerts_beachten && ui->chkRueckwaerts->isChecked())
        findflags = QTextDocument::FindBackward;                            // 0000 0001
    if(ui->chkGrossKlein->isChecked())
        findflags |= QTextDocument::FindCaseSensitively;                    // 0000 0010
    if(ui->chkGanzeWorte->isChecked())                                      // 0000 0011    Summe
        findflags |= QTextDocument::FindWholeWords;                         // 0000 0100

    //-------------------------------------------------------Suche auslösen
    if(textEditAusMainWindow->find(ui->leSuchbegriff->text(), findflags))   // 0000 0111    Summe
        return true;
    else
        return false;
}

void DlgSuchen_Ersetzen::on_leSuchbegriff_textChanged(const QString &arg1)
{
    ui->btnSuchen->setText("Suchen");
}

void DlgSuchen_Ersetzen::on_btnErsetzen_clicked(bool weitersuchen)
{
    //Stelle an der der Cursor steht mit neuem Text versehen
    textEditAusMainWindow->textCursor().insertText(ui->leErsetzenDurch->text());
    if(weitersuchen)
    {
        on_btnSuchen_clicked(); //Automatisches weitersuchen
    }
}

void DlgSuchen_Ersetzen::on_btnAllesErsetzen_clicked()
{
    //Setze den Cursor an den Dokumentanfang
    QTextCursor cursor = textEditAusMainWindow->textCursor();
    cursor.movePosition(QTextCursor::Start);

    //Gib Cursorposition an TextEdit zurück
    textEditAusMainWindow->setTextCursor(cursor);

    //Durchlaufe den Text bis zum Ende und erstze gefundene Suchbegriffe durch Ersetzungsbegriff
    while(on_btnSuchen_clicked(false))  //false = Automatisches weitersuchen unterdrücken
    {
        on_btnErsetzen_clicked(false);  //false = Rückwärtssuche ignorieren
    }
}

