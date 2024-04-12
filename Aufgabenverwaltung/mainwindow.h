#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QActionGroup>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QActionGroup *languageActionGroup;
    QTranslator translator;


public:

    QDateTime *Sintflut_Datetime = new QDateTime(QDateTime::fromString("30/12/9999 23:59:59", "dd/MM/yyyy HH:mm:ss"));

    enum class Status
    {
        UNERLEDIGT  =0,
        IN_ARBEIT   =1,
        ERLEDIGT    =2
    };

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void refreschUI();

private slots:
    void on_pushButton_1_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionNeu_Aufgabe_triggered();

    void on_actionProjekteninfo_triggered();

    void on_actionStudio_triggered();



    void on_actionAktualisierung_triggered();

 public slots:

    void on_actionDE_triggered();

    void on_actionUS_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
