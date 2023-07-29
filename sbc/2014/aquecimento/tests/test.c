#include "./minunit/minunit.h"

int isPositive(int num);

MU_TEST(positive_returns_true) {
  int numTest = 10;
  int expected = 1;

  int result = isPositive(numTest);

  mu_assert_int_eq(expected, result);
}

MU_TEST(negative_returns_false) {
  int numTest = -1;
  int expected = 0;

  int result = isPositive(numTest);

  mu_assert_int_eq(expected, result);
}


MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(positive_returns_true);
  MU_RUN_TEST(negative_returns_false);
}

int main(int argc, char** argv) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
