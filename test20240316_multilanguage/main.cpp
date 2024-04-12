#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QSettings *myregistry = new QSettings("HKEY_CURRENT_USER\\Software\\QtApp", QSettings::NativeFormat);
    QString language = myregistry->value("lang","de").toString();
    QTranslator translator;
    if(language == "de")    w.on_actionDE_triggered();
    else                    w.on_actionUS_triggered();


    w.show();
    return a.exec();
}
