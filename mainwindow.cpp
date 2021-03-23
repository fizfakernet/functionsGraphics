
#include <QObject>
#include <QMouseEvent>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define INDENT 10

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_doubleValidator(-1000.00, 1000.00, 5, this)
    , gt(this)
{
    ui->setupUi(this);
    m_doubleValidator.setNotation( QDoubleValidator::StandardNotation );

    ui->inputA->setValidator( &m_doubleValidator );
    ui->inputB->setValidator( &m_doubleValidator );
    ui->inputC->setValidator( &m_doubleValidator );
    ui->inputFrom->setValidator( &m_doubleValidator );
    ui->inputStep->setValidator( &m_doubleValidator );
    ui->inputTo->setValidator( &m_doubleValidator );

    ploter.set(ui->ploterSpace,&tableFunction);
    setStatusWait(true);

    QObject::connect(&tableFunction,SIGNAL( theEnd()),this,SLOT(finish()));
    QObject::connect(&tableFunction,SIGNAL( updateInfo(int) ),this,SLOT( progress(int ) ));
    QObject::connect(&gt,SIGNAL( saveInFile(QString) ),this,SLOT( save(QString ) ));
    QObject::connect(&gt,SIGNAL( loadFromFile(QString ) ),this,SLOT( load(QString ) ));
}


void MainWindow::progress(int procent)
{
    if(tableFunction.isRunning())
    {
        ui->startButton->setText(
                    "progress ("
                    + QString::number( procent )
                    + "%)"
                    );

        setStatusWait(false);
        repaint();
    }
}

void MainWindow::finish()
{
    setStatusWait(true);
    repaint();
}

void MainWindow::save(QString path)
{
    tableFunction.save(path);
}

void MainWindow::load(QString path)
{
   tableFunction.load(path);
   gt.setTable( tableFunction.getPoints() );

   AllParams params = tableFunction.getParams();
   bool isEnd;

   ui->selectFunction->setCurrentIndex(params.num);
   ui->inputA->setText(QString::number(params.a));
   ui->inputB->setText(QString::number(params.b));
   ui->inputC->setText(QString::number(params.c));
   ui->inputFrom->setText(QString::number(params.nowFrom));
   ui->inputTo->setText(QString::number(params.nowTo));
   ui->inputStep->setText(QString::number(params.nowStep));

   isEnd = ( params.nowX >= params.nowTo );
   if( isEnd )
   {
       ui->startButton->setText( "New" );
       ui->pauseButton->setText( "Pause" );
   }
   else
   {
       ui->startButton->setText( "Progress" );
       ui->pauseButton->setText( "Continue" );
   }
   ui->startButton->setEnabled( isEnd );
   ui->pauseButton->setEnabled( !isEnd );
   ui->breakButton->setEnabled( !isEnd );

   repaint();
}

void MainWindow::setStatusWait(bool isWait)
{
    ui->selectFunction->setEnabled(isWait);
    ui->inputA->setEnabled(isWait);
    ui->inputB->setEnabled(isWait);
    ui->inputC->setEnabled(isWait);
    ui->inputFrom->setEnabled(isWait);
    ui->inputTo->setEnabled(isWait);
    ui->inputStep->setEnabled(isWait);
    if(isWait) ui->startButton->setText( "Start" );
    ui->startButton->setEnabled(isWait);
    ui->pauseButton->setEnabled( !isWait );
    ui->breakButton->setEnabled( !isWait );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    int x1,x2,y1,y2,x,y;
    x1 = ui->ploterSpace->x();
    x2 = ui->ploterSpace->x() + ui->ploterSpace->width();
    y1 = ui->ploterSpace->y();
    y2 = ui->ploterSpace->y() + ui->ploterSpace->height();
    x = event->x();
    y = event->y();
    if( (x1 < x) && (x < x2) && (y1 < y) && (y < y2) && ( !tableFunction.isRunning() ) )
    {
        gt.setTable(tableFunction.getPoints());
        gt.show();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    bool running = tableFunction.isRunning();
    tableFunction.stop();
    while (tableFunction.isRunning());

    ui->ploterSpace->resize(this->width() - ui->ploterSpace->x() - INDENT*2, this->height() - ui->ploterSpace->y() - INDENT*2);

    QPainter graphPainter(this);
    ploter.setWindow(ui->ploterSpace->x(),ui->ploterSpace->y(),ui->ploterSpace->x()+ui->ploterSpace->width(),ui->ploterSpace->y()+ui->ploterSpace->height());

    graphPainter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    ploter.drawScale(&graphPainter);
    graphPainter.setPen(Qt::red);
    ploter.draw(&graphPainter);

    if(running)
        tableFunction.calculate();
}

void MainWindow::on_startButton_clicked()
{
    tableFunction.calculate(
                ui->selectFunction->currentIndex(),
                ui->inputA->text().replace(",", ".").toDouble(),
                ui->inputB->text().replace(",", ".").toDouble(),
                ui->inputC->text().replace(",", ".").toDouble(),
                ui->inputFrom->text().replace(",", ".").toDouble(),
                ui->inputTo->text().replace(",", ".").toDouble(),
                ui->inputStep->text().replace(",", ".").toDouble()
                );
}

void MainWindow::on_pauseButton_clicked()
{
    if(tableFunction.isRunning())
    {
        tableFunction.stop();
        ui->pauseButton->setText("Continue");
    }
    else
    {
        tableFunction.calculate();
        ui->pauseButton->setText("Pause");
    }
}

void MainWindow::on_breakButton_clicked()
{
    tableFunction.stop();
    while(tableFunction.isRunning());
    setStatusWait(true);
    ui->startButton->setText("New");
}
