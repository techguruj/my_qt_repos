#ifndef MYWIDGET_H
#define MYWIDGET_H

/*
//QLabel//QPushButton//QLineEdit//QHBoxLayout//QGridLayout//QVBoxLayout//QSpinBox//QSlider

*Red            ;
*Green          ;
*Blue           ;
*Farbecode      ;
*Platzhalter    ;
*Kopie          ;
*Schreiben      ;
*Beenden        ;
*Farbefenster   ;
---------------------------------------------


 */

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QDebug>



class myWidget : public QWidget
{
    Q_OBJECT

    QLabel      *LabelRed                   ;
    QLabel      *LabelGreen                 ;
    QLabel      *LabelBlue                  ;
    QLabel      *LabelFarbecode             ;
    QLabel      *LabelPlatzhalter           ;
    QLabel      *LabelFarbefenster          ;
    QSlider     *SliderRed                  ;
    QSlider     *SliderGreen                ;
    QSlider     *SliderBlue                 ;
    QSpinBox    *SpinBoxRed                 ;
    QSpinBox    *SpinBoxGreen               ;
    QSpinBox    *SpinBoxBlue                ;
    QPushButton *PushButtonSchreiben        ;
    QPushButton *PushButtonBeenden          ;
    QPushButton *PushButtonKopie            ;
    QLineEdit   *LineEditFarbefenster       ;
    QGridLayout *gridLayoutlinks            ;
    QHBoxLayout *hBoxLayouAlles             ;

private slots:
    void Changecolor(int);
    void InputColor();



public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
#endif // MYWIDGET_H
