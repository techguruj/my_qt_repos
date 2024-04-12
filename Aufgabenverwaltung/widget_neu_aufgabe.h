#ifndef WIDGET_NEU_AUFGABE_H
#define WIDGET_NEU_AUFGABE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Widget_Neu_Aufgabe;
}

class Widget_Neu_Aufgabe : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Neu_Aufgabe(QWidget *parent = nullptr);
    int holenNextID();
    ~Widget_Neu_Aufgabe();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_Speichern_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::Widget_Neu_Aufgabe *ui;
};

#endif // WIDGET_NEU_AUFGABE_H
