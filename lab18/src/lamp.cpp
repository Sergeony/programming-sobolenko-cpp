/**
 * @file lamp.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією лампочки
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <lamp.h>


/* CONSTRUCTORS & DESTRUCTOR */

Lamp::Lamp(): isTurnedOn(true),
              isBroken(false),
              manufacturer("popular_firm"),
              leftStarts(1000),
              wattPerHour(10),
              colourTemperature(1500),
              shape(Tubular),
              plinthType(E40) {}

Lamp::Lamp(std::string input)
{
    std::stringstream inputStream(input);

    inputStream >> this->isTurnedOn;
    inputStream >> this->isBroken;
    inputStream >> this->manufacturer;
    inputStream >> this->leftStarts;
    inputStream >> this->wattPerHour;
    inputStream >> this->colourTemperature;

    std::string tempShape, tempPlinthType;
    inputStream >> tempShape;
    inputStream >> tempPlinthType;

    if (tempShape == "Candle" || tempShape == "0") {
        this->shape = Candle;
    }
    if (tempShape == "Tubular" || tempShape == "1") {
        this->shape = Tubular;
    }
    if (tempShape == "Globe" || tempShape == "2") {
        this->shape = Globe;
    }
    if (tempShape == "Pear" || tempShape == "3") {
        this->shape = Pear;
    }
    if (tempShape == "Ogive" || tempShape == "4") {
        this->shape = Ogive;
    }

    if (tempPlinthType == "E40" || tempPlinthType == "0") {
        this->plinthType = E40;
    }
    if (tempPlinthType == "E27" || tempPlinthType == "1") {
        this->plinthType = E27;
    }
    if (tempPlinthType == "E14" || tempPlinthType == "2") {
        this->plinthType = E14;
    }
}

Lamp::Lamp(const Lamp& copy): isTurnedOn(copy.isTurnedOn),
                              isBroken(copy.isBroken),
                              manufacturer(copy.manufacturer),
                              leftStarts(copy.leftStarts),
                              wattPerHour(copy.wattPerHour),
                              shape(copy.shape),
                              plinthType(copy.plinthType) {}

Lamp::~Lamp() {}


/* GETTERS & SETTERS */

bool Lamp::getIsTurnedOn() const {
    return this->isTurnedOn;
}

void Lamp::setIsTurnedOn(bool newIsTurnedOn) {
    this->isTurnedOn = newIsTurnedOn;
}

bool Lamp::getIsBroken() const {
    return this->isBroken;
}

void Lamp::setIsBroken(bool newIsBroken) {
    this->isBroken = newIsBroken;
}

std::string Lamp::getManufacturer() const {
    return this->manufacturer;
}

int Lamp::getLeftStarts() const {
    return this->leftStarts;
}

void Lamp::setLeftStarts(int newLeftStarts) {
    this->leftStarts = newLeftStarts;
}

int Lamp::getWattPerHour() const {
    return this->wattPerHour;
}

int Lamp::getColourTemperature() const {
    return this->colourTemperature; 
}

enum Shape Lamp::getShape() const {
    return this->shape;
}

enum PlinthType Lamp::getPlinthType() const {
    return this->plinthType;
}


/* OTHER METHODS */

std::string Lamp::toString() const
{
    std::stringstream outputStream;

    outputStream << this->isTurnedOn << " " 
                 << this->isBroken << " " 
                 << this->manufacturer << " "
                 << this->leftStarts << " "
                 << this->wattPerHour << " "
                 << this->colourTemperature << " "
                 << this->shape << " "
                 << this->plinthType;

    std::string output = outputStream.str();

    return output;
}
