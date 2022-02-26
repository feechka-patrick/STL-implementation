#include "rbtree.hpp"

int main()
{
    ft::rbtree<std::pair<const int, int> > rbt;

    //auto a = std::pair<const int, int>(5, 9);

    rbt.insert(std::pair<const int, int>(1, 9));
    rbt.print();

    rbt.insert(std::pair<const int, int>(0, 9));
    rbt.print();

    rbt.insert(std::pair<const int, int>(5, 9));
    rbt.print();
}