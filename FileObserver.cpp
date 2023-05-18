#include <iostream>

#include "Observer.h"
#include "FileObserver.h"

FileObserver::FileObserver() //конструктор
{
    exist = false;
}

void FileObserver::updateSlot(bool new_exist, int new_size){ //cлот для вывода сообщений
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
