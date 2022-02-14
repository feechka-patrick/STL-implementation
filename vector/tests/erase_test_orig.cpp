#include <iostream>
#include <iterator>
#include <vector>

void print_container(const std::vector<int>& c) 
{
    for (int i : c) {
        std::cout << i << " ";
    }
    std::cout << "\nsize-> " << c.size() << "\n";
    std::cout << "cap -> " << c.capacity() << "\n\n";
}
 
int main( )
{
    std::vector<int> c;
    //c.erase(c.begin());
    for (size_t i = 0; i < 10; i++)
        c.push_back(i);
    print_container(c);
 
    auto it = c.erase(c.begin());
    std::cout << *it << "\n";
    print_container(c);
 
    it = c.erase(c.begin()+2, c.begin()+5);
    std::cout << *it << "\n";
    print_container(c);
 
}