#ifndef MYWIDGET_COPY2_H
#define MYWIDGET_COPY2_H

#include <QWidget>

namespace Ui {
class mywidget_copy2;
}

class mywidget_copy2 : public QWidget
{
    Q_OBJECT

public:
    explicit mywidget_copy2(QWidget *parent = nullptr);
    ~mywidget_copy2();

private:
    Ui::mywidget_copy2 *ui;
};

#endif // MYWIDGET_COPY2_H
