#ifndef SQUARE_H
#define SQUARE_H

#include <QPainter>
#include <QGraphicsItem>
#include "sqcoms.h"

class Square : public QGraphicsItem
{

public:
    Square(QPoint top, QPoint bottom);
    ~Square();

    QPoint topLeft, bottomRight;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool leftClicked;
    bool rightClicked;
    bool hasBomb;
    bool markedBomb;
    static int bombCount;
    static bool gameOver;

    SqComms* coms;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool determineBomb(int low, int high);
    int updateBombCount();
};

#endif // SQUARE_H
