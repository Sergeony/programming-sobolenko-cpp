#ifndef __LAMP_CONTAINER_H__
#define __LAMP_CONTAINER_H__

/**
 * @file lamp_container.h
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
        /**
         * @brief Construct by default
         * 
         */
        LampContainer();

        /**
         * @brief Constructor with params
         * 
         * @param size 
         */
        explicit LampContainer(int size);
        
        /**
         * @brief Constructor of copying
         * 
         * @param copy 
         */
        LampContainer(const LampContainer& copy);

        /**
         * @brief Destructor
         * 
         */
        ~LampContainer();

        /**
         * @brief array getter
         * 
         * @return LampContainer& 
         */
        Lamp& getLamps();
        
        /**
         * @brief size getter
         * 
         * @return int 
         */
        int getSize() const;

        /**
         * @brief Add a new element to the end of list
         * 
         * @param newLamp 
         */
        void append(Lamp& newLamp);

        /**
         * @brief Delete the element on the given position
         * 
         * @param pos 
         */
        void delItem(int pos);

        /**
         * @brief Get element on the given position
         * 
         * @param pos 
         * @return Lamp& 
         */
        Lamp& getItem(int pos) const;

        /**
         * @brief Print the object, in string representation, to the console
         * 
         */
        void print() const;

        /**
         * @brief Sort list on leftStarts by ascending
         * 
         */
        void sortByField();
};


#endif
