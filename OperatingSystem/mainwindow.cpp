#include "mainwindow.h"
#include "ui_mainwindow.h"

//biblioteki zapisu do plikow
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

//biblioteki otawrcia drugiego okna
#include <chartdialog.h>

//losowanie liczb
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //poczatkowe ustawienia managera katalagow
    ui->checkBox_katalogi->setChecked(true);

    //wyzerowanie zmiennych programowych
    wielkosc[0][0]=0;   wielkosc[0][1]=0;   wielkosc[0][2]=0;   wielkosc[0][3]=0;
    wielkosc[1][0]=0;   wielkosc[1][1]=0;   wielkosc[1][2]=0;   wielkosc[1][3]=0;
    wielkosc[2][0]=0;   wielkosc[2][1]=0;   wielkosc[2][2]=0;   wielkosc[2][3]=0;
    wielkosc[3][0]=0;   wielkosc[3][1]=0;   wielkosc[3][2]=0;   wielkosc[3][3]=0;

    //wyzerowanie indeksow itemow
    item[0]=0;  item[1]=0;  item[2]=0;  item[3]=0;

    //ukrycie przyciskow funkcyjnych programu
    ui->pushButton_zasoby->setVisible(false);
    ui->pushButton_save->   setVisible(false);
    ui->pushButton_wyniki-> setVisible(false);
    ui->pushButton_wyniki->click();

    //inicjalizacja randomowego seed'a
    srand(time(NULL));

    //dodanie naglowkow do tabel
    QStringList labels;
    labels<<"Nazwa"<<"Wielkosc [Mb]"<<"Prawa";
    ui->tableWidget_katalog1->setColumnCount(3);
    ui->tableWidget_katalog2->setColumnCount(3);
    ui->tableWidget_katalog3->setColumnCount(3);
    ui->tableWidget_katalog4->setColumnCount(3);

    ui->tableWidget_katalog1->setHorizontalHeaderLabels(labels);
    ui->tableWidget_katalog2->setHorizontalHeaderLabels(labels);
    ui->tableWidget_katalog3->setHorizontalHeaderLabels(labels);
    ui->tableWidget_katalog4->setHorizontalHeaderLabels(labels);

    //wyzerowanie indeksow ilosci wierszy w tabelach
    iloscWierszy[0]=0;  iloscWierszy[1]=0;  iloscWierszy[2]=0;  iloscWierszy[3]=0;
}

void MainWindow::on_katalog_1_clicked()
{//przejscie do katalogu 1
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_katalog_2_clicked()
{//przejscie do katalogu 2
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_katalog_3_clicked()
{//przejscie do katalogu 3
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_katalog_4_clicked()
{//przejscie do katalogu 4
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_checkBox_katalogi_toggled(bool checked)
{//[ukrycie/wlaczenie] widocznosci menagera katalogow
    ui->groupBox_katalogi->setVisible(checked);
}

void MainWindow::on_actionzakoncz_triggered()
{//wyjscie z programu
    exit(0);
}

void MainWindow::on_pushButton_dodaj_clicked()
{
    ui->pushButton_save->click();

    //wprowadzenie linii danych do odpowiedniego katalogu
    if(ui->comboBox_katalog->currentIndex()==0){
        //dodanie rekordu do tabeli
        ui->tableWidget_katalog1->insertRow(iloscWierszy[0]);
            QTableWidgetItem *nazwa = new QTableWidgetItem;
            QTableWidgetItem *rozmiar = new QTableWidgetItem;
            QTableWidgetItem *prawa = new QTableWidgetItem;

                nazwa->setText(ui->lineEdit_nazwa->text()+ui->comboBox_format->currentText());
                rozmiar->setText(QString::number(ui->lineEdit_wielkosc->text().toFloat()));
                prawa->setText(QString::number(ui->lineEdit_prawa->text().toInt()));

            ui->tableWidget_katalog1->setItem(iloscWierszy[0],0,nazwa);
            ui->tableWidget_katalog1->setItem(iloscWierszy[0],1,rozmiar);
            ui->tableWidget_katalog1->setItem(iloscWierszy[0],2,prawa);
        iloscWierszy[0]++;

        //dodanie wielkosci katalogu do zmiennych programowych [klamry sa niepotrzebne dla wyrazen jednoliniowych]
             if(ui->comboBox_format->currentIndex()==0)  wielkosc[0][0]+=ui->lineEdit_wielkosc->text().toFloat();//txt
        else if(ui->comboBox_format->currentIndex()==1)  wielkosc[0][1]+=ui->lineEdit_wielkosc->text().toFloat();//jpeg
        else if(ui->comboBox_format->currentIndex()==2)  wielkosc[0][2]+=ui->lineEdit_wielkosc->text().toFloat();//png
        else if(ui->comboBox_format->currentIndex()==3)  wielkosc[0][3]+=ui->lineEdit_wielkosc->text().toFloat();//pdf
    }
    else if(ui->comboBox_katalog->currentIndex()==1){
        //dodanie rekordu do tabeli
        ui->tableWidget_katalog2->insertRow(iloscWierszy[1]);
            QTableWidgetItem *nazwa = new QTableWidgetItem;
            QTableWidgetItem *rozmiar = new QTableWidgetItem;
            QTableWidgetItem *prawa = new QTableWidgetItem;

                nazwa->setText(ui->lineEdit_nazwa->text()+ui->comboBox_format->currentText());
                rozmiar->setText(QString::number(ui->lineEdit_wielkosc->text().toFloat()));
                prawa->setText(QString::number(ui->lineEdit_prawa->text().toInt()));

            ui->tableWidget_katalog2->setItem(iloscWierszy[1],0,nazwa);
            ui->tableWidget_katalog2->setItem(iloscWierszy[1],1,rozmiar);
            ui->tableWidget_katalog2->setItem(iloscWierszy[1],2,prawa);
        iloscWierszy[1]++;

        //dodanie wielkosci katalogu do zmiennych programowych [klamry sa niepotrzebne dla wyrazen jednoliniowych]
             if(ui->comboBox_format->currentIndex()==0) wielkosc[1][0]+=ui->lineEdit_wielkosc->text().toFloat();//txt
        else if(ui->comboBox_format->currentIndex()==1) wielkosc[1][1]+=ui->lineEdit_wielkosc->text().toFloat();//jpeg
        else if(ui->comboBox_format->currentIndex()==2) wielkosc[1][2]+=ui->lineEdit_wielkosc->text().toFloat();//png
        else if(ui->comboBox_format->currentIndex()==3) wielkosc[1][3]+=ui->lineEdit_wielkosc->text().toFloat();//pdf
    }
    else if(ui->comboBox_katalog->currentIndex()==2){
        //dodanie rekordu do tabeli
        ui->tableWidget_katalog3->insertRow(iloscWierszy[2]);
            QTableWidgetItem *nazwa = new QTableWidgetItem;
            QTableWidgetItem *rozmiar = new QTableWidgetItem;
            QTableWidgetItem *prawa = new QTableWidgetItem;

                nazwa->setText(ui->lineEdit_nazwa->text()+ui->comboBox_format->currentText());
                rozmiar->setText(QString::number(ui->lineEdit_wielkosc->text().toFloat()));
                prawa->setText(QString::number(ui->lineEdit_prawa->text().toInt()));

            ui->tableWidget_katalog3->setItem(iloscWierszy[2],0,nazwa);
            ui->tableWidget_katalog3->setItem(iloscWierszy[2],1,rozmiar);
            ui->tableWidget_katalog3->setItem(iloscWierszy[2],2,prawa);
        iloscWierszy[2]++;

        //dodanie wielkosci katalogu do zmiennych programowych [klamry sa niepotrzebne dla wyrazen jednoliniowych]
             if(ui->comboBox_format->currentIndex()==0) wielkosc[2][0]+=ui->lineEdit_wielkosc->text().toFloat();//txt
        else if(ui->comboBox_format->currentIndex()==1) wielkosc[2][1]+=ui->lineEdit_wielkosc->text().toFloat();//jpeg
        else if(ui->comboBox_format->currentIndex()==2) wielkosc[2][2]+=ui->lineEdit_wielkosc->text().toFloat();//png
        else if(ui->comboBox_format->currentIndex()==3) wielkosc[2][3]+=ui->lineEdit_wielkosc->text().toFloat();//pdf
    }
    else if(ui->comboBox_katalog->currentIndex()==3){
        //dodanie rekordu do tabeli
        ui->tableWidget_katalog4->insertRow(iloscWierszy[3]);
            QTableWidgetItem *nazwa = new QTableWidgetItem;
            QTableWidgetItem *rozmiar = new QTableWidgetItem;
            QTableWidgetItem *prawa = new QTableWidgetItem;

                nazwa->setText(ui->lineEdit_nazwa->text()+ui->comboBox_format->currentText());
                rozmiar->setText(QString::number(ui->lineEdit_wielkosc->text().toFloat()));
                prawa->setText(QString::number(ui->lineEdit_prawa->text().toInt()));

            ui->tableWidget_katalog4->setItem(iloscWierszy[3],0,nazwa);
            ui->tableWidget_katalog4->setItem(iloscWierszy[3],1,rozmiar);
            ui->tableWidget_katalog4->setItem(iloscWierszy[3],2,prawa);
        iloscWierszy[3]++;

        //dodanie wielkosci katalogu do zmiennych programowych [klamry sa niepotrzebne dla wyrazen jednoliniowych]
             if(ui->comboBox_format->currentIndex()==0) wielkosc[3][0]+=ui->lineEdit_wielkosc->text().toFloat();//txt
        else if(ui->comboBox_format->currentIndex()==1) wielkosc[3][1]+=ui->lineEdit_wielkosc->text().toFloat();//jpeg
        else if(ui->comboBox_format->currentIndex()==2) wielkosc[3][2]+=ui->lineEdit_wielkosc->text().toFloat();//png
        else if(ui->comboBox_format->currentIndex()==3) wielkosc[3][3]+=ui->lineEdit_wielkosc->text().toFloat();//pdf
    }

    //aktualizacja managera zasobow (slaba nazwa przycisku)
    ui->pushButton_zasoby->click();
    //zapisanie do pliku ogolnego
    ui->actionzapisz->trigger();
    //zaladowanie zawartosci pliku wyniki.txt do podgladu
    ui->pushButton_wyniki->click();
}


void MainWindow::on_pushButton_zasoby_clicked()
{//wstawienie wartosci do tabeli menagera zasobow
    ui->kat1_txt ->setText(QString::number(wielkosc[0][0]));
    ui->kat1_jpeg->setText(QString::number(wielkosc[0][1]));
    ui->kat1_png ->setText(QString::number(wielkosc[0][2]));
    ui->kat1_pdf ->setText(QString::number(wielkosc[0][3]));

    ui->kat2_txt ->setText(QString::number(wielkosc[1][0]));
    ui->kat2_jpeg->setText(QString::number(wielkosc[1][1]));
    ui->kat2_png ->setText(QString::number(wielkosc[1][2]));
    ui->kat2_pdf ->setText(QString::number(wielkosc[1][3]));

    ui->kat3_txt ->setText(QString::number(wielkosc[2][0]));
    ui->kat3_jpeg->setText(QString::number(wielkosc[2][1]));
    ui->kat3_png ->setText(QString::number(wielkosc[2][2]));
    ui->kat3_pdf ->setText(QString::number(wielkosc[2][3]));

    ui->kat4_txt ->setText(QString::number(wielkosc[3][0]));
    ui->kat4_jpeg->setText(QString::number(wielkosc[3][1]));
    ui->kat4_png ->setText(QString::number(wielkosc[3][2]));
    ui->kat4_pdf ->setText(QString::number(wielkosc[3][3]));
}


void MainWindow::on_actionzapisz_triggered()
{//zapis do pliku calkowitego wyniki.txt
    QFile file(QCoreApplication::applicationDirPath()+"/wyniki.txt");//"C:/Users/EliteBook/Desktop/wyniki.txt"
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            qDebug()<<"Could not open file for writing";
            return;
        }
        QTextStream out (&file);
        out<<"Wielkosc poszczegolnych typow plikow w katalogach [Mb]:\n";

        out<<"# Katalog 1:\t[lacznie:"<<wielkosc[0][0]+wielkosc[0][1]+wielkosc[0][2]+wielkosc[0][3]<<"Mb]\n";
        out<<"\t-txt:" <<wielkosc[0][0]<<" Mb\n";
        out<<"\t-jpeg:"<<wielkosc[0][1]<<" Mb\n";
        out<<"\t-png:" <<wielkosc[0][2]<<" Mb\n";
        out<<"\t-pdf:" <<wielkosc[0][3]<<" Mb\n\n";

        out<<"# Katalog 2:\t[lacznie:"<<wielkosc[1][0]+wielkosc[1][1]+wielkosc[1][2]+wielkosc[1][3]<<"Mb]\n";
        out<<"\t-txt:" <<wielkosc[1][0]<<" Mb\n";
        out<<"\t-jpeg:"<<wielkosc[1][1]<<" Mb\n";
        out<<"\t-png:" <<wielkosc[1][2]<<" Mb\n";
        out<<"\t-pdf:" <<wielkosc[1][3]<<" Mb\n\n";

        out<<"# Katalog 3:\t[lacznie:"<<wielkosc[2][0]+wielkosc[2][1]+wielkosc[2][2]+wielkosc[2][3]<<"Mb]\n";
        out<<"\t-txt:" <<wielkosc[2][0]<<" Mb\n";
        out<<"\t-jpeg:"<<wielkosc[2][1]<<" Mb\n";
        out<<"\t-png:" <<wielkosc[2][2]<<" Mb\n";
        out<<"\t-pdf:" <<wielkosc[2][3]<<" Mb\n\n";

        out<<"# Katalog 4:\t[lacznie:"<<wielkosc[3][0]+wielkosc[3][1]+wielkosc[3][2]+wielkosc[3][3]<<"Mb]\n";
        out<<"\t-txt:" <<wielkosc[3][0]<<" Mb\n";
        out<<"\t-jpeg:"<<wielkosc[3][1]<<" Mb\n";
        out<<"\t-png:" <<wielkosc[3][2]<<" Mb\n";
        out<<"\t-pdf:" <<wielkosc[3][3]<<" Mb\n\n";

        file.flush();
        file.close();
}

void MainWindow::on_pushButton_clicked()
{//otwarcie drugiego okna (do wygenerowania wykresu)
    ui->pushButton_save->click();
        ChartDialog oknoWykres;
        oknoWykres.setModal(true);
        oknoWykres.exec();
}

void MainWindow::on_pushButton_save_clicked()
{//zapisanie do pliku funkcyjnego (na podstawie ktorego bedzie generowany wykres)
//wielkosc[4][4];//[katalog][txt/jpeg/png/pdf]

    //zapisanie stanu do katalog.txt
    QFile file(QCoreApplication::applicationDirPath()+"/katalog.txt");
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            qDebug()<<"Could not open file for writing";
            return;
        }
        QTextStream out (&file);
        out<<wielkosc[0][0]<<"\n";
        out<<wielkosc[0][1]<<"\n";
        out<<wielkosc[0][2]<<"\n";
        out<<wielkosc[0][3]<<"\n";

        out<<wielkosc[1][0]<<"\n";
        out<<wielkosc[1][1]<<"\n";
        out<<wielkosc[1][2]<<"\n";
        out<<wielkosc[1][3]<<"\n";

        out<<wielkosc[2][0]<<"\n";
        out<<wielkosc[2][1]<<"\n";
        out<<wielkosc[2][2]<<"\n";
        out<<wielkosc[2][3]<<"\n";

        out<<wielkosc[3][0]<<"\n";
        out<<wielkosc[3][1]<<"\n";
        out<<wielkosc[3][2]<<"\n";
        out<<wielkosc[3][3]<<"\n";
        file.flush();
        file.close();
}

void MainWindow::on_pushButton_wyniki_clicked()
{//wyswietlenie zawartosci pliku wyniki.txt
    QFile file(QCoreApplication::applicationDirPath()+"/wyniki.txt");//"C:/Users/EliteBook/Desktop/wyniki.txt"
        if(!file.open(QFile::ReadOnly | QFile::Text)){
            qDebug()<<"Could not open {wyniki.txt}";
            return;
        }
        QTextStream in (&file);
        ui->textEdit_wyniki->setText(in.readAll());
        file.close();
}

void MainWindow::on_pushButton_losuj_clicked()
{//wygenerowanie losowych plikow
    QStringList losowanieTXT;
    QStringList losowanieJPEG;
    QStringList losowaniePNG;
    QStringList losowaniePDF;
    int losowanieIndeks=0;

    losowanieTXT <<"notatka"   <<"dokument"  <<"zapisek"     <<"uwaga"         <<"dziennik"<<"kajet"   <<"dowód"    <<"akt";//[0-7]
    losowanieJPEG<<"obrazek"   <<"zdjecie"   <<"fotografia"  <<"widok"         <<"portret" <<"panorama"<<"sceneria";        //[0-6]
    losowaniePNG <<"rysunek"   <<"ilustracja"<<"rycina"      <<"malunek"       <<"skan"    <<"pejzaż"  <<"plener";          //[0-6]
    losowaniePDF <<"swiadectwo"<<"certyfikat"<<"zaswiadczenie"<<"druk urzedowy"<<"akt"     <<"dyplom"  <<"licencja" <<"atest";//[0-7]

    //katalog 1-4
    for(int a=0;a<4;a++){

        //zmiana katalogu
        switch(losowanieIndeks){
        case 0:
            ui->comboBox_katalog->setCurrentIndex(0);
            break;
        case 1:
            ui->comboBox_katalog->setCurrentIndex(1);
            break;
        case 2:
            ui->comboBox_katalog->setCurrentIndex(2);
            break;
        case 3:
            ui->comboBox_katalog->setCurrentIndex(3);
            break;
        }

        //txt
        for(int b=0;b<4;b++){
            ui->lineEdit_nazwa->setText(losowanieTXT[rand()%8]);
            ui->lineEdit_wielkosc->setText(QString::number(rand()%20+(float(rand())/float((RAND_MAX)) * 5)));
            ui->comboBox_format->setCurrentIndex(0);
            ui->lineEdit_prawa->setText(QString::number(rand()%8+1)+QString::number(rand()%8+1)+QString::number(rand()%8+1));
            ui->pushButton_dodaj->click();//zatwierdzenie przyciskiem
        }
        //jpeg
        for(int b=0;b<4;b++){
            ui->lineEdit_nazwa->setText(losowanieJPEG[rand()%7]);
            ui->lineEdit_wielkosc->setText(QString::number(rand()%20+(float(rand())/float((RAND_MAX)) * 5)));
            ui->comboBox_format->setCurrentIndex(1);
            ui->lineEdit_prawa->setText(QString::number(rand()%8+1)+QString::number(rand()%8+1)+QString::number(rand()%8+1));
            ui->pushButton_dodaj->click();//zatwierdzenie przyciskiem
        }
        //png
        for(int b=0;b<4;b++){
            ui->lineEdit_nazwa->setText(losowaniePNG[rand()%7]);
            ui->lineEdit_wielkosc->setText(QString::number(rand()%20+(float(rand())/float((RAND_MAX)) * 5)));
            ui->comboBox_format->setCurrentIndex(2);
            ui->lineEdit_prawa->setText(QString::number(rand()%8+1)+QString::number(rand()%8+1)+QString::number(rand()%8+1));
            ui->pushButton_dodaj->click();//zatwierdzenie przyciskiem
        }
        //pdf
        for(int b=0;b<4;b++){
            ui->lineEdit_nazwa->setText(losowaniePDF[rand()%8]);
            ui->lineEdit_wielkosc->setText(QString::number(rand()%20+(float(rand())/float((RAND_MAX)) * 5)));
            ui->comboBox_format->setCurrentIndex(3);
            ui->lineEdit_prawa->setText(QString::number(rand()%8+1)+QString::number(rand()%8+1)+QString::number(rand()%8+1));
            ui->pushButton_dodaj->click();//zatwierdzenie przyciskiem
        }
        losowanieIndeks++;
    }

    //wyczyszczenie formularza
    ui->comboBox_katalog->setCurrentIndex(0);
    ui->lineEdit_nazwa->setText("");
    ui->lineEdit_wielkosc->setText("");
    ui->comboBox_format->setCurrentIndex(0);
    ui->lineEdit_prawa->setText("");
}

void MainWindow::on_pushButton_search_clicked()
{//wyszukiwanie pliku o danej nazwie
    if(ui->lineEdit_search->text()==""){
        ui->lineEdit_search->setText("Input your search");
            for(int a=0;a<ui->tableWidget_katalog1->rowCount();a++){    ui->tableWidget_katalog1->setRowHidden(a,false);    }
            for(int a=0;a<ui->tableWidget_katalog2->rowCount();a++){    ui->tableWidget_katalog2->setRowHidden(a,false);    }
            for(int a=0;a<ui->tableWidget_katalog3->rowCount();a++){    ui->tableWidget_katalog3->setRowHidden(a,false);    }
            for(int a=0;a<ui->tableWidget_katalog4->rowCount();a++){    ui->tableWidget_katalog4->setRowHidden(a,false);    }
        return;
    }

    for(int a=0;a<ui->tableWidget_katalog1->rowCount();a++){    ui->tableWidget_katalog1->hideRow(a);   }
    for(int a=0;a<ui->tableWidget_katalog2->rowCount();a++){    ui->tableWidget_katalog2->hideRow(a);   }
    for(int a=0;a<ui->tableWidget_katalog3->rowCount();a++){    ui->tableWidget_katalog3->hideRow(a);   }
    for(int a=0;a<ui->tableWidget_katalog4->rowCount();a++){    ui->tableWidget_katalog4->hideRow(a);   }

    for(int a=0;a<ui->tableWidget_katalog1->rowCount();a++){
        QString row;
        row.append(ui->tableWidget_katalog1->item(a,0)->text());
        row.append(ui->tableWidget_katalog1->item(a,1)->text());
        row.append(ui->tableWidget_katalog1->item(a,2)->text());
        if(row.contains(ui->lineEdit_search->text())){
            ui->tableWidget_katalog1->setRowHidden(a,false);
        }
    }
    for(int a=0;a<ui->tableWidget_katalog2->rowCount();a++){
        QString row;
        row.append(ui->tableWidget_katalog2->item(a,0)->text());
        row.append(ui->tableWidget_katalog2->item(a,1)->text());
        row.append(ui->tableWidget_katalog2->item(a,2)->text());
        if(row.contains(ui->lineEdit_search->text())){
            ui->tableWidget_katalog2->setRowHidden(a,false);
        }
    }
    for(int a=0;a<ui->tableWidget_katalog3->rowCount();a++){
        QString row;
        row.append(ui->tableWidget_katalog3->item(a,0)->text());
        row.append(ui->tableWidget_katalog3->item(a,1)->text());
        row.append(ui->tableWidget_katalog3->item(a,2)->text());
        if(row.contains(ui->lineEdit_search->text())){
            ui->tableWidget_katalog3->setRowHidden(a,false);
        }
    }
    for(int a=0;a<ui->tableWidget_katalog4->rowCount();a++){
        QString row;
        row.append(ui->tableWidget_katalog4->item(a,0)->text());
        row.append(ui->tableWidget_katalog4->item(a,1)->text());
        row.append(ui->tableWidget_katalog4->item(a,2)->text());
        if(row.contains(ui->lineEdit_search->text())){
            ui->tableWidget_katalog4->setRowHidden(a,false);
        }
    }
}


MainWindow::~MainWindow(){   delete ui;  }
