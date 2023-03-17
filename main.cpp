#include <QCoreApplication>

#include <stdio.h>
#include <QFile>
#include <iostream>

#include "observer.h"
#include "observer.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileObserver obs; //создаем экземпляр наблюдателя
    FileSubject file("test.txt"); //создаем экзепляр состояния файла

    file.attach(&obs); //добавляем наблюдателя к экземпляру состояния файла

    file.startNotify(); //запускаем постоянную проверку состояния файла

    return a.exec();
}
