#include <QFile>
#include <stdio.h>
#include <thread>
#include <iostream>

#include "observer.h"

/*FileObserver::FileObserver() //конструктор
{
    exist = false;
}*/

// cлоты вывода сообщения
void FileObserver::createSlot(int size){
    std::cout << "The file exists, the file is not empty. Size = " << size <<  " bytes" << std::endl;
}

void FileObserver::updateSlot(int size){
     std::cout << "The file exists, the file has been modified. Size = " << size <<  " bytes" << std::endl;
}

void FileObserver::deleteSlot(){
    std::cout << "File does not exist" << std::endl;
}

/*void FileObserver::update(bool new_exist, int new_size) //переопределяем виртуальный метод родителя
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
}*/


FileSubject::FileSubject(QString path) //контруктор, входной параметр путь к файлу
{
    file_path = path; //присваиваем полю file_path переданное значение
    file_exist = false;
    file_size = 0;
}

/*
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
*/

void FileSubject::notify() //метод для постоянного наблюдения
{
  while(true) //бесконечный цикл
  {
      bool new_exist = QFile(file_path).exists(); //новое значение существование файла
      int new_size = 0; //новый размер
      if (new_exist) //на каждой итерации цикла получаем новое текущее состояние файла и записываем его в new_exist
          new_size = QFile(file_path).size();
      if (new_exist != file_exist)  { //если состояние полученное на текущей итерации не равно состояние на предыдущей итерации, то состояние файла изменилось
          if (new_exist) {// файл был создан
              emit createSignal(new_size); //испускается сигнал
          } else { // файл был удален
              emit deleteSignal();
          }
      } else if (new_size != file_size) { //файл был изменен
          emit updateSignal(new_size);
      }
      file_exist = new_exist;
      file_size = new_size;
      std::this_thread::sleep_for(std::chrono::milliseconds(100)); //пауза 100 миллисекуд
  }
}
