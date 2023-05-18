#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>

class Observer:  public QObject //абстрактный класс родитель наблюдателей
{
    Q_OBJECT
public slots: //слот-обработчик
    virtual void updateSlot(bool new_exist, int new_size) = 0;
};


#endif // OBSERVER_H
