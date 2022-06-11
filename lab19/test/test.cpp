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
#include <../src/lamp_container.h>
#include <check.h>

/**
 * Верифікація роботи функцій
 * на основі набора вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(overloaded_operators_test)
{
    LampContainer myLamps("3");

    const std::string inputPath = "assets/input.txt";
    const std::string outputPath = "dist/output.txt";

    std::ifstream fin(inputPath);
    fin >> myLamps;
    fin.close();

    std::stringstream inputStream("1 0 test 1000 10 1000 1 2");
    inputStream >> myLamps[2];

    std::stringstream resultStream;
    for (int i = 0; i < myLamps.getSize(); i++) {
       resultStream << myLamps[i] << std::endl;
    }
    std::string resultString = resultStream.str();

    std::string expectedString = "0 0 noname 3 7 3 4 2\n"
                                 "0 0 noname 3 7 3 4 2\n"
                                 "1 0 test 1000 10 1000 1 2\n";

    std::cout << expectedString << std::endl << resultString;

    ck_assert(resultString == expectedString);

    bool areEqual = myLamps[0] == myLamps[1];
    ck_assert(areEqual);

    bool areNotEqual = myLamps[1] != myLamps[2];
    ck_assert(areNotEqual);
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
    TCase *tc_core = tcase_create("Lab19");

    tcase_add_test(tc_core, overloaded_operators_test);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
