#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Neues_Dokument_triggered();
    void on_action_Oeffnen_triggered();
    void on_action_Speichern_triggered();
    bool on_action_Speichern_unter_triggered();
    void on_action_Vorschau_triggered();
    void on_action_Druck_triggered();
    void on_action_Beenden_triggered();
    void on_action_Rueckgaengig_triggered();
    void on_action_Wiederholen_triggered();
    void on_action_Ausschneiden_triggered();
    void on_action_Kopieren_triggered();
    void on_action_Einfuegen_triggered();
    void on_action_Suchen_triggered();
    void on_action_Ersetzen_triggered();
    void on_action_Schriftart_triggered();
    void on_action_Vordergrund_triggered();
    void on_action_Optionen_triggered();
    void on_action_Deutsch_triggered();
    void on_action_Englisch_triggered();
    void on_action_100_triggered();
    void on_action_200_triggered();
    void on_action_300_triggered();
    void on_action_400_triggered();
    void on_action_800_triggered();
    void on_action_1600_triggered();
    void on_action_3200_triggered();

    void on_btnZoomPlus_clicked();

    void on_btnZoomMinus_clicked();

    void on_sldZoom_valueChanged(int value);

    void on_textEdit_textChanged();

    void on_action_Direkt_Drucken_triggered();

    void on_action_Hintergrund_triggered();

private:
    Ui::MainWindow *ui;

    int aktueller_zoom = 1;       //private variables
    QString filename;
    QString filepath;
    QString filter;
    bool dirty;
    QPrinter printer;
    QSettings * registry;

                                    //private methods
    void zoom(int wunschzoom);
    bool checkDirty();
    bool save();
    void setTitle(QString value  = "Neues Dokument");
    void adjustLanguage(QString lang);

};
#endif // MAINWINDOW_H
