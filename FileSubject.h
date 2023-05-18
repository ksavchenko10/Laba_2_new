#ifndef FILESUBJECT_H
#define FILESUBJECT_H

//#include "Observer.h"
#include "Subject.h"

class FileSubject: public Subject //класс для работы с файлом
{
private:
    QString file_path; //путь к файлу
    bool file_exist; //существование файла
    int file_size; //размер файла

public:
    void attach(Observer *obs); //метод для добавления наблюдателя в вектор
    void detach(Observer *obs); //метод удаления наблюдателя из вектора
    void notify(); //метод с бесконечным циклом, следящий за файлом

    FileSubject(QString path); //конструктор, входной параметр путь к файлу
};



#endif // FILESUBJECT_H
