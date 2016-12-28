#include "square.h"

Square::Square()
{
    clicked = false;
    setFlag(ItemIsMovable);
}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
    return QRectF(0,0,30,30);
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

