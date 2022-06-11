
#ifndef __ENTITY_H__
#define __ENTITY_H__

/**
 * @file entity.h
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
        Lamp() : isTurnedOn(true),
                 isBroken(false),
                 manufacturer("popular_firm"),
                 leftStarts(1000),
                 wattPerHour(10),
                 colourTemperature(1500),
                 shape(Tubular),
                 plinthType(E40) {}
        
        Lamp(std::string input);
        
        Lamp(const Lamp& copy);

        ~Lamp();

        bool getIsTurnedOn() const;
        void setIsTurnedOn(bool newIsTurnedOn);

        bool getIsBroken() const;
        void setIsBroken(bool newIsBroken);

        std::string getManufacturer() const;

        int getLeftStarts() const;
        void setLeftStarts(int newLeftStarts);

        int getWattPerHour() const;

        int getColourTemperature() const;

        enum Shape getShape() const;

        enum PlinthType getPlinthType() const;

        std::string print() const;
};

#endif
