/**
 * @file test.cpp
 * @author Sobolenko S.
 * @brief 
 * @version 0.1
 * @date 2022-06-11
 *
 * @copyright Copyright (c) 2022
 * 
 */
#include "../src/list.h"
#include <check.h>

/**
 * Верифікація роботи функцій
 * на основі набора вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(check_manufacturer_test)
{
	LampContainer myLamps;    

    const std::string inputFile = "assets/input.txt";
    const std::string outputFile = "dist/output.txt";

    myLamps.readFromFile(inputFile);

    myLamps.delItem(1);

    myLamps.sortByField();

    myLamps.writeToFile(outputFile);

    int expectedLeftStarts = 3;
    int actual = myLamps.getItem(0).getLeftStarts();

    ck_assert_int_eq(actual, expectedLeftStarts);
}
END_TEST

/**
 * Точка входу модуля тестування
 *
 * Опис роботи:
 *  - Запускає розроблені функції
 *  - По завершенню тестів виводиться на екран резуміюча інформація про стан 
 *    проходження тестів.
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("Lab18");

    tcase_add_test(tc_core, check_manufacturer_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
