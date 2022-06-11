/**
 * @file lamp.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією лампочки
 * @version 0.1
 * @date 2022-06-10
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

Lamp::Lamp(bool isTurnedOn,
           bool isBroken,
           std::string manufacturer,
           int leftStarts,
           int wattPerHour,
           enum Shape shape,
           enum PlinthType plinthType)
{
    this->isTurnedOn = isTurnedOn;
    this->isBroken = isBroken;
    this->manufacturer = manufacturer;
    this->leftStarts = leftStarts;
    this->wattPerHour = wattPerHour;
    this->shape = shape;
    this->plinthType = plinthType;
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

void Lamp::print()
{
    std::cout << this->isTurnedOn << " " \
              << this->isBroken << " " \
              << this->manufacturer << " " \
              << this->leftStarts << " " \
              << this->wattPerHour << " " \
              << this->colourTemperature << " " \
              << this->shape << " " \
              << this->plinthType << std::endl;
}
