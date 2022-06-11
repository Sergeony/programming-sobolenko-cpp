/**
 * @file lamps.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією контейнера
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <lamps.h>

LampContainer::LampContainer(int size)
{
    this->lamps = new Lamp[(unsigned)size];
    this->size = size;
}

LampContainer::LampContainer(const LampContainer& copy)
{
    this->lamps = copy.lamps;
    this->size = copy.size;
}

LampContainer::~LampContainer(){ delete [] this->lamps; }

int LampContainer::getSize() const
{
    return this->size;
}

void LampContainer::append(Lamp& newLamp)
{
    Lamp *newLamps = new Lamp[(unsigned)this->size + 1];

    for (int i = 0; i < this->size; i++) {
        newLamps[i] = this->lamps[i];
    }
    
    newLamps[this->size] = newLamp;
    this->size++;

    delete [] this->lamps;
    this->lamps = newLamps;
}

void LampContainer::delItem(int pos)
{
     Lamp *newLamps = new Lamp[(unsigned)this->size -1];

     for (int i = 0, j = 0; j < this->size; i++, j++) {
         if (j == pos) {
             i--;
             continue;
         }
         
         newLamps[i] = this->lamps[j];
     }

     this->size--;

     delete [] this->lamps;
     this->lamps = newLamps;
}

Lamp& LampContainer::getItem(int pos)
{
    return this->lamps[pos];
}

void LampContainer::print()
{
    for (int i = 0; i < this->size; i++) {
        this->lamps[i].print();
    }
}

void LampContainer::sortByField()
{
    for (int i = 0; i < this->size; i++) {
        for (int j = 1; j < this->size; j++) {

            int curr_el = this->lamps[j].getLeftStarts();
            int prew_el = this->lamps[j - 1].getLeftStarts();

            if (curr_el < prew_el) {
                Lamp temp = this->lamps[j];

                this->lamps[j] = this->lamps[j - 1];
                this->lamps[j - 1] = temp;
            }
        }
    }
}
