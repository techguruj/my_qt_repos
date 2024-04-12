#include "mainwindow.h"
#include <QSettings>
#include <QTranslator>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Spracheinstellungen U N B E D I N G T zwischen erstewllung des Application-Objekts und Window-Objekts einbinden
    QSettings *registry = new QSettings("HKEY_CURRENT_USER/Software/Graf_Editor", QSettings::IniFormat);
    QString lang = registry->value("lang").toString();
    qDebug() << lang;
    QTranslator translator;

    translator.load("C:/Users/q/Documents/qt_repos/Graf_Editor-2/translate_en.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
