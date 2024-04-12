#ifndef DLGOPTIONEN_H
#define DLGOPTIONEN_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class DlgOptionen;
}

class DlgOptionen : public QDialog
{
    Q_OBJECT

    QSettings *registry;

public:
    explicit DlgOptionen(QWidget *parent = nullptr);
    ~DlgOptionen();

private slots:

    void on_rdDeutsch_clicked();

    void on_rdEnglisch_clicked();

private:
    Ui::DlgOptionen *ui;
};

#endif // DLGOPTIONEN_H
