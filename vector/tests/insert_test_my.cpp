#include <iostream>
#include <iterator>
#include <vector>
#include "../vector.hpp"

void print(int id, const ft::vector<int>& container)
{
    std::cout << id << ". ";
    for (int i; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << '\n';
    std::cout << "size-> " << container.size() << "\n";
    std::cout << "cap -> " << container.capacity() << "\n\n";
}

int main ()
{
    ft::vector<int> c1(3, 100);
    print(1, c1);
    
 
    ft::vector<int>::iterator it = c1.begin();
    it = c1.insert(it, 200);
    print(2, c1);
 
    c1.insert(it, 2, 300);
    print(3, c1);

 
    // // `it` no longer valid, get a new one:
    it = c1.begin();
 
    ft::vector<int> c2(2, 400);
    c1.insert(std::next(it, 2), c2.begin(), c2.end());
    print(4, c1);
 
    int arr[] = { 501,502,503 };
    c1.insert(c1.begin(), arr, arr + 3);
    print(5, c1);
}