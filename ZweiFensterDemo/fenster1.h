#ifndef FENSTER1_H
#define FENSTER1_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Fenster1; }
QT_END_NAMESPACE

class Fenster1 : public QWidget
{
    Q_OBJECT

public:
    Fenster1(QWidget *parent = nullptr);
    ~Fenster1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Fenster1 *ui;
};
#endif // FENSTER1_H
