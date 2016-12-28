#include "square.h"

Square::Square(QPoint top, QPoint bottom)
{
    clicked = false;
    setFlag(ItemIsMovable);

    this->topLeft = top;
    this->bottomRight = bottom;
}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
//    return QRectF(0,0,30,30);
    return QRectF(topLeft, bottomRight);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);

    if (clicked)
    {
        brush.setColor(Qt::red);
    }
    else
    {
//        brush.setColor(Qt::green);
    }

    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clicked = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    clicked = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);

}

