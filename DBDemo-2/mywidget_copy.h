#ifndef MYWIDGET_COPY_H
#define MYWIDGET_COPY_H

#include <QWidget>

namespace Ui {
class mywidget_copy;
}

class mywidget_copy : public QWidget
{
    Q_OBJECT

public:
    explicit mywidget_copy(QWidget *parent = nullptr);
    ~mywidget_copy();

private:
    Ui::mywidget_copy *ui;
};

#endif // MYWIDGET_COPY_H
