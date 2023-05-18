#include <QCoreApplication>

#include "FileObserver.h"
#include "FileSubject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileObserver obs; //создаем экземпляр наблюдателя
    FileSubject file("test.txt"); //создаем экземпляр состояния файла

    file.attach(&obs); //добавляем наблюдателя к экземпляру состояния файла
    file.notify(); //запускаем постоянную проверку состояния файла

    return a.exec();
}
