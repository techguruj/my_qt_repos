#ifndef DLGMITARGUMENTBYVALUE_H
#define DLGMITARGUMENTBYVALUE_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString msg, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DLGMITARGUMENTBYVALUE_H
