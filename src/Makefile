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

tests: test start_tests

all: build_object_files build_library testmemcpy testmemmove testmemcmp teststrpbrk start_tests gen_html clean

main:
	$(CC) $(FLAGS) testFiles/test.c sourceFiles/s21_strrchr.c
	./a.out

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C) 

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

test: 
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_memchr.c -L. s21_string.a  -o s21_test_memchr
	
start_tests:
	./s21_test_memchr

gcov_report:
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: start_tests gcov_report
	
clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info s21* a.out
	cd testFiles; \
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info a.out

rebuild:
	make clean
	make	
