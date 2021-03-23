#include <qmath.h>
#include <QWidget>
#include "ploter.h"

Ploter::Ploter()
{
    x1 = x2 = y1 = y2 = 0;
}

Ploter::Ploter(QWidget *wind, TableFunction *gr)
{
    Ploter();
    set(wind, gr);
}

void Ploter::set(QWidget *wind, TableFunction *gr)
{
    graphic = gr;

    if(gr != NULL)
    {
        minX = gr->getMinX(); maxX = gr->getMaxX();
        minY = gr->getMinY(); maxY = gr->getMaxY();
    }
    else return;

    if(wind != 0)
    {
        if( (x1>=x2) || (y1>=y2) )
        {
            setWindow(
                wind->x(),
                wind->y(),
                wind->x() + wind->width(),
                wind->y() + wind->height()
                    );
        }
    }
}

void Ploter::setWindow(int x, int y, int x_, int y_)
{
    x1 = x; y1 = y; x2 = x_;y2 = y_;

    if(graphic != NULL)
    {
        minX = graphic->getMinX(); maxX = graphic->getMaxX();
        minY = graphic->getMinY(); maxY = graphic->getMaxY();
    }
    if ( (maxX - minX)*(maxY - minY) > 0 )
    {
        ax = (x2-x1) / (maxX - minX)  ;
        ay = -(y2-y1) / (maxY - minY) ;
        bx = -minX*ax+x1;
        by = -minY*ay+y2;
    }
}

void Ploter::setWindow(QRect rect)
{
    x1 = rect.x();
    y1 = rect.y();
    x2 = rect.x()+rect.width();
    y2 = rect.y()+rect.height();

    setWindow(x1,y1,x2,y2);
}

void Ploter::drawScale(QPainter *p)
{
//    p->drawRect(x1,y1,x2-x1,y2-y1);
    print_Strelka(p, (x1+x2)/2, y2, (x1+x2)/2, y1);
    print_Strelka(p, x1, (y1+y2)/2 , x2, (y1+y2)/2 );
}

void Ploter::draw(QPainter *p)
{
    QPolygonF printPoints;
        foreach( QPointF elem, *(graphic->getPoints()) )
        {
            printPoints << QPointF(elem.x()*ax+bx,elem.y()*ay+by);
        }
        p->drawPolyline(printPoints);
}

void Ploter::print_Strelka(QPainter *p,float x1, float y1, float x2, float y2)
{

    float x, y;
    float f1x2 , f1y2;
    float lons, ugol;

    const float ostr = 0.25;        // острота стрелки

    p->drawLine(x1, y1, x2, y2);

    x = x2 - x1;
    y = y2 - y1;

    lons = sqrt(x*x + y*y) / 7;     // длина лепестков % от длины стрелки
    ugol = atan2(y, x);             // угол наклона линии

    //lons = 12;

    f1x2 = x2 - lons * cos(ugol - ostr);
    f1y2 = y2 - lons * sin(ugol - ostr);

    p->drawLine(x2, y2, f1x2, f1y2);

    f1x2 = x2 - lons * cos(ugol + ostr);
    f1y2 = y2 - lons * sin(ugol + ostr);

    p->drawLine(x2, y2, f1x2, f1y2);
}
