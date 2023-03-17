#include <QFile>
#include <stdio.h>
#include <thread>
#include <iostream>

#include "observer.h"

FileObserver::FileObserver() //конструктор
{
    exist = false;
}

void FileObserver::update(bool new_exist, int new_size) //переопределяем виртуальный метод родителя
{
    if (new_exist != exist) //изменилось существование
    {
        exist = new_exist;
        if (new_exist) {
            std::cout << "The file exists, the file is not empty. Size = " << new_size <<  " bytes" << std::endl;
        }
        else //если файл сейчас не существует
        {
            std::cout << "File does not exist" << std::endl;
        }
    }
    else //существование не менялось
    {

        std::cout << "The file exists, the file has been modified. Size = " << new_size <<  " bytes" << std::endl;
    }
}


FileSubject::FileSubject(QString path) //контруктор, входной параметр путь к файлу
{
    file_path = path; //присваиваем полю file_path переданное значение
    file_exist = false;
    file_size = 0;
}

bool FileSubject::fileExist() //метод возвращающий значение bool - существует ли файл или нет
{
    return QFile(file_path).exists(); //файл существует? используется стандартный метод библиотки QFile
}

int FileSubject::getSize() //метод возвращающий размер файла, равное количеству байт
{
    if (!fileExist())
        return 0;
    return QFile(file_path).size(); //определяем размер файла в байтах
}

void FileSubject::attach(Observer *obs) //метод для добавления наблюдателя в вектор наблюдателей
{
    list.push_back(obs); //используем стандартный метод push_back для добавления значения в вектор list
}

void FileSubject::detach(Observer *obs) //метод удаления наблюдателя из вектора
{
    list.erase(std::find(list.begin(), list.end(), obs));
    //находим позицию наблюдателя obs в векторе list с помощью метода find
    //затем используем метод erase и передаем туда позицию, для удаления этого наблюдателя
}

void FileSubject::notify() //метод проверки состояни и вызова методов update у наблюдателей
{
    bool new_exist = this->fileExist(); //новое значение
    int new_size = this->getSize(); //новый размер
    if  (new_exist != file_exist || new_size != file_size) {
        file_exist = new_exist;
        file_size = new_size;
        for (std::vector<Observer*>::const_iterator iter = list.begin(); iter != list.end(); iter++) //проходим по всем наблюдателям из вектора list
        {
            (*iter)->update(file_exist, file_size);
            //вызываем метод update у каждого наблюдателя и передаем туда параметры
        }
    }

}

void FileSubject::startNotify() //метод для постоянного наблюдения
{
  while(true) //бесконечный цикл
  {
     this->notify(); //запускаем метод notify, для проверки состояния
     std::this_thread::sleep_for(std::chrono::milliseconds(100)); //пауза 100 миллисекуд
  }
}
