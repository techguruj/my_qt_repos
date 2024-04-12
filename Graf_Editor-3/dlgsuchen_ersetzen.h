#ifndef DLGSUCHEN_ERSETZEN_H
#define DLGSUCHEN_ERSETZEN_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class DlgSuchen_Ersetzen;
}

class DlgSuchen_Ersetzen : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSuchen_Ersetzen(QWidget *parent = nullptr, bool erweitert = false, QTextEdit * mainwindow_textedit = nullptr);
    ~DlgSuchen_Ersetzen();

private slots:
    void on_btnErweitern_clicked(bool erweitern = false);

    bool on_btnSuchen_clicked(bool rueckwaerts_beachten = true);

    void on_leSuchbegriff_textChanged(const QString &arg1);

    void on_btnErsetzen_clicked(bool weitersuchen = true);

    void on_btnAllesErsetzen_clicked();

private:
    Ui::DlgSuchen_Ersetzen *ui;

    QTextEdit * textEditAusMainWindow;
};

#endif // DLGSUCHEN_ERSETZEN_H
