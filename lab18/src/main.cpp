/**
 * @file main.cpp
 * @author Sobolenko S.
 * @brief Головний модуль для демонстрації виконаною роботи
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list.h>

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
	LampContainer myLamps;

    const std::string inputFile = "assets/input.txt";
    const std::string outputFile = "dist/output.txt";

    myLamps.readFromFile(inputFile);

    myLamps.delItem(1);

    myLamps.sortByField();

    myLamps.writeToFile(outputFile);

    std::cout << myLamps.print() << std::endl;

	return 0;
}
