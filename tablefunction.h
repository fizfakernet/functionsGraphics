#ifndef TABLEFUNCTION_H
#define TABLEFUNCTION_H

#include <QThread>
#include <QPolygonF>

struct FunctWithParams
{
    int num;
    double a,b,c;
    double f(double x,bool &corret);
};

struct AllParams : FunctWithParams
{
    double nowFrom,nowX,nowStep,nowTo;
    double minX,minY,maxX,maxY;
};

class TableFunction : public QThread
{
    Q_OBJECT
public:
    TableFunction();
    void run();
    void calculate(int functNum,double _a,double _b,double _c,double _from,double _to,double _step);
    void stop();
    void calculate();
    QPolygonF *getPoints(){return &points;}
    double getMinY(){return minY;}
    double getMaxY(){return maxY;}
    double getMinX(){return minX;}
    double getMaxX(){return maxX;}
    int numElems(){return points.size();}

    AllParams getParams();
    int save(QString path);
    int load(QString path);
signals:
    void updateInfo(int procent);
    void theEnd();

private:
    FunctWithParams fabc;
    double nowFrom,nowX,nowStep,nowTo;//параметры текущего вычисления
    bool loading,calculating;//флаги исполняемых действий
    double minX,minY,maxX,maxY;
    QPolygonF points;
    bool first;// флаг начала вычислений
};

#endif // TABLEFUNCTION_H
