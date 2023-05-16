#ifndef OBSERVER_H
#define OBSERVER_H

#include <Qstring>
#include <QObject>
#include <vector>

/*class Observer //абстрактный класс родитель наблюдателей
{
 public:
    virtual void update(bool new_exist, int new_size) = 0; //абстрактный метод
};
*/

class FileObserver: public QObject //класс наследуемый от Observer
{
    Q_OBJECT
//private:
//    bool exist; //существование файла

public slots:
    void createSlot(int size);
    void updateSlot(int size);
    void deleteSlot();

public:
    //FileObserver();
    //void update(bool new_exist, int new_size);
};
/*
class Subject //абстрактный класс
{
 public:
    virtual void attach(Observer *obs) = 0; //метод для добавления наблюдателя в вектор
    virtual void detach(Observer *obs) = 0; //метод удаления наблюдателя из вектора
    virtual void notify() = 0; //метод который вызывает метод update у всех добаdленных в вектор list наблюдателей
};
*/

class FileSubject: public QObject //класс для работы с файлом
{
    Q_OBJECT
private:
    //std::vector<Observer*> list; //вектор содержащий наблюдателей

    QString file_path; //путь к файлу
    bool file_exist; //существование файла
    int file_size; //размер файла

signals:
    void createSignal(int size);
    void updateSignal(int size);
    void deleteSignal();

public:
    FileSubject(QString path); //конструктор, входной параметр путь к файлу

    //void attach(Observer *obs); //метод для добавления наблюдателя в вектор
    //void detach(Observer *obs); //метод удаления наблюдателя из вектора
    void notify();

    bool fileExist(); //метод возвращающий значение существует файл или нет
    int getSize(); //метод возвращающий значение размера файла в байтах

    void startNotify(); //метод с бесконечным циклов, запускающий метод notify
};

#endif // OBSERVER_H
