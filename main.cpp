#include <QCoreApplication>

#include <stdio.h>
#include <QFile>
#include <QObject>
#include <iostream>

#include "observer.h"
#include "observer.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileObserver obs; //создаем экземпляр наблюдателя
    FileSubject file("test.txt"); //создаем экзепляр состояния файла

    //file.attach(&obs); //добавляем наблюдателя к экземпляру состояния файла
    QObject::connect(&file, &FileSubject::createSignal, &obs, &FileObserver::createSlot);
    QObject::connect(&file, &FileSubject::updateSignal, &obs, &FileObserver::updateSlot);
    QObject::connect(&file, &FileSubject::deleteSignal, &obs, &FileObserver::deleteSlot);

    file.notify(); //запускаем постоянную проверку состояния файла

    return a.exec();
}
