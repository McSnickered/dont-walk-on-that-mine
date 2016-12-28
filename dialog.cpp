#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

//    QPoint top(0,0);
//    QPoint bottom(30,30);
//    square = new Square(top, bottom);
//    scene->addItem(square);

    grid = createGrid();
    for (Square* s : grid)
    {
        scene->addItem(s);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

std::vector<Square*> Dialog::createGrid()
{
    // Create a 10x10 grid of squares
    int sqSize = 30;
    std::vector<Square*> gridMap;
    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            QPoint top(x * sqSize, y * sqSize);
            QPoint bottom(x * sqSize + sqSize, y * sqSize + sqSize);
            //QRect rectangle(top, bottom);
            Square *square = new Square(top, bottom);

            gridMap.push_back(square);
        }
    }

    return gridMap;
}
