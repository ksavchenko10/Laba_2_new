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

    FSubject(QString path); //конструктор, входной параметр путь к файлу
    void attach(Observer *obs); //метод для добавления наблюдателя в вектор
    void detach(Observer *obs); //метод удаления наблюдателя из вектора
    void startNotify(); //метод с бесконечным циклов, запускающий метод notify
    bool fileExist(); //метод возвращающий значение существует файл или нет
    int getSize(); //метод возвращающий значение размера файла в байтах
    void notify(); //метод который вызывает метод update у всех добаdленных в вектор list наблюдателей
};

#endif // OBSERVER_H
