#ifndef DIALOG_STARTER_H
#define DIALOG_STARTER_H

#include <QDialog>

namespace Ui {
class Dialog_Starter;
}

class Dialog_Starter : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Starter(QWidget *parent = nullptr);
    ~Dialog_Starter();

private:
    Ui::Dialog_Starter *ui;
};

#endif // DIALOG_STARTER_H
