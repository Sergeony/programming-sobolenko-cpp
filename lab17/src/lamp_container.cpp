/**
 * @file lamp_container.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією контейнера
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <lamp_container.h>


/* CONSTRUCTOR & DESTRUCTOR */

LampContainer::LampContainer(): size(DEFAULT_ARRAY_SIZE)
{
    this->lamps = new Lamp[DEFAULT_ARRAY_SIZE];
}

LampContainer::LampContainer(int size)
{
    this->lamps = new Lamp[(unsigned)size];
    this->size = size;
}

LampContainer::LampContainer(const LampContainer& copy): lamps(copy.lamps),
                                                         size(copy.size) {}

LampContainer::~LampContainer()
{ 
    delete [] this->lamps;
}


/* GETTERS & SETTERS */

Lamp& LampContainer::getLamps() {
    return *this->lamps;
}

int LampContainer::getSize() const
{
    return this->size;
}


/* OTHER METHODS */

void LampContainer::append(Lamp& newLamp)
{
    Lamp *newLamps = new Lamp[(unsigned)this->size + 1];

    for (int i = 0; i < this->size; i++) {
        newLamps[i] = this->lamps[i];
    }
    newLamps[this->size] = newLamp;

    delete [] this->lamps;
    this->lamps = newLamps;
    this->size++;
}

void LampContainer::delItem(int pos)
{
     Lamp *newLamps = new Lamp[(unsigned)this->size -1];

     for (int i = 0; i < pos; i++) {        
         newLamps[i] = this->lamps[i];
     }
     for (int i = pos + 1; i < this->size; i++) {
         newLamps[i - 1] = this->lamps[i];
     }

     delete [] this->lamps;
     this->lamps = newLamps;
     this->size--;
}

Lamp& LampContainer::getItem(int pos) const
{
    return this->lamps[pos];
}

void LampContainer::print() const
{
    for (int i = 0; i < this->size; i++) {
        this->lamps[i].print();
    }
}

void LampContainer::sortByField()
{
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size - i - 1; j++) {

            int curr_el = this->lamps[j].getLeftStarts();
            int next_el = this->lamps[j + 1].getLeftStarts();

            if (curr_el > next_el) {
                Lamp temp = this->lamps[j];

                this->lamps[j] = this->lamps[j + 1];
                this->lamps[j + 1] = temp;
            }
        }
    }
}
