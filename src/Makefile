CC = gcc
EFLAGS = -Wall -Wextra -Werror -std=c11 -g
CFLAGS = $(EFLAGS) -c
OFLAGS = $(EFLAGS) -o
S21_DECIMAL_C = functions/*.c
S21_DECIMAL_O = *.o
S21_SUITE_C = tests/*.c
S21_SUITE_O = suite_*.o

all: clean test

s21_decimal.a:
	$(CC) $(CFLAGS) $(S21_DECIMAL_C)
	ar r s21_decimal.a $(S21_DECIMAL_O)
	rm -rf *.o
	ranlib s21_decimal.a

test: s21_decimal.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) $(OFLAGS) test $(S21_SUITE_O) main.o s21_decimal.a -lm -lcheck -lsubunit
	rm -rf *.o *.a
	./test

gcov_report:
	$(CC) --coverage $(CFLAGS) $(S21_DECIMAL_C)
	ar r s21_decimal.a $(S21_DECIMAL_O)
	ranlib s21_decimal.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) --coverage $(OFLAGS) test $(S21_SUITE_O) main.o s21_decimal.a -lm -lcheck -lsubunit
	rm -rf *.o *.a
	./test
	lcov -t "GcovReport" -o GcovReport.info -c -d .
	genhtml -o report GcovReport.info
	open ./report/index-sort-f.html


check:
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem ./
	clang-format -n *.c *.h

clean:
	rm -rf test *.o *.gcno *.gcda *.info *.a *.gch GcovReport s21_decimal_test report valgrind-out.txt

rebuild: clean all
