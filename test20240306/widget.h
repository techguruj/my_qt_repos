#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>


class Widget : public QWidget
{
    Q_OBJECT
    QSlider      *slider;
    QSpinBox     *spin;
    QHBoxLayout  *hlayout;

        private slots:
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
