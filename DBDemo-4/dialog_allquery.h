#ifndef DIALOG_ALLQUERY_H
#define DIALOG_ALLQUERY_H

#include <QDialog>

namespace Ui {
class Dialog_allquery;
}

class Dialog_allquery : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_allquery(QWidget *parent = nullptr);
    ~Dialog_allquery();

private slots:
    void on_pushButton_Run_clicked();



private:
    Ui::Dialog_allquery *ui;
};

#endif // DIALOG_ALLQUERY_H
