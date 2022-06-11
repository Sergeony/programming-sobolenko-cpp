#ifndef __LAMP_CONTAINER_H__
#define __LAMP_CONTAINER_H__

/**
 * @file lamp_container.h
 * @author Sobolenko S.
 * @brief Модуль з об'явленням контейнеру
 * @version 0.1
 * @date 2022-06-11
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
         * @brief Constructor by default
         * 
         */
        LampContainer();

        /**
         * @brief Constructor with params
         * 
         * @param input 
         */
        explicit LampContainer(std::string input);
        
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
         * @brief Convert an object to the string representation
         * 
         * @return std::string 
         */
        std::string toString() const;

        /**
         * @brief Sort list on leftStarts by ascending
         * 
         */
        void sortByField();

        /**
         * @brief Add some elements to the end of list from the given file
         * 
         * @param filePath 
         */
        void readFromFile(const std::string& filePath);

        /**
         * @brief Write the list to the given file
         * 
         * @param filePath 
         */
        void writeToFile(const std::string& filePath);
};


#endif
