#ifndef SQUARE_H
#define SQUARE_H

#include <QPainter>
#include <QGraphicsItem>

class Square : public QGraphicsItem
{
public:
    Square();
    ~Square();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool clicked;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SQUARE_H