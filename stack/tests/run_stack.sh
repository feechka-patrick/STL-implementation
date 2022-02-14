#! /bin/zsh

mkdir logs

  clang++ -Wall -Wextra -Werror -fsanitize=address my_stack_test.cpp -o logs/user_bin &&
  ./logs/user_bin > logs/user.output &&
  clang++ -Wall -Wextra -Werror -fsanitize=address orig_stack_test.cpp -o logs/bin &&
  ./logs/bin > logs/std.output &&
  diff logs/user.output logs/std.output