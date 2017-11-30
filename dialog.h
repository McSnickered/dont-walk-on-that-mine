#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "square.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    std::vector<Square*> createGrid(int rowColNum);

public slots:
    void endGame();
    void decrementCount();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    Square *square;
    std::vector<Square*> grid;

};

#endif // DIALOG_H
