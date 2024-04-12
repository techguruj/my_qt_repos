#ifndef WIDGET_Edit_H
#define WIDGET_Edit_H

#include <QItemSelectionModel>
#include <QSqlRelationalTableModel>
#include <QWidget>

namespace Ui {
class Widget_Edit;
}

class Widget_Edit : public QWidget
{
    Q_OBJECT
    QSqlRelationalTableModel *relationalmodel;
    QItemSelectionModel *selectionModel;

public:
    explicit Widget_Edit(QWidget *parent = nullptr);
    ~Widget_Edit();

private slots:
    void on_pushButton_Hochladen_clicked();

    void on_pushButton_UndoAll_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_Beenden_clicked();

private:
    Ui::Widget_Edit *ui;
};

#endif // WIDGET_Edit_H
