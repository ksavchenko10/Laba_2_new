#ifndef OBSERVER_H
#define OBSERVER_H

class Observer //абстрактный класс родитель наблюдателей
{
 public:
    virtual void update(bool exist, bool new_exist, int size, int new_size) = 0; //абстрактный метод
};

class FileObserver: public Observer //класс наследуемый от Observer
{
public:
        FileObserver();
        void update(bool exist, bool new_exist, int size, int new_size); //переопределяем виртуальный метод родителя
};


#endif // OBSERVER_H
