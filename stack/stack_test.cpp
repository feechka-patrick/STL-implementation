#include <iostream>
#include <stack>
#include <cstddef> // size_t , ?ptrdiff_t
#include <limits> // ?numeric_limit=
#include "stack.hpp"
#include <deque>

#define RED   "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


void test_announce(std::string str) {

	std::cout << std::endl << CYAN;
	std::cout << "=====================";
	std::cout << str;
	std::cout << "=====================" << std::endl;
	std::cout << RESET << std::endl;
}

void action_announce(std::string str) {
	std::cout << std::endl;
	std::cout << MAGENTA << ">>> action made: " << RESET;
	std::cout << str << std::endl;
}

template<typename T, class C>
void print(lib::stack<T, C> st){
	size_t s = st.size();
	std::cout << "size    : " << s << std::endl;
    std::cout << "arr     :" << std::endl;
    for (size_t i = 0; i < s; ++i) {
        if (i != 0 && i % 20 == 0)
            std::cout << std::endl;
        std::cout << st.top() << " ";
		st.pop();
    }
    std::cout << std::endl;
}

void top_test(){
	test_announce("top test");
	action_announce("default container: vector<int>");
	lib::stack<int> st;

	for(size_t i = 0; i < 10; ++i)
		st.push(i);

	print(st);

	action_announce("other container: deque<int>");
	lib::stack<int, std::deque<int> > st2;

	for(size_t i = 0; i < 10; ++i)
		st2.push(i);

	print(st2);
}

void empty_test(){
	test_announce("empty()");
	action_announce("default container: vector<int>");
	lib::stack<int> st;

	std::cout << st.empty() << std::endl;
	for(size_t i = 0; i < 10; ++i)
		st.push(i);
	std::cout << st.empty() << std::endl;

	action_announce("other container: deque<int>");
	lib::stack<int, std::deque<int> > st2;
	std::cout << st2.empty() << std::endl;
	for(size_t i = 0; i < 10; ++i)
		st2.push(i);
	std::cout << st2.empty() << std::endl;
}


// =============================================================================

int main(void)
{
	top_test();
	empty_test();
	return 0;
}