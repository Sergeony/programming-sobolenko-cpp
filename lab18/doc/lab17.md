# Лабораторна робота No18. ООП. Потоки

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 11-jul-2021.

### 1.3 Індивідуальне завдання

- Поширити попередню лабораторну роботу таким чином:
    - використання функцій printf/scanf замінити на використання cin/cout;
    - усі конкатенації рядків замінити на використання stringstream;
    - замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію про об’єкт, який далі можна виводити на екран;
    - замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацією про об’єкт, обробляє його та створює об’єкт на базі цієї інформації.
- Поширити клас-список, шляхом реалізації методів роботи з файлами за допомогою файлових потоків (fstream)

## 2 Опис програми

### 2.1 Функціональне призначення

Переробити минулу роботу за допомогою використання потоків вводу виводу. Додати можливість зчитування та запису до файлу масиву елементів. Переробити логіку конструктора так, щоб він приймав строку параметрів.

### 2.2 Важливі фрагменти програми

#### Конструктор зі строкою параметрів

```c++
        LampContainer::LampContainer(std::string input)
        {
            std::stringstream inputStream(input);
            
            inputStream >> this->size;
            this->lamps = new Lamp[(unsigned)size];
        }
```

### Метод конвертації об'єкту до строки

```c++
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
```

### Метод считування з файлу

```c++
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
```

### Метод запису до файлу

```c++
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
```
### Функція видалення елементу за індексом

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
        0 0 noname 3 7 3 4 2
        1 0 Meizu 1000 10 1500 3 1
```

**Варіант використання 2**: запустити тести у консолі:

71% поркиття є задовільною кількістю для даної роботи. Але взагалі, краще коли б були покриті усі функції.

```
        Running suite(s): Programming
        100%: Checks: 1, Failures: 0, Errors: 0
        test/test.cpp:39:P:Lab17:check_manufacturer_test:0: Passed
        llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
        llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
        Filename                      Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        entity.cpp                         47                15    68.09%          15                11    26.67%          99                47    52.53%
        list.cpp                           40                10    75.00%          11                 4    63.64%         110                33    70.00%
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        TOTAL                              87                25    71.26%          26                15    42.31%         209                80    61.72%
```

**Витоків пам'яті немає**
```
        ==195432== HEAP SUMMARY:
        ==195432==     in use at exit: 0 bytes in 0 blocks
        ==195432==   total heap usage: 29 allocs, 29 frees, 94,528 bytes allocated
        ==195432== 
        ==195432== All heap blocks were freed -- no leaks are possible
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з потоками вводу/виводу та файловими потоками.