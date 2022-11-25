#include "observer.h"

FileObserver::FileObserver() //конструктор
{
}

void FileObserver::update(bool exist, bool new_exist, int size, int new_size) //переопределяем виртуальный метод родителя
{ //входные параметры: exist - существовал ли файл до этого,
  //new_exist - существует ли файл сейчас/
  //size - размер файла который был при прошлой проверка
  //new_size - размер файла новый
}
