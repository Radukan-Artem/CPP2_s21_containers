CC=clang++
CFLAGS=-c -Wall  -Werror -Wextra -g -std=c++17
CCTEST=clang++ -fprofile-arcs -ftest-coverage
GTESTFLAGS = $(shell pkg-config --cflags --libs gtest)

all: test
	clear
	./unit_tests

test: clean unit_tests.o tests_suite
	$(CC) $(GTESTFLAGS) unit_tests.o tests_*.o -o unit_tests -lgtest 


unit_tests.o: unit_tests.cpp
	$(CC) $(CFLAGS) unit_tests.cpp

tests_suite: test_suite_creation_functions/*.cpp
	$(CC) $(CFLAGS) test_suite_creation_functions/*.cpp

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.gcov