#include <QFile>

#include "observer.h"

FileObserver::FileObserver() //конструктор
{
}

void FileObserver::update(bool exist, bool new_exist, int size, int new_size) //переопределяем виртуальный метод родителя
{ //входные параметры: exist - существовал ли файл до этого,
  //new_exist - существует ли файл сейчас/
  //size - размер файла который был при прошлой проверка
  //new_size - размер файла новый

    if (new_exist != exist) //если существование файла изменилось
    {
        if (new_exist) //если сущетсвует сейчас
        {
            printf("The file exists, the file is not empty. Size = %d bytes\n", new_size);
        }
        else //если файл сейчас не существует
        {
            printf("File does not exist\n");
        }
    }
    else //если состояние файла не изменилось
    {
        if (new_exist && new_size != size) //проверяем не изменился ли размер
        {
            printf("The file exists, the file has been modified. New size = %d bytes\n", new_size);
        }
    }
}


FSubject::FSubject(QString path) //контруктор, входной параметр путь к файлу
{
    this->file_path = path; //присваиваем полю file_path переданное значение
}

bool FSubject::fileExist() //метод возвращающий значение bool - существует ли файл или нет
{
     if (QFile(this->file_path).exists()) //файл существует? используется стандартный метод библиотки QFile
     {
         return true;
     }

    return false;
}

int FSubject::getSize() //метод возвращающий размер файла, равное количеству байт
{
    int size = 0;
    size = QFile(this->file_path).size(); //определяем размер файла в байтах

    return size; //возвращаем значение размера
}

void FSubject::attach(Observer *obs) //метод для добавления наблюдателя в вектор наблюдателей
{
    list.push_back(obs); //используем стандартный метод push_back для добавления значения в вектор list
}

void FSubject::detach(Observer *obs) //метод удаления наблюдателя из вектора
{
    list.erase(std::find(list.begin(), list.end(), obs));
    //находим позицию наблюдателя obs в векторе list с помощью метода find
    //затем используем метод erase и передаем туда позицию, для удаления этого наблюдателя
}
