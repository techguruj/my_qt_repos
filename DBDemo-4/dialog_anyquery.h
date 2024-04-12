#ifndef DIALOG_ANYQUERY_H
#define DIALOG_ANYQUERY_H

#include <QDialog>

namespace Ui {
class Dialog_anyquery;
}

class Dialog_anyquery : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_anyquery(QWidget *parent = nullptr);
    ~Dialog_anyquery();

private:
    Ui::Dialog_anyquery *ui;
};

#endif // DIALOG_ANYQUERY_H
