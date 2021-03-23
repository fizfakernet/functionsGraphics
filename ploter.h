#ifndef PLOTER_H
#define PLOTER_H

#include <QPainter>
#include "tablefunction.h"

class Ploter
{
public:
    Ploter();
    Ploter(QWidget *wind,TableFunction *gr);
    void set(QWidget *wind,TableFunction *gr);
    void setWindow(int x, int y, int x_, int y_);
    void setWindow(QRect rect);
    void drawScale(QPainter *p);
    qreal getMinX(){return minX;}
    qreal getMinY(){return minY;}
    qreal getMaxX(){return maxX;}
    qreal getMaxY(){return maxY;}
    void draw(QPainter *p);
private:
    qreal minX,minY,maxX,maxY;//минимамальные и максимальные значения
    qreal ax,bx,ay,by;//парамантры масжабирования
    int x1,x2,y1,y2;//координаты окна рисования
//    QPainter *painter;
    TableFunction *graphic;
    static QPointF wherePointInGraphic(QPoint p);
    void print_Strelka(QPainter *p,float x1, float y1, float x2, float y2);
};

#endif // PLOTER_H
