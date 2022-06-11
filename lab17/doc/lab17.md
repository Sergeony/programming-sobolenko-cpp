# Лабораторна робота No17. ООП. Вступ до ООП

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 06-jul-2021.

### 1.3 Індивідуальне завдання

Для предметної галузі з розділу “Розрахункове завдання / Iндивідуальні завдання” розробитидва класи:
- клас, що відображає сутність “базового класу”, у тому числі:
    - конструктор за замовчуванням, копіювання та конструктор з аргументами (реалізація конструкторів повинна бути продемонстрована за допомогою списків ініціалізацій);
    - деструктор;
    - гетери та сетери на поля класу;
    - метод виводу об’єкта на екран: print();
- клас, що має у собі динамічний масив об’єктів базового класу та має в собі методи додавання, видалення елемента, отримання елемента по індексу (або ідентифікатору),вивід усіх елементів на екран. 

## 2 Опис програми

### 2.1 Функціональне призначення

Переробити минулу роботу за допомогою ООП реалізації.

### 2.2 Важливі фрагменти програми

#### Клас лампочки

```c
        /**
         * @brief Базовий клас - лампочка
         */
        class Lamp {
            private:
                bool isTurnedOn;
                bool isBroken;
                string manufacturer;
                int leftStarts;
                int wattPerHour;
                int colourTemperature;
                enum Shape shape;
                enum PlinthType plinthType;
            
            public:
                Lamp() : isTurnedOn(true),
                        isBroken(false),
                        manufacturer("Meizu"),
                        leftStarts(1000),
                        wattPerHour(10),
                        colourTemperature(1500),
                        shape(Tubular),
                        plinthType(E40) {}
                
                Lamp(bool isTurnedOn,
                    bool isBroken,
                    string manufacturer,
                    int leftStarts,
                    int wattPerHour,
                    enum Shape shape,
                    enum PlinthType plinthType);
                
                Lamp(const Lamp& copy);

                ~Lamp();

                bool getIsTurnedOn() const;
                void setIsTurnedOn(bool newIsTurnedOn);

                bool getIsBroken() const;
                void setIsBroken(bool newIsBroken);

                string getManufacturer() const;

                int getLeftStarts() const;
                void setLeftStarts(int newLeftStarts);

                int getWattPerHour() const;

                int getColourTemperature() const;

                enum Shape getShape() const;

                enum PlinthType getPlinthType() const;

                void print();
        };
```

### Клас контейнера

```c
/**
 * @brief Клас-контейнер для класу Lamp
 */
        class LampContainer {
            private:
                Lamp *lamps;
                int size;
            
            public:
                LampContainer(): size(DEFAULT_ARRAY_SIZE)
                {
                    this->lamps = new Lamp[DEFAULT_ARRAY_SIZE];
                }
                explicit LampContainer(int size);
                LampContainer(const LampContainer& copy);

                ~LampContainer();

                int getSize() const;

                void append(Lamp& newLamp);

                void delItem(int pos);

                Lamp& getItem(int pos);

                void print();

                void sortByField();
        };
```
### Функція видалення елементу за індексом

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
        0 0 noname 3 7 3 3 0
        0 0 noname 3 7 3 3 0
        1 0 Meizu 1000 10 1500 1 2
```

**Варіант використання 2**: запустити тести у консолі:

59% поркиття є задовільною кількістю для даної роботи. Але взагалі, краще коли б були покриті усі функції.

```
        Running suite(s): Programming
        100%: Checks: 1, Failures: 0, Errors: 0
        test/test.cpp:41:P:Lab17:check_manufacturer_test:0: Passed
        llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
        llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
        Filename                      Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        lamp.cpp                           15                11    26.67%          15                11    26.67%          62                40    35.48%
        lamps.cpp                          29                 7    75.86%           9                 4    55.56%          66                16    75.76%
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        TOTAL                              44                18    59.09%          24                15    37.50%         128                56    56.25%
        llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.cpp --format html > dist/coverage.html
```

**Витоків пам'яті немає**
```
        ==179321== HEAP SUMMARY:
        ==179321==     in use at exit: 0 bytes in 0 blocks
        ==179321==   total heap usage: 13 allocs, 13 frees, 74,880 bytes allocated
        ==179321== 
        ==179321== All heap blocks were freed -- no leaks are possible
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи з класами та ії основними можливостями(конструктори/деструктори).