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
#include <lamp_container.h>
#include <fstream>

/**
 * @brief Основна функція
 * 
 * Опис роботи:
 * - Створюємо об'єкт контейнера
 * - Зчитуэмо масив з файлу у контейнер
 * - Вводимо нове значення для lamps[2] елементу
 * - Виводимо контейнер у консоль
 * - Записуємо масив у файл
 * - Перевіряємо елементи на рівність
 * - Перевіряємо елементи на нерівність
 * 
 * @return (0) коли завершилась успішно
 */
int main()
{
    LampContainer myLamps("3");

    const std::string inputPath = "assets/input.txt";
    const std::string outputPath = "dist/output.txt";

    std::ifstream fin(inputPath);
    fin >> myLamps;
    fin.close();

    std::stringstream("1 1 some 100 10 200 4 2") >> myLamps[2];

    std::cout << std::endl << "Readed list from the file: " << std::endl;
    for (int i = 0; i < myLamps.getSize(); i++) {
        std::cout << myLamps[i] << std::endl;
    }

    std::ofstream fout(outputPath);
    fout << myLamps;
    fout.close();

    bool areEqual = myLamps[0] == myLamps[1];
    std::cout << "Are lamps[0] == lamps[1]: " << areEqual << std::endl;

    bool areNotEqual = myLamps[1] != myLamps[2];
    std::cout << "Are lamps[1] != lamps[2]: " << areNotEqual << std::endl;

	return 0;
}
