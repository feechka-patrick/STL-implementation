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
    c.erase(c.begin());
    for (size_t i = 0; i < 10; i++)
        c.push_back(i);
    print_container(c);
 
    ft::vector<int>::iterator it = c.erase(c.begin());
    std::cout << *it << "\n";
    print_container(c);
 
    it = c.erase(c.begin()+2, c.begin()+5);
    std::cout << *it << "\n";
    print_container(c);

}