CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

all:
	$(CC) $(FLAGS) main.cpp -o test
	./test 1

clean:
	rm test
