#include "widget.h"
#include "dialog_abteilung.h"
#include "dialog_allquery.h"
#include "widget_copy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    Widget w;
    //Dialog_Abteilung w;
    //Dialog_allquery w;
    //Form_Arbeien w;
    w.show();
    return a.exec();
}
