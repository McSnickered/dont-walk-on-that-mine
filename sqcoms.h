#ifndef SQCOMS_H
#define SQCOMS_H

#include <QObject>

class SqComms : QObject
{
    Q_OBJECT

public:
    SqComms() { }
    ~SqComms() { }

public slots:

signals:
    void gameIsOver();

};


#endif // SQCOMS_H
