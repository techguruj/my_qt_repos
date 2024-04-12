#ifndef MYWIDGET_H
#define MYWIDGET_H

/*





*/


#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class myWidget : public QWidget
{
    Q_OBJECT
    QLabel      *LabelBild                  ;
    QFormLayout *FormlayoutUsernamePassword ;
    QLineEdit   *Lineeditusername           ;
    QLineEdit   *Lineeditpassword           ;
    QPushButton *PushbuttonOk               ;
    QPushButton *PushbuttonAbort            ;
    QGridLayout *GridlayoutAlles            ;
    int         logincount;

private slots:
    void loginfunction();

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
#endif // MYWIDGET_H
