#include <iostream>
#include <iterator>
#include "../vector.hpp"

void print_container(const ft::vector<int>& c) 
{
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\nsize-> " << c.size() << "\n";
    std::cout << "cap -> " << c.capacity() << "\n\n";
}
 
int main( )
{
    ft::vector<int> container;
    for (size_t i = 1; i < 4; i++)
        container.push_back(i);
 
    print_container(container);

    std::cout << "Before clear:";
    print_container(container);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
 
    std::cout << "Clear\n";
    container.clear();
 
    std::cout << "After clear:";
    print_container(container);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n' << '\n';
}