CC = clang++
FLAGS = -Wall -Wextra -Werror
FLAGS_STD = -std=c++98
TEST_NAME = stack_test
DIR_TEST = tests

all: clean test

clean:
	-rm -rf a.out.dSYM
	-rm result.diff

test:
	clang++  $(FLAGS) $(FLAGS_STD) $(TEST_NAME).cpp -D lib=ft; ./a.out > my.output;
	clang++  $(FLAGS) $(FLAGS_STD) $(TEST_NAME).cpp -D lib=std; ./a.out > std.output;
	@echo "\033[32m ============================================ STACK TEST ============================================ \n\033[0m" >> result.diff
	diff -y std.output my.output >> result.diff; cat result.diff
	rm std.output my.output

leaks:
	clang++ -g $(TEST_NAME).cpp -D lib=ft
	valgrind ./a.out --leak-check=full --track-origins=yes
	rm a.out

fclean: clean
	rm std.output my.output