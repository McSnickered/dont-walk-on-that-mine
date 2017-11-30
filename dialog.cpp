#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    grid = createGrid(10);
    for (Square* s : grid)
    {
        scene->addItem(s);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

std::vector<Square*> Dialog::createGrid(int rowColNum)
{
    // Create a 10x10 grid of squares
    int sqSize = 30;
    std::vector<Square*> gridMap;
    for (int y = 0; y < rowColNum; ++y)
    {
        for (int x = 0; x < rowColNum; ++x)
        {
            QPoint top(x * sqSize, y * sqSize);
            QPoint bottom(x * sqSize + sqSize, y * sqSize + sqSize);
            Square *square = new Square(top, bottom);

            // Connect signals and slots
            this->connect(square->coms, SIGNAL(gameIsOver()), this, SLOT(endGame()));
            this->connect(square->coms, SIGNAL(flagSet()), this, SLOT(decrementCount()));

            gridMap.push_back(square);
        }
    }

    ui->lcdCount->display(Square::bombCount);

    return gridMap;
}

void Dialog::endGame()
{
    ui->lblGameOver->setText("GAME OVER!");
}

void Dialog::decrementCount()
{
    int tmpValue = ui->lcdCount->intValue();
    --tmpValue;
    ui->lcdCount->display(tmpValue);
}
