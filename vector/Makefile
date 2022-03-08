CC = clang++
FLAGS = -Wall -Wextra -Werror
FLAGS_STD = -std=c++98
OBJ_NAME = vector_test
DIR_TEST = tests

all: clean test
	cat result.diff | sed '/\|/ s//\x1b[31m&\x1b[0m/p'

clean:
	rm -rf result.diff
	@echo > result.diff

test:
	@$(CC) $(FLAGS) $(FLAGS_STD) $(DIR_TEST)/vector_test_my.cpp -o $(DIR_TEST)/$(OBJ_NAME)1 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)1 > ./$(DIR_TEST)/my.output
	@$(CC) $(FLAGS) $(DIR_TEST)/vector_test_orig.cpp -o $(DIR_TEST)/$(OBJ_NAME)2 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)2 > ./$(DIR_TEST)/orig.output
	@echo "\033[32mVECTOR TEST -------------------------------------\n\033[0m" >> result.diff
	@-diff -y ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output >> result.diff
	rm ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output

mytest:
	clang++  $(FLAGS) $(FLAGS_STD) namor_vector_test.cpp -D lib=ft; ./a.out > my.output;
	clang++  $(FLAGS) $(FLAGS_STD) namor_vector_test.cpp -D lib=std; ./a.out > std.output;
	diff -y std.output my.output > result.diff; cat result.diff
	rm std.output my.output

leaks:
	clang++ -g namor_vector_test.cpp -D lib=ft
	valgrind ./a.out --leak-check=full --track-origins=yes
	rm a.out

fclean:
	rm result.diff