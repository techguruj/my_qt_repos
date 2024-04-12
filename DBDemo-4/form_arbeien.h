#ifndef FORM_ARBEIEN_H
#define FORM_ARBEIEN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class Form_Arbeien;
}

class Form_Arbeien : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Arbeien(QWidget *parent = nullptr);

    ~Form_Arbeien();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Form_Arbeien *ui;
};

#endif // FORM_ARBEIEN_H
