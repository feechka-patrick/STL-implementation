CC = clang++
FLAGS = -Wall -Wextra -Werror -g
FLAGS_STD = -std=c++98
OBJ_NAME = stack_test
DIR_TEST = tests

all: clean clear insert erase resize

term: test
	cat result.diff | sed -r '/\|/ s//\x1b[31m&\x1b[0m/p'

clean:
	@echo > result.diff

test:
	@$(CC) $(FLAGS) $(FLAGS_STD) $(DIR_TEST)/stack_test_my.cpp -o $(DIR_TEST)/$(OBJ_NAME)1 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)1 > ./$(DIR_TEST)/my.output && rm $(DIR_TEST)/$(OBJ_NAME)1
	@$(CC) $(FLAGS) $(DIR_TEST)/stack_test_orig.cpp -o $(DIR_TEST)/$(OBJ_NAME)2 \
	&& ./$(DIR_TEST)/$(OBJ_NAME)2 > ./$(DIR_TEST)/orig.output && rm $(DIR_TEST)/$(OBJ_NAME)2
	@echo "\033[32mVECTOR TEST -------------------------------------\n\033[0m" >> result.diff
	@-diff -y ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output >> result.diff
	rm ./$(DIR_TEST)/my.output ./$(DIR_TEST)/orig.output

fclean:
	rm result.diff