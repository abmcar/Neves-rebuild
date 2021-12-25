#include"windowpaint.h"

void NevesPaint::getPainter(QPainter *temppainter)
{
    painter = temppainter;
}

NevesPaintRectangle::NevesPaintRectangle(QPainter *painter,int tempX,int tempY)
{
    getPainter(painter);
    getObject(tempX,tempY);
}

void NevesPaint::getObject(int tempX, int tempY)
{
    objectX = tempX;
    objectY = tempY;
}

void NevesPaintRectangle::startPaint()
{
    painter->drawRect(objectX,objectY,141,141);
}

NevesPaintTriangle::NevesPaintTriangle(QPainter *painter,int tempX,int tempY,int temphigh,int tempwidth)
{
    getPainter(painter);
    getObject(tempX,tempY);
    high = temphigh;
    width = tempwidth;
}

void NevesPaintTriangle::startPaint()
{
    QPainterPath triangle;
    triangle.moveTo(objectX,objectY);
    triangle.lineTo(objectX+high/2,objectY-width);
    triangle.lineTo(objectX+high,objectY);
    triangle.lineTo(objectX,objectY);
    painter->drawPath(triangle);
}

NevesPaintParallelogram::NevesPaintParallelogram(QPainter *painter,int tempX,int tempY)
{
    getPainter(painter);
    getObject(tempX,tempY);
}

void NevesPaintParallelogram::startPaint()
{
    QPainterPath parallelogram;
    parallelogram.moveTo(objectX,objectY);
    parallelogram.lineTo(objectX+100,objectY-100);
    parallelogram.lineTo(objectX+300,objectY-100);
    parallelogram.lineTo(objectX+200,objectY);
    parallelogram.lineTo(objectX,objectY);
    painter->drawPath(parallelogram);
}
