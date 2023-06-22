#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QCategoryAxis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    QString filename = "C:/Users/oscar/Documents/GitHub/qt/budget/data/data_current.txt";
//    QFile file(filename);
//    if(!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(0, "error", file.errorString());
//    }
//    QTextStream in(&file);
//    qDebug() << "reading";
//    while(!in.atEnd()) {
//        QString line = in.readLine();
//        qDebug() << line;
//    }



//    QBarSet *set0 = new QBarSet("test");
//    *set0 << 100 << 150 << 213;

//    QBarSeries *series = new QBarSeries();
//    series->append(set0);

//    // Used to define the bar chart to display, title
//    // legend,
//    QChart *chart = new QChart();

//    // Add the chart
//    chart->addSeries(series);

//    // Used to display the chart
//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);



//    // Create the button, make "this" the parent
//    QPushButton *m_button = new QPushButton("Ouvrir formulaire");
//    // set size and location of the button
//    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

//    // Connect button signal to appropriate slot
//    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);

    ui->setupUi(this);
//    ui->verticalLayout->addWidget(m_button);
//    ui->verticalLayout->addWidget(chartView);
}

void MainWindow::handleButton() {
//    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_form_button_clicked()
{
    transaction_form.show();
}


void MainWindow::on_add_account_button_clicked()
{
    account_form.show();
}


void MainWindow::on_add_account_category_clicked()
{
    account_category_form.show();
}

