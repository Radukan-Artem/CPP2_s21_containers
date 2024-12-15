#include "unit_tests.h"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  // Запускаем все тесты
  return RUN_ALL_TESTS();
}