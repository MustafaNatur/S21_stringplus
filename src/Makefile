#!/bin/bash
# requirements
# ubuntu 22.04 LTS
# sudo apt install pkg-config
# sudo apt install check
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
TST_LIBS?=-lcheck
ifeq ($(shell uname), Linux)
TST_LIBS=-lcheck_pic $(shell pkg-config --libs check) -lpthread -lrt -lm
endif
all: build_object_files build_library testmemcpy testmemmove testmemcmp teststrpbrk start_tests gen_html clean

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C) 

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

testmemcpy:
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_memcpy.c -o s21_test_memcpy $(TST_LIBS) -L. s21_string.a
	
testmemmove:
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_memmove.c -o s21_test_memmove $(TST_LIBS) -L. s21_string.a
	
testmemcmp:
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_memcmp.c  -o s21_test_memcmp $(TST_LIBS) -L. s21_string.a 
	
teststrpbrk:
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_strpbrk.c  -o s21_test_strpbrk $(TST_LIBS) -L. s21_string.a 
	
start_tests:
	./s21_test_memcpy
	./s21_test_memmove
	./s21_test_memcmp
	./s21_test_strpbrk

gcov_report:
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: start_tests gcov_report
	
clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info s21*

rebuild:
	make clean
	make	
