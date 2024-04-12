#ifndef DLGMODAL_H
#define DLGMODAL_H

#include <QDialog>

namespace Ui {
class DlgModal;
}

class DlgModal : public QDialog
{
    Q_OBJECT

public:
    explicit DlgModal(QWidget *parent = nullptr);
    ~DlgModal();

private:
    Ui::DlgModal *ui;
};

#endif // DLGMODAL_H
