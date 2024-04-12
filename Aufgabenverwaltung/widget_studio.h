#ifndef WIDGET_STUDIO_H
#define WIDGET_STUDIO_H

#include <QWidget>

namespace Ui {
class Widget_Studio;
}

class Widget_Studio : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Studio(QWidget *parent = nullptr);
    ~Widget_Studio();

private slots:


    void on_pushButton_Laden_clicked();

    void on_pushButton_Leeren_clicked();

private:
    Ui::Widget_Studio *ui;
};

#endif // WIDGET_STUDIO_H
