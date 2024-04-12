#ifndef DLGNICHTMODAL_H
#define DLGNICHTMODAL_H

#include <QDialog>

namespace Ui {
class DlgNichtModal;
}

class DlgNichtModal : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNichtModal(QWidget *parent = nullptr);
    ~DlgNichtModal();

private:
    Ui::DlgNichtModal *ui;
};

#endif // DLGNICHTMODAL_H
