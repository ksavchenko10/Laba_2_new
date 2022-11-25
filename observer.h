#ifndef OBSERVER_H
#define OBSERVER_H

#include <Qstring>
#include <vector>

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

class FSubject //класс для работы с файлом
{
    std::vector<Observer*> list; //вектор содержащий наблюдателей

    public:
    QString file_path; //путь к файлу
    bool file_exist = false; //существование файла
    int file_size = 0; //размер файла
};

#endif // OBSERVER_H
