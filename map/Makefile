CC = clang++
FLAGS = -Wall -Wextra -Werror -g
FLAGS_STD = -std=c++98
OBJ_NAME = map_test
DIR_TEST = tests

all: clean test
	cat result.diff | sed '/\|/ s//\x1b[31m&\x1b[0m/p'

clean:
	@echo > result.diff

test:
	@$(CC) $(FLAGS) $(FLAGS_STD) $(DIR_TEST)/map_ft.cpp -o $(DIR_TEST)/$(OBJ_NAME)1 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)1 > ./$(DIR_TEST)/my.output
	@$(CC) $(FLAGS) $(DIR_TEST)/map_std.cpp -o $(DIR_TEST)/$(OBJ_NAME)2 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)2 > ./$(DIR_TEST)/orig.output
	@echo "\033[32m MAP TEST -------------------------------------\n\033[0m" >> result.diff
	@-diff -y ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output >> result.diff
	rm ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output

mytest: clean 
	clang++ $(FLAGS) $(FLAGS_STD) my_test_map.cpp -D lib=ft; ./a.out > my.output;
	clang++ $(FLAGS) $(FLAGS_STD) my_test_map.cpp -D lib=std; ./a.out > std.output;
	@echo "\033[32m ============================================ MAP TEST ============================================ \n\033[0m" >> result.diff
	diff -y std.output my.output >> result.diff; cat result.diff
	

leaks:
	clang++ -g my_test_map.cpp -D lib=ft
	valgrind ./a.out --leak-check=full
	rm a.out

fclean:
	rm result.diff