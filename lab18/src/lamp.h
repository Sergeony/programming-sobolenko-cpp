#ifndef __LAMP_H__
#define __LAMP_H__

/**
 * @file lamp.h
 * @author Sobolenko S.
 * @brief Модуль з об'явленням ламочки
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

enum Shape {Candle, Tubular, Globe, Pear, Ogive};
enum PlinthType {E14, E27, E40};

/**
 * @brief Базовий клас - лампочка
 */
class Lamp {
    private:
        bool isTurnedOn;
        bool isBroken;
        std::string manufacturer;
        int leftStarts;
        int wattPerHour;
        int colourTemperature;
        enum Shape shape;
        enum PlinthType plinthType;
    
    public:
        /**
         * @brief Constructor by default
         * 
         */
        Lamp();
        
        /**
         * @brief Constructor with params
         * 
         * @param input 
         */
        Lamp(std::string input);
        
        /**
         * @brief Constructor of copying
         * 
         * @param copy 
         */
        Lamp(const Lamp& copy);

        /**
         * @brief Destructor
         * 
         */
        ~Lamp();

        /**
         * @brief turnedOn getter
         * 
         * @return true 
         * @return false 
         */
        bool getIsTurnedOn() const;
        
        /**
         * @brief turnedOn setter
         * 
         * @param newIsTurnedOn 
         */
        void setIsTurnedOn(bool newIsTurnedOn);

        /**
         * @brief isBroken getter
         * 
         * @return true 
         * @return false 
         */
        bool getIsBroken() const;

        /**
         * @brief isBroken setter
         * 
         * @param newIsBroken 
         */
        void setIsBroken(bool newIsBroken);

        /**
         * @brief manufacturer getter
         * 
         * @return std::string 
         */
        std::string getManufacturer() const;

        /**
         * @brief leftStarts getter
         * 
         * @return int 
         */
        int getLeftStarts() const;

        /**
         * @brief leftStarts setter
         * 
         * @param newLeftStarts 
         */
        void setLeftStarts(int newLeftStarts);

        /**
         * @brief wattPerHour getter
         * 
         * @return int 
         */
        int getWattPerHour() const;

        /**
         * @brief colourTemperature getter
         * 
         * @return int 
         */
        int getColourTemperature() const;

        /**
         * @brief shape getter
         * 
         * @return enum Shape 
         */
        enum Shape getShape() const;

        /**
         * @brief plinthType getter
         * 
         * @return enum PlinthType 
         */
        enum PlinthType getPlinthType() const;

        /**
         * @brief Convert to the string representation
         * 
         * @return std::string 
         */
        std::string toString() const;
};

#endif
