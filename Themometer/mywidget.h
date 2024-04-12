#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QPixmap>
#include <QIcon>

class myWidget : public QWidget
{
    Q_OBJECT

private:
    QLabel          *labelBilder                    ;
    QPixmap         *pixmap                         ;
    QGroupBox       *groupBoxArt                    ;
    QRadioButton    *radioButtonCelsiustoFahrenheit ;
    QRadioButton    *radioButtonFahrenheittoCelsius ;
    QFormLayout     *formLayout                     ;
    QCheckBox       *checkBox2Nachkommastellen      ;
    QVBoxLayout     *vboxLayoutMitte                ;
    QVBoxLayout     *vboxLayoutRechts               ;
    QHBoxLayout     *hboxLayoutAlles                ;
    QLineEdit       *lineEditOben                   ;
    QLineEdit       *lineEditUnten                  ;
    QHBoxLayout     *hboxLayoutArt                  ;
    QPushButton     *pushButtonClear                ;
    QPushButton     *pushButtonBerechnen            ;
    QPushButton     *pushButtonSchliessen           ;
    QIcon           *icon                           ;
    double          celsius                         ;
    double          fahrenheit                      ;
    bool            *toDoubleOK                     ;

private slots:
    void celsisuto_Fahrenheit();
    void fahrenheitto_Celsius();
    void CelOrFahren();


public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();




};
#endif // MYWIDGET_H
