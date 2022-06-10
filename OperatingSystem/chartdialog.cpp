#include "chartdialog.h"
#include "ui_chartdialog.h"

ChartDialog::ChartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartDialog)
{
    ui->setupUi(this);

    //ustawienie zmiennych poczatkowych
    float wielkoscChart[4][4];
    wielkoscChart[0][0]=0;  wielkoscChart[0][1]=0;  wielkoscChart[0][2]=0;  wielkoscChart[0][3]=0;
    wielkoscChart[1][0]=0;  wielkoscChart[1][1]=0;  wielkoscChart[1][2]=0;  wielkoscChart[1][3]=0;
    wielkoscChart[2][0]=0;  wielkoscChart[2][1]=0;  wielkoscChart[2][2]=0;  wielkoscChart[2][3]=0;
    wielkoscChart[3][0]=0;  wielkoscChart[3][1]=0;  wielkoscChart[3][2]=0;  wielkoscChart[3][3]=0;

    //zaczytwanie z katalog1.txt
    QFile chartIn(QCoreApplication::applicationDirPath()+"/katalog.txt");
        if(!chartIn.open(QFile::ReadOnly | QFile::Text)){
            qDebug()<<"Could not open chart-katalog1";
            return;}
        QTextStream in (&chartIn);
        wielkoscChart[0][0]=in.readLine().toFloat();
        wielkoscChart[0][1]=in.readLine().toFloat();
        wielkoscChart[0][2]=in.readLine().toFloat();
        wielkoscChart[0][3]=in.readLine().toFloat();

        wielkoscChart[1][0]=in.readLine().toFloat();
        wielkoscChart[1][1]=in.readLine().toFloat();
        wielkoscChart[1][2]=in.readLine().toFloat();
        wielkoscChart[1][3]=in.readLine().toFloat();

        wielkoscChart[2][0]=in.readLine().toFloat();
        wielkoscChart[2][1]=in.readLine().toFloat();
        wielkoscChart[2][2]=in.readLine().toFloat();
        wielkoscChart[2][3]=in.readLine().toFloat();

        wielkoscChart[3][0]=in.readLine().toFloat();
        wielkoscChart[3][1]=in.readLine().toFloat();
        wielkoscChart[3][2]=in.readLine().toFloat();
        wielkoscChart[3][3]=in.readLine().toFloat();
        chartIn.close();

    //wprowadzenie danych do wykresu
    QBarSet *set0=new QBarSet(".txt");
    QBarSet *set1=new QBarSet(".jpeg");
    QBarSet *set2=new QBarSet(".png");
    QBarSet *set3=new QBarSet(".pdf");

    //txt [katalog1,katalog2,katalog3,katalog4]
    //jpeg [katalog1,katalog2,katalog3,katalog4]
    //png [katalog1,katalog2,katalog3,katalog4]
    //pdf [katalog1,katalog2,katalog3,katalog4]

    *set0<<wielkoscChart[0][0]<<wielkoscChart[1][0]<<wielkoscChart[2][0]<<wielkoscChart[3][0];
    *set1<<wielkoscChart[0][1]<<wielkoscChart[1][1]<<wielkoscChart[2][1]<<wielkoscChart[3][1];
    *set2<<wielkoscChart[0][2]<<wielkoscChart[1][2]<<wielkoscChart[2][2]<<wielkoscChart[3][2];
    *set3<<wielkoscChart[0][3]<<wielkoscChart[1][3]<<wielkoscChart[2][3]<<wielkoscChart[3][3];

    QHorizontalStackedBarSeries *series= new QHorizontalStackedBarSeries;
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    //dodanie serii danych i nazwy wykresu
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Zajetosc wedlug typow plikow");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //dodanie kategorii do pionowej osi
    QStringList categories;
    categories<<"katalog 1"<<"katalog 2"<<"katalog 3"<<"katalog 4";
    QBarCategoryAxis *axisY= new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisY);

    //dodanie kategorii do poziomej osi
    QValueAxis *axisX = new QValueAxis;
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);

    //utworzenie legendy kolorow do wykresu
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //dodanie wykresu na widok i ustawienie rodzica
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chart_display);
}

ChartDialog::~ChartDialog() {   delete ui;  }
