# Лабораторна робота No19. ООП. Перевантаження операторів

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 11-jul-2021.

### 1.3 Індивідуальне завдання

Поширити попередню лабораторну роботу (потоковий i/o при роботі зі класами) такимчином:
- у базовому класі (прикладної галузі) перевантажити:
    - оператор присвоювання;
    - оператори порівняння (== , !=);
    - оператори введення / виведення;
- у класі-списку перевантажити:
    - оператор індексування ( [ ] );
    - оператори введення / виведення з акцентом роботи, у тому числі і з файлами

## 2 Опис програми

### 2.1 Функціональне призначення

Переробити минулу роботу використовуючи методи перевантаження базових операторів, задля того, щоб покращити зручність та читальність коду.

### 2.2 Важливі фрагменти програми

#### Перевантаження оператору []

```c++
        Lamp& LampContainer::operator[](int pos) {
            return this->lamps[pos];
        }
```

### Перевантаження оператору ==

```c++
        bool Lamp::operator==(const Lamp &other) const {
            return this->isTurnedOn == other.isTurnedOn &&
                this->isBroken == other.isBroken &&
                this->manufacturer == other.manufacturer &&
                this->leftStarts == other.leftStarts &&
                this->wattPerHour == other.wattPerHour &&
                this->colourTemperature == other.colourTemperature &&
                this->shape == other.shape &&
                this->plinthType  == other.plinthType;
        }
```

### Перевантаження оператору <<

```c++
        std::ostream& operator<<(std::ostream& output,
                                const Lamp& lamp)
        {
            output << lamp.toString();
            return output;             
        }
```

### Перевантаження оператору >>

```c++
        std::istream& operator>>(std::istream& inputStream,
                                Lamp& lamp)
        {
            inputStream >> lamp.isTurnedOn;
            inputStream >> lamp.isBroken;
            inputStream >> lamp.manufacturer;
            inputStream >> lamp.leftStarts;
            inputStream >> lamp.wattPerHour;
            inputStream >> lamp.colourTemperature;

            std::string tempShape, tempPlinthType;
            inputStream >> tempShape;
            inputStream >> tempPlinthType;

            if (tempShape == "Candle" || tempShape == "0") {
                lamp.shape = Candle;
            }
            if (tempShape == "Tubular" || tempShape == "1") {
                lamp.shape = Tubular;
            }
            if (tempShape == "Globe" || tempShape == "2") {
                lamp.shape = Globe;
            }
            if (tempShape == "Pear" || tempShape == "3") {
                lamp.shape = Pear;
            }
            if (tempShape == "Ogive" || tempShape == "4") {
                lamp.shape = Ogive;
            }

            if (tempPlinthType == "E40" || tempPlinthType == "2") {
                lamp.plinthType = E40;
            }
            if (tempPlinthType == "E27" || tempPlinthType == "1") {
                lamp.plinthType = E27;
            }
            if (tempPlinthType == "E14" || tempPlinthType == "0") {
                lamp.plinthType = E14;
            }

            return inputStream;
        }
```
### Функція видалення елементу за індексом

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
        Readed list from the file: 
        0 0 noname 3 7 3 4 2
        0 0 noname 3 7 3 4 2
        1 1 some 100 10 200 4 2
        Are lamps[0] == lamps[1]: 1
        Are lamps[1] != lamps[2]: 1
```

**Варіант використання 2**: запустити тести у консолі:

38% поркиття оскільки тестувалися лише нові методи, інші були вже протестовані у минулих роботах та змінам не підлягали.

```
Filename                      Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
lamp.cpp                          102                52    49.02%          21                14    33.33%         163                94    42.33%
lamp_container.cpp                 47                39    17.02%          15                10    33.33%         127               104    18.11%
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                             149                91    38.93%          36                24    33.33%         290               198    31.72%
```

**Витоків пам'яті немає**
```
        ==226462== HEAP SUMMARY:
        ==226462==     in use at exit: 0 bytes in 0 blocks
        ==226462==   total heap usage: 24 allocs, 24 frees, 95,164 bytes allocated
        ==226462== 
        ==226462== All heap blocks were freed -- no leaks are possible
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з методами перевантаження базових операторів.