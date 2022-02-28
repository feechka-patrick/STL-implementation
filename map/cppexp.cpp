#include "rbtree.hpp"

int main()
{
    int i = 0;
    ft::rbtree<const int, int> rbt;

    //auto a = std::pair<const int, int>(5, 9);

    rbt.insert(std::pair<const int, int>(5, 9));
    rbt.insert(std::pair<const int, int>(3, 9));
    rbt.insert(std::pair<const int, int>(8, 9));
    rbt.insert(std::pair<const int, int>(7, 9));
    rbt.insert(std::pair<const int, int>(9, 9));
    rbt.insert(std::pair<const int, int>(4, 9));

    rbt.print(++i);

    rbt.deleteNode(std::pair<const int, int>(5, 9));
    rbt.print(++i);
    rbt.deleteNode(std::pair<const int, int>(3, 9));
    rbt.print(++i);

    rbt.deleteNode(std::pair<const int, int>(8, 9));
    rbt.print(++i);

    rbt.deleteNode(std::pair<const int, int>(7, 9));
    rbt.print(++i);

    rbt.deleteNode(std::pair<const int, int>(9, 9));
    rbt.print(++i);

    rbt.deleteNode(std::pair<const int, int>(4, 9));

    rbt.print(++i);
    rbt.deleteNode(std::pair<const int, int>(4, 9));
}

//leaks --atExit -- ./a.out
//leaks a.out