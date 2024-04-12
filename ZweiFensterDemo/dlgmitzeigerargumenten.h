#ifndef DLGMITZEIGERARGUMENTEN_H
#define DLGMITZEIGERARGUMENTEN_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class dlgMitZeigerArgumenten;
}

class dlgMitZeigerArgumenten : public QDialog
{
    Q_OBJECT

public:
    dlgMitZeigerArgumenten(QString nachricht, QLineEdit * leVonFenster1);
    dlgMitZeigerArgumenten(QWidget *parent = nullptr);
    ~dlgMitZeigerArgumenten();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dlgMitZeigerArgumenten *ui;
    QLineEdit * leAntwortVonFenster1;
};

#endif // DLGMITZEIGERARGUMENTEN_H
