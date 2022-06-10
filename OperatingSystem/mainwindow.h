#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_katalog_1_clicked();
    void on_katalog_2_clicked();
    void on_katalog_3_clicked();
    void on_katalog_4_clicked();
    void on_checkBox_katalogi_toggled(bool checked);
    void on_actionzakoncz_triggered();
    void on_pushButton_dodaj_clicked();
    void on_pushButton_zasoby_clicked();
    void on_actionzapisz_triggered();
    void on_pushButton_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_wyniki_clicked();
    void on_pushButton_losuj_clicked();
    void on_pushButton_search_clicked();

private:
    Ui::MainWindow *ui;
    bool checked1=false;
    bool checked2=false;
    bool checked3=false;
    bool checked4=false;

    QString katalog[4];//przechowuje zawartosc listy katalogu 1-4
    float wielkosc[4][4];//[katalog1/katalog2/katalog3/katalog4][txt/jpeg/png/pdf]
    int item[4];//indeks listy (losowanie wartosci)[txt/jpeg/png/pdf]
    int iloscWierszy[4];//ilosc wierszy dla list (indeksy wierszy)
};
#endif // MAINWINDOW_H
