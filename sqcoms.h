#ifndef SQCOMS_H
#define SQCOMS_H

#include <QObject>

class SqComms : public QObject
{
    Q_OBJECT

public:
    SqComms() { }
    ~SqComms() { }

public slots:

signals:
    void gameIsOver();
    void flagSet();

};


#endif // SQCOMS_H
