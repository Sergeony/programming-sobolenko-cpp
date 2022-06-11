/**
 * @file main.cpp
 * @author Sobolenko S.
 * @brief Головний модуль для демонстрації виконаною роботи
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <lamp.h>
#include <lamps.h>

using namespace std;

/**
 * @brief Основна функція
 * 
 * Опис роботи:
 * - Створюємо об'єкт контейнера
 * - Створюємо декілька об'єктів класа Lamp за допомогою різних конструкторів
 * - Додаємо об'єкти до контейнеру
 * - Видаляемо один з них
 * - Сортуємо массив
 * - Виводимо результат до консолі
 * 
 * @return (0) коли завершилась успішно
 */
int main()
{
	LampContainer *myLamps = new LampContainer();
    
    Lamp *lamp1 = new Lamp();
    Lamp *lamp2 = new Lamp(false, true, "something", 10, 5, Globe, E27);
    Lamp *lamp3 = new Lamp(false, false, "noname", 3, 7, Pear, E14);
    Lamp *lamp4 = new Lamp(*lamp3);

    myLamps->append(*lamp1);
    myLamps->append(*lamp2);
    myLamps->append(*lamp3);
    myLamps->append(*lamp4);

    myLamps->delItem(1);

    myLamps->sortByField();

    myLamps->print();

    delete lamp1;
    delete lamp2;
    delete lamp3;
    delete lamp4;
    delete myLamps;

	return 0;
}
