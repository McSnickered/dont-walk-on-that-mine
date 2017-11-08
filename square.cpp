#include "square.h"
#include <QGraphicsSceneMouseEvent>

int Square::bombCount = 0;

Square::Square(QPoint top, QPoint bottom)
{
    leftClicked = false;
    rightClicked = false;
    markedBomb = false;
    hasBomb = determineBomb(1, 10);

    //    setFlag(ItemIsMovable);

    this->topLeft = top;
    this->bottomRight = bottom;
}

Square::~Square()
{
}

QRectF Square::boundingRect() const
{
    return QRectF(topLeft, bottomRight);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);

    if (leftClicked && hasBomb)
    {
        brush.setColor(Qt::red);

        // Signal to the UI that the game is over

    }
    else if (leftClicked)
    {
        brush.setColor(Qt::lightGray);
    }
    else if (rightClicked)
    {
        brush.setColor(Qt::yellow);
    }

    painter->fillRect(rect, brush);
    painter->drawRect(rect);
    update();
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        leftClicked = true;
    }
    else if (event->button() == Qt::RightButton)
    {
        // This square has already been right-clicked, so undo the right-click stuff.
        if (rightClicked)
        {
            rightClicked = false;
            markedBomb = false;
            ++bombCount;
            this->setToolTip("");
        }
        else
        {
            rightClicked = true;
            markedBomb = true;
            --bombCount;

            this->setToolTip("You think this is a bomb :-)");
        }
    }
    update();
    QGraphicsItem::mousePressEvent(event);
}

bool Square::determineBomb(int low, int high)
{
    bool bombExists = false;

    // Limit the number of bombs to 10
    if (bombCount < 10)
    {
        bombExists = (qrand() % ((high + 1) - low) + low) == 5;

        if (bombExists)
            ++bombCount;
    }
    return bombExists;
}

