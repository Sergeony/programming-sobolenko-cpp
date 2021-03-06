# ЛабораторнароботаNo22. (х2)ООП.STL.Вступ до Стандартної бібліотеки шаблонів

## 1 Вимоги

### 1.1 Розробник

* Соболенко Cергій Сергійович;
* студент групи КН-921б;
* 11-jul-2021.

### 1.3 Індивідуальне завдання

Поширити реалізацію лабораторної роботи “Динамічні масиви” наступним шляхом:
- замінити масив та CRUD (create/read/update/delete) методи роботи з ним на використання STL
- додати функцію сортування коллекції з використанням функтора

## 2 Опис програми

### 2.1 Функціональне призначення

Переробити минулу роботу, використовуючи STL

### 2.2 Важливі фрагменти програми

### Реалізація сортування

```c++
        /* FUNCTOR */

        class Functor {
        public:
                bool operator()(int x, int y);
        };

        bool Functor::operator()(int x, int y) { return x < y; }


        void List::sort() {
                std::sort(this->array.begin(), this->array.end(), Functor());
        }
```

## Варіанти використання

**Варіант використання 1**: послідовність дій для запуску програми у консолі:

- запустити програму;
- подивитись результати виконання програми;

```
        List before sorting: 
        7 -2
        List after sorting: 
        -2 7
        Min element: -2

        Get index of -2: 0

        Element on 1 position: 7
```

**Варіант використання 2**: запустити тести у консолі:

85% покриття тестами достатньо для цієї роботи.

```
        Filename                      Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        src/list.hpp                       34                15    55.88%          12                 3    75.00%          51                18    64.71%
        test/test.cpp                       1                 0   100.00%           1                 0   100.00%          14                 0   100.00%
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        TOTAL                              35                15    57.14%          13                 3    76.92%          65                18    72.31%
```

**Витоків пам'яті немає**
```
        ==262660== HEAP SUMMARY:
        ==262660==     in use at exit: 0 bytes in 0 blocks
        ==262660==   total heap usage: 5 allocs, 5 frees, 73,756 bytes allocated
        ==262660== 
        ==262660== All heap blocks were freed -- no leaks are possible
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи готовими колекціями та алгоритмами з бібліотеки STL.