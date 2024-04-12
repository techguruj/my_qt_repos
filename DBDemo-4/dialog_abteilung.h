#ifndef DIALOG_ABTEILUNG_H
#define DIALOG_ABTEILUNG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QTableWidget>

namespace Ui {
class Dialog_Abteilung;
}

class Dialog_Abteilung : public QDialog
{
    Q_OBJECT
    int rowsInDatabase;
    QString origialText;
    QSqlRelationalTableModel *relational_tabelmodel;



public:
    explicit Dialog_Abteilung(QWidget *parent = nullptr);
    ~Dialog_Abteilung();

private slots:


    bool on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_Abteilung *ui;
};

#endif // DIALOG_ABTEILUNG_H
