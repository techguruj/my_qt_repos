#include "widget.h"
//#include "widget_copy.h"
#include "mywidget.h"
#include "mywidget_copy2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //Widget_copy w;
    mywidget_copy2 w;
    w.show();
    return a.exec();
}
