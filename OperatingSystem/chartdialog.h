#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QDialog>

//biblioteki ogolne wykresow
#include <QtCharts>
#include <QChartView>

//biblioteki do wykresu typu bar
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class ChartDialog;
}

class ChartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChartDialog(QWidget *parent = nullptr);
    ~ChartDialog();

private:
    Ui::ChartDialog *ui;
};

#endif // CHARTDIALOG_H
