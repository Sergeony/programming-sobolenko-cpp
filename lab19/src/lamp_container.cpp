/**
 * @file lamp_сontainer.cpp
 * @author Sobolenko S.
 * @brief Модуль з реалізацією контейнера
 * @version 0.1
 * @date 2022-06-11
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

LampContainer::LampContainer(std::string input)
{
    std::stringstream inputStream(input);
    
    inputStream >> this->size;
    this->lamps = new Lamp[(unsigned)size];
}

LampContainer::LampContainer(const LampContainer& copy): lamps(copy.lamps),
                                                         size(copy.size) {}

LampContainer::~LampContainer()
{ 
    delete [] this->lamps;
}


/* GETTERS & SETTERS */

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

std::string LampContainer::toString() const
{
    std::stringstream outputStream;

    for (int i = 0; i < this->size; i++) {
        outputStream << this->lamps[i].toString();

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
        outputFile << this->lamps[i].toString();
        
        if (i != this->size - 1) {
            outputFile << std::endl;
        }
    }

    outputFile.close();
}


/* OVERLOADING METHODS */

Lamp& LampContainer::operator[](int pos) {
    return this->lamps[pos];
}

std::ostream& operator<<(std::ostream& outputStream,
                         const LampContainer& lampContainer)
{
    outputStream << lampContainer.toString();
    return outputStream;
}
        
std::istream& operator>>(std::istream& inputStream,
                         LampContainer &lampContainer)
{
    for (int i = 0; i < lampContainer.getSize(); i++) {

        inputStream >> lampContainer[i];
    }

    return inputStream;
}
