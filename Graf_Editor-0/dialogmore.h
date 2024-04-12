#ifndef DIALOGMORE_H
#define DIALOGMORE_H

#include <QDialog>

namespace Ui {
class Dialogmore;
}

class Dialogmore : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogmore(QWidget *parent = nullptr);
    ~Dialogmore();

private:
    Ui::Dialogmore *ui;
};

#endif // DIALOGMORE_H
