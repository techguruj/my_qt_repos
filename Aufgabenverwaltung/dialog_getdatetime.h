#ifndef DIALOG_GETDATETIME_H
#define DIALOG_GETDATETIME_H

#include <QDateTime>
#include <QDialog>
#include <QDate>

namespace Ui {
class Dialog_getDatetime;
}

class Dialog_getDatetime : public QDialog
{
    Q_OBJECT

public:
    QDateTime temp_Datetime;
    explicit Dialog_getDatetime(QWidget *parent = nullptr, QString anweisung="");
    ~Dialog_getDatetime();

private slots:

    void on_pushButton_Jetzt_clicked();

    void on_pushButton_Uebernehmen_clicked();

private:
    Ui::Dialog_getDatetime *ui;
};

#endif // DIALOG_GETDATETIME_H
