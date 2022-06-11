#ifndef __LAMPS_H__
#define __LAMPS_H__

/**
 * @file lamps.h
 * @author Sobolenko S.
 * @brief Модуль з об'явленням контейнеру
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <lamp.h>

const int DEFAULT_ARRAY_SIZE = 0;

/**
 * @brief Клас-контейнер для класу Lamp
 */
class LampContainer {
    private:
        Lamp *lamps;
        int size;
    
    public:
        LampContainer(): size(DEFAULT_ARRAY_SIZE)
        {
            this->lamps = new Lamp[DEFAULT_ARRAY_SIZE];
        }
        explicit LampContainer(int size);
        LampContainer(const LampContainer& copy);

        ~LampContainer();

        int getSize() const;

        void append(Lamp& newLamp);

        void delItem(int pos);

        Lamp& getItem(int pos);

        void print();

        void sortByField();
};


#endif
