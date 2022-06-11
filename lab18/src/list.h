#ifndef __LIST_H__
#define __LIST_H__

/**
 * @file list.h
 * @author Sobolenko S.
 * @brief Модуль з об'явленням контейнеру
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <entity.h>

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
        explicit LampContainer(std::string input);
        LampContainer(const LampContainer& copy);

        ~LampContainer();

        int getSize() const;

        void append(Lamp& newLamp);

        void delItem(int pos);

        Lamp& getItem(int pos) const;

        std::string print() const;

        void sortByField();

        void readFromFile(const std::string& filePath);

        void writeToFile(const std::string& filePath);
};


#endif
