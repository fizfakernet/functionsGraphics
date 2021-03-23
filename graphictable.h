#ifndef GRAPHICTABLE_H
#define GRAPHICTABLE_H

#include <qmainwindow.h>

namespace Ui {
class GraphicTable;
}

class GraphicTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphicTable(QWidget *parent = nullptr);
    ~GraphicTable();
    void setTable(QPolygonF *points);

signals:
    void saveInFile(QString filename);
    void loadFromFile(QString filename);

private slots:
    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::GraphicTable *ui;
};

#endif // GRAPHICTABLE_H
