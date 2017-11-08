#ifndef SQUARE_H
#define SQUARE_H

#include <QPainter>
#include <QGraphicsItem>

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

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool determineBomb(int low, int high);
    int updateBombCount();
};

#endif // SQUARE_H
