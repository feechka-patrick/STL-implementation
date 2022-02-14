#include <iostream>
#include <iterator>
#include <vector>

void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
    std::cout << "size-> " << container.size() << "\n";
    std::cout << "cap -> " << container.capacity() << "\n\n";
}

int main ()
{
    std::vector<int> c1(3, 100);
    print(1, c1);
    
 
    std::vector<int>::iterator it = c1.begin();
    it = c1.insert(it, 200);
    print(2, c1);
 
    c1.insert(it, 2, 300);
    print(3, c1);


    it = c1.begin();
 
    std::vector<int> c2(2, 400);
    c1.insert(std::next(it, 2), c2.begin(), c2.end());
    print(4, c1);
 
    int arr[] = { 501,502,503 };
    c1.insert(c1.begin(), arr, arr + 3);
    print(5, c1);
}