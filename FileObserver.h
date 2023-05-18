#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "Observer.h"

class FileObserver: public Observer //класс наследуемый от Observer
{
private:
    bool exist;
public: //слот-обработчик
    void updateSlot(bool new_exist, int new_size);

    FileObserver();
};


#endif // FILEOBSERVER_H
