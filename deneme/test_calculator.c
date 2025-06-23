#include "unity/src/unity.h"
#include "calculator.h"  // Bu satırı ekleyin!

void setUp(void) {}
void tearDown(void) {}

void test_add(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
}

void test_subtract(void) {
    TEST_ASSERT_EQUAL(1, subtract(3, 2));
}

void test_multiply(void) {
    TEST_ASSERT_EQUAL(6, multiply(2, 3));
}

void test_divide(void) {
    TEST_ASSERT_EQUAL_FLOAT(2.0, divide(4, 2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    RUN_TEST(test_multiply);
    RUN_TEST(test_divide);
    return UNITY_END();
}