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

all: build_object_files build_library build_test start_tests gen_html



build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C) 

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

build_test: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_memchr_test.c -L. s21_string.a  -o s21_memchr_test
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_strerror_test.c -L. s21_string.a  -o s21_strerror_test


build_test_sanitizer: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(SAN) $(GCOVFLAGS) testFiles/s21_memchr_test.c -L. s21_string.a  -o s21_memchr_test
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(SAN) $(GCOVFLAGS) testFiles/s21_strerror_test.c -L. s21_string.a  -o s21_strerror_test



start_tests:
	./s21_memchr_test
	./s21_strerror_test
	

start_leaks_tests: build_object_files build_library build_test 
	leaks -atExit -- ./s21_memchr_test
	leaks -atExit -- ./s21_strerror_test

start_sanitizer_tests: build_object_files build_library build_test_sanitizer 
	./s21_memchr_test
	./s21_strerror_test
	make clean



gcov_report:
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: gcov_report
	


clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info s21*

rebuild:
	make clean
	make