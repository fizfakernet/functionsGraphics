
#include <qfile.h>
#include <qtextstream.h>
#include <qobject.h>
#include <qmath.h>
#include "tablefunction.h"

#define PROCENT_DISCRET 1

TableFunction::TableFunction()
{
    loading = false; calculating = false;
    first = true;
 }

void TableFunction::run()
{
    double y;
    bool correct;
    int procent,procent_ald = 0;

    if( calculating )
    {
        for(; (nowX <= nowTo) && calculating ; nowX += nowStep )
        {
//            wait(1000);//для того, чтобы успевать нажимать "пауза"
            y = fabc.f(nowX,correct);
            if(correct)
            {
                points.push_back( QPointF(nowX,y) );
                if ( (nowTo-nowFrom)>0 )
                    procent = qRound( 100*(nowX-nowFrom)/(nowTo-nowFrom) );
                if( (procent - procent_ald) > PROCENT_DISCRET )
                {
                    procent_ald = procent;
                    emit updateInfo(procent);
                }
                if(first)
                {
                    minY = maxY = y;
                    first = false;
                }
                else
                {
                    minY = fmin(y,minY);
                    maxY = fmax(y,maxY);
                }
            }
        }
    }
    calculating = false;
    if(nowX >= nowTo) emit theEnd();
}

void TableFunction::calculate(int functNum, double _a, double _b, double _c, double _from, double _to, double _step)
{ 
    if( (_to - _from)*_step > 0 )
    {
        points.clear();
        loading = false; calculating = true;
        nowFrom = nowX = _from; nowStep = _step; nowTo = _to;
        fabc.a = _a; fabc.b = _b; fabc.c = _c; fabc.num = functNum;

        minX = _from; maxX = _to;
        first = true;
        start( QThread :: IdlePriority );
    }
}

void TableFunction::stop()
{
    calculating = false; loading = false;
}

void TableFunction::calculate()
{
    calculating = true; loading = false;
    start();
}

int TableFunction::save(QString path)
{
    if(isRunning())
        return -2;
    QFile f(path);
    if( !f.open(QIODevice::WriteOnly | QIODevice::Text) )
        return -1;
    QTextStream writeStream(&f);

    QString head =
                QString::number(nowFrom) + "\n" +
                QString::number(nowTo) + "\n" +
                QString::number(nowStep) + "\n" +
                QString::number(nowX) + "\n" +
                QString::number(minX) + "\n" +
                QString::number(maxX) + "\n" +
                QString::number(minY) + "\n" +
                QString::number(maxY) + "\n" +
                QString::number(fabc.num) + "\n" +
                QString::number(fabc.a) + "\n" +
                QString::number(fabc.b) + "\n" +
                QString::number(fabc.c) + "\n" ;

    writeStream << head << "\n";
    foreach( QPointF elem, points )
    {
        writeStream << elem.x() << " " << elem.y() << "\n";
    }
    f.close();
    return 0;
}

int TableFunction::load(QString path)
{
    double x,y;
    if(isRunning())
        return -2;
    QFile f(path);
    if( !f.open(QIODevice::ReadOnly | QIODevice::Text) )
        return -1;
    QTextStream readStream(&f);

    readStream
            >> nowFrom
            >> nowTo
            >> nowStep
            >> nowX
            >> minX
            >> maxX
            >> minY
            >> maxY
            >> fabc.num
            >> fabc.a
            >> fabc.b
            >> fabc.c;


    points.clear();
    while( !readStream.atEnd() )
    {
        readStream >> x;
        if( !readStream.atEnd() )
        {
            readStream >> y;
            points.push_back(QPointF(x,y));
        }

    }

    f.close();
    return 0;
}

AllParams TableFunction::getParams()
{
    AllParams ret;
    ret.nowFrom = nowFrom;
    ret.nowTo = nowTo;
    ret.nowStep = nowStep;
    ret.nowX = nowX;
    ret.minX = minX;
    ret.maxX = maxX;
    ret.minY = minY;
    ret.maxY = maxY;
    ret.num = fabc.num;
    ret.a = fabc.a;
    ret.b = fabc.b;
    ret.c = fabc.c;

    return ret;
}

double FunctWithParams::f(double x,bool &corret)
{
    corret = true;
    switch (num)
    {
    case 0: return a*(x*x) + b*x + c;break;
    case 1: return a * sin(x) + b * cos( c*x );break;
    case 2: if(b*x >0 ) {return a*log( b*x );} else corret = false; break;
    case 3: if(sin(x*x) * b != 0) {return a / ( sin(x*x) * b );} else corret = false; break;
    default: corret = false;
    }
    return 0;
}

