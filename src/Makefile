#!/bin/bash
FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=sourceFiles/*.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_string.a
GLFLAGS=--coverage
SAN=-fsanitize=address
GCOVFLAGS=-fprofile-arcs -ftest-coverage
sourceFilesArray=$(ls sourceFiles)

all: build_object_files build_library build_test start_tests clean

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C) 

build_object_files_san:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) $(SAN) -c $(FUNC_FILES_C) 

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

build_test: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_memset_test.c -L. s21_string.a  -o s21_memset_test
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_strncat_test.c -L. s21_string.a  -o s21_strncat_test
		$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_strcspn_test.c -L. s21_string.a  -o s21_strcspn_test

build_test_sanitizer: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) $(SAN) -g testFiles/s21_memset_test.c -L. s21_string.a  -o s21_memset_test
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) $(SAN) -g testFiles/s21_strncat_test.c -L. s21_string.a  -o s21_strncat_test
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) $(SAN) -g testFiles/s21_strcspn_test.c -L. s21_string.a  -o s21_strcspn_test

start_tests:
	./s21_memset_test
	./s21_strncat_test
	./s21_strcspn_test

start_leaks_tests: build_object_files build_library build_test 
	valgrind --leak-check=yes ./s21_memset_test
	valgrind --leak-check=yes ./s21_strncat_test
	valgrind --leak-check=yes ./s21_strcspn_test

start_sanitizer_tests: build_object_files_san build_library build_test_sanitizer 
	./s21_memset_test
	./s21_strncat_test
	./s21_strcspn_test
	make clean

gcov_report:
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: start_tests gcov_report


clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info *test *dSYM

rebuild:
	make clean
	make