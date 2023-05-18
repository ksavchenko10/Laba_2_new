#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>

#include "Observer.h"

class Subject: public QObject  //абстрактный класс
{
    Q_OBJECT

signals: //cигналы для передачи
    void updateSignal(bool new_exist, int new_size);

 public:
    virtual void attach(Observer *obs) = 0; //метод для добавления наблюдателя
    virtual void detach(Observer *obs) = 0; //метод удаления наблюдателя
    virtual void notify() = 0; //метод, следящий за состоянием и размером файла
};



#endif // SUBJECT_H
