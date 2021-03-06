#include "square.h"
#include <QGraphicsSceneMouseEvent>
#include <QTime>

int Square::bombCount = 0;
bool Square::gameOver = false;


Square::Square(QPoint top, QPoint bottom)
{
    leftClicked = false;
    rightClicked = false;
    markedBomb = false;
    hasBomb = determineBomb(1, 10);

    this->topLeft = top;
    this->bottomRight = bottom;

    this->coms = new SqComms();
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
    // To get rid of not-used warnings
    option = option;
    widget = widget;
    // end

    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);

    if (leftClicked && hasBomb)
    {
        brush.setColor(Qt::red);

        // Signal to the UI that the game is over
        emit this->coms->gameIsOver();
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
        if (rightClicked)
        {
            rightClicked = false;
            markedBomb = false;
            ++bombCount;
            this->setToolTip("");
        }

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
            if (bombCount > 0)
            {
                rightClicked = true;
                markedBomb = true;
                --bombCount;
                this->setToolTip("You think this is a bomb :-)");
            }
        }
    }

    // Signal to the UI to update the LCD count display in case it changed
    emit this->coms->flagSet();

    update();
    QGraphicsItem::mousePressEvent(event);
}

bool Square::determineBomb(int low, int high)
{
    bool bombExists = false;
    int seed = QTime::currentTime().msec();

    // Limit the number of bombs to 10
    if (bombCount < 10)
    {
        bombExists = (qsrand(seed) % ((high + 1) - low) + low) == 5;

        if (bombExists)
            ++bombCount;
    }
    return bombExists;
}

