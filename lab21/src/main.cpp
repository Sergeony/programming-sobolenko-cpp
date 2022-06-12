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
#include <list.hpp>

/**
 * @brief Основна функція
 * 
 * Опис роботи:
 * - Створюємо порожній список
 * - Додаємо 3 елементи
 * - Видаляємо 1 елемент
 * - Виводимо список на екран
 * - Сортуємо список
 * - Виводимо відсортований список
 * - Виводимо найменший елемент
 * - Знаходимо індекс елементу
 * - Повторюємо дії зі списком строк
 * 
 * @return (0) коли завершилась успішно
 */
int main()
{
    List<int> list1;

    list1.append(1);
    list1.append(7);
    list1.append(-2);

    list1.delItem(0);

    std::cout << "List before sorting: " << std::endl;
    list1.print();

    list1.sort();
    
    std::cout << std::endl << "List after sorting: " << std::endl;
    list1.print();

    std::cout << std::endl << "Min element: " << list1.getMin() << std::endl;

    std::cout << std::endl << "Get index of -2: " << list1.getIndex(-2) << std::endl;


    std::cout << std::endl;


    List<std::string> list2;

    list2.append("b");
    list2.append("c");
    list2.append("a");

    list2.delItem(0);

    std::cout << "List 2 before sotring: " << std::endl;
    list2.print();

    list2.sort();

    std::cout << std::endl << "List 2 after sorting: " << std::endl;
    list2.print();

    std::cout << std::endl << "Min element: " << list2.getMin() << std::endl;

    std::cout << std::endl << "Get index of 'a': " << list2.getIndex("a") << std::endl;
    
	return 0;
}
