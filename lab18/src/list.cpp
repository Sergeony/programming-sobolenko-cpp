/**
 * @file list.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією контейнера
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list.h>

LampContainer::LampContainer(std::string input)
{
    std::stringstream inputStream(input);
    
    inputStream >> this->size;
    this->lamps = new Lamp[(unsigned)size];
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

Lamp& LampContainer::getItem(int pos) const
{
    return this->lamps[pos];
}

std::string LampContainer::print() const
{
    std::stringstream outputStream;

    for (int i = 0; i < this->size; i++) {
        outputStream << this->lamps[i].print();

         if (i != this->size - 1) {
            outputStream << std::endl;
        }
    }

    const std::string output = outputStream.str();

    return output;
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

void LampContainer::readFromFile(const std::string& filePath)
{
    std::ifstream inputFile;
    std::string lampString;

    inputFile.open(filePath);
    
    while (!inputFile.eof())
    {    
        getline(inputFile, lampString);

        Lamp lamp(lampString);

        this->append(lamp);
    }

    inputFile.close();
}

void LampContainer::writeToFile(const std::string& filePath)
{
    std::ofstream outputFile;

    outputFile.open(filePath);

    for (int i = 0; i < this->size; i++) {
        outputFile << this->lamps[i].print();
        
        if (i != this->size - 1) {
            outputFile << std::endl;
        }
    }

    outputFile.close();
}
