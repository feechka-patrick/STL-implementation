#include <iostream>
#include <iterator>
#include <vector>
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
    ft::vector<int> c;
    for (int i = 1; i <= 3; i++)
        c.push_back(i);
    std::cout << "The vector holds: ";
    print_container(c);

    c.resize(7);
    std::cout << "After resize up to 7: ";
    print_container(c);

    c.resize(5);
    std::cout << "After resize down to 5: ";
    print_container(c);

    c.resize(2);
    std::cout << "After resize down to 2: ";
    print_container(c);

    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    print_container(c);

}