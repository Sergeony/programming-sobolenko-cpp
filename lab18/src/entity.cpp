/**
 * @file entity.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією лампочки
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <entity.h>

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

Lamp::Lamp(const Lamp& copy){
    this->isTurnedOn = copy.isTurnedOn;
    this->isBroken = copy.isBroken;
    this->manufacturer = copy.manufacturer;
    this->leftStarts = copy.leftStarts;
    this->wattPerHour = copy.wattPerHour;
    this->shape = copy.shape;
    this->plinthType = copy.plinthType;
}

Lamp::~Lamp() {}


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

std::string Lamp::print() const
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

    const std::string output = outputStream.str();

    return output;
}
