#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include "graphictable.h"
#include "tablefunction.h"
#include "ploter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_breakButton_clicked();
    void on_startButton_clicked();
    void on_pauseButton_clicked();

public slots:
    void progress(int procent);
    void finish();
    void save(QString path);
    void load(QString path);

private:
    Ui::MainWindow *ui;
    QDoubleValidator m_doubleValidator;
    GraphicTable gt;
    TableFunction tableFunction;
    Ploter ploter;

    void setStatusWait(bool isWait);
};
#endif // MAINWINDOW_H
