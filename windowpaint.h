#ifndef WINDOWPAINT_H
#define WINDOWPAINT_H

#include<QPainter>
#include<QPaintDevice>
#include<QPaintDeviceWindow>
#include<QtDebug>
#include<QMouseEvent>
#include<QVector>
#include<QPainterPath>
#include<QMap>
#include<QColor>

struct paintObject
{
    int type;
    int mouseX,mouseY;
    int rota;
};

class NevesPaint
{
public:
    void virtual startPaint() = 0;
    void getObject(int tempX,int tempY);
    void getPainter(QPainter *temppainter);
//    void getVector(QVector<paintObject> *tempvector);
//    void getPos(int Pos);
//    void vectorUpdate(QVector<paintObject> &tempvector);
    QPainter *painter;
    int objectX,objectY;
//private:
//    QVector<paintObject> *nowVector;
//    paintObject nowObject;
//    int vectorPos;
};

class NevesPaintRectangle : public NevesPaint
{
public:
    NevesPaintRectangle(QPainter *painter,int tempX,int tempY);
    void startPaint();
};

class NevesPaintTriangle : public NevesPaint
{
public:
    NevesPaintTriangle(QPainter *painter,int tempX,int tempY,int temphigh,int tempwidth);
    void startPaint();
private:
    int high,width;
};

class NevesPaintParallelogram : public NevesPaint
{
public:
    NevesPaintParallelogram(QPainter *painter,int tempX,int tempY);
    void startPaint();
};

#endif // WINDOWPAINT_H
