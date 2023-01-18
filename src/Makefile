#!/bin/bash
FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=sourceFiles/*.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_string.a
GLFLAGS=--coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage
sourceFilesArray=$(ls sourceFiles)

all: build_object_files build_library test start_tests gen_html clean

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C) 

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

test: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_memset_test.c -L. s21_string.a  -o s21_memset_test
	
start_tests:
	./s21_memset_test

gcov_report:
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: start_tests gcov_report
	
clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info s21_*_test

rebuild:
	make clean
	make
