#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{


    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->btnNewGame->setVisible(false);
    ui->btnQuit->setVisible(false);
    ui->lblGameOver->setVisible(false);

    this->connect(this->ui->btnNewGame, SIGNAL(clicked()), this, SLOT(startNewGame()));
    this->connect(this->ui->btnQuit, SIGNAL(clicked()), this, SLOT(quitGame()));

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
            this->connect(square->coms, SIGNAL(flagSet()), this, SLOT(displayCount()));

            gridMap.push_back(square);
        }
    }

    ui->lcdCount->display(10);

    return gridMap;
}

void Dialog::endGame()
{
    // 1.) Disable the graphics view so player can't click on squares
    // 2.) Enable the New Game button
    ui->graphicsView->setEnabled(false);
    ui->lblGameOver->setVisible(true);
    ui->btnNewGame->setEnabled(true);
    ui->btnNewGame->setVisible(true);
    ui->btnQuit->setEnabled(true);
    ui->btnQuit->setVisible(true);
}

void Dialog::displayCount()
{
    ui->lcdCount->display(Square::bombCount);
}

void Dialog::startNewGame()
{
    QProcess process;
    process.startDetached("Minesweeper");

    QApplication::quit();

}

void Dialog::quitGame()
{
    QApplication::quit();
}
