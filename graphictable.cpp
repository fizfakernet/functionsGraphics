#include <qfiledialog.h>
#include "graphictable.h"
#include "ui_graphictable.h"

GraphicTable::GraphicTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicTable)
{
    ui->setupUi(this);
}

GraphicTable::~GraphicTable()
{
    delete ui;
}

void GraphicTable::setTable(QPolygonF *points)
{
    if(points != NULL)
    {
        ui->tableWidget->setRowCount(points->size());
        int i=0;
        foreach(QPointF point,*points)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(point.x())));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(point.y())));
            i++;
        }
    }
}

void GraphicTable::on_saveButton_clicked()
{
    QString fn = QFileDialog::getSaveFileName();
    emit saveInFile(fn);
}

void GraphicTable::on_loadButton_clicked()
{
    QString fn = QFileDialog::getOpenFileName();
    emit loadFromFile(fn);
}
