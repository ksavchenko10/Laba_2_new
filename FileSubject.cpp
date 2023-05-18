#include <thread>

#include <QFile>
#include <QObject>

#include "FileSubject.h"

FileSubject::FileSubject(QString path) //контруктор, входной параметр путь к файлу
{
    file_path = path; //присваиваем полю file_path переданное значение
    file_exist = false;
    file_size = 0;
}


void FileSubject::attach(Observer *obs) //метод для добавления наблюдателя
{
    QObject::connect(this, &FileSubject::updateSignal, obs, &Observer::updateSlot); //связываем сигнал со слотом
}

void FileSubject::detach(Observer *obs) //метод удаления наблюдателя
{
    QObject::disconnect(this, &FileSubject::updateSignal, obs, &Observer::updateSlot); // разъединяем

}

void FileSubject::notify() //метод для постоянного наблюдения
{
  while(true) //бесконечный цикл
  {
      //на каждой итерации цикла получаем новое текущее состояние файла и записываем его в new_exist
      bool new_exist = QFile(file_path).exists(); //новое значение существование файла
      int new_size = 0;
      if (new_exist)
          new_size = QFile(file_path).size(); //новый размер файла
      if (file_exist != new_exist || file_size != new_size) //если изменилось состояние или размер, то имитируем сигнал
          emit updateSignal(new_exist, new_size);
      file_exist = new_exist;
      file_size = new_size;
      std::this_thread::sleep_for(std::chrono::milliseconds(100)); //пауза 100 миллисекуд
  }
}
