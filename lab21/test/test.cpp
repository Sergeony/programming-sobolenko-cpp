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
#include <../src/list.hpp>
#include <check.h>

/**
 * Верифікація роботи функцій
 * на основі набора вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(template_class_test)
{
    List<int> list1;

    list1.append(1);
    list1.append(7);
    list1.append(-2);
    list1.delItem(0);

    list1.sort();
    int expected_list[] = {-2, 7};
    for (int i = 0; i < 2; i++) {
        ck_assert_int_eq(list1.getItem(i), expected_list[i]);
    }

    int actual_min = list1.getMin();
    int expected_min = -2;
    ck_assert_int_eq(actual_min, expected_min);

    int actual_index = list1.getIndex(-2);
    int expected_index = 0;
    ck_assert_int_eq(actual_index, expected_index);
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
    TCase *tc_core = tcase_create("Lab21");

    tcase_add_test(tc_core, template_class_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
