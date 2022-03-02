#include "pair.hpp"
#include "map.hpp"

int main()
{
    int i = 0;
    ft::map<const int, int> rbt;

    //auto a = ft::pair<const int, int>(5, 9);

    rbt.insert(ft::pair<const int, int>(5, 9));
    rbt.insert(ft::pair<const int, int>(3, 9));
    rbt.insert(ft::pair<const int, int>(8, 9));
    rbt.insert(ft::pair<const int, int>(7, 9));
    rbt.insert(ft::pair<const int, int>(9, 9));
    rbt.insert(ft::pair<const int, int>(4, 9));

    rbt.print(++i);

    rbt.erase(5);
    rbt.print(++i);

    rbt.erase(3);
    rbt.print(++i);

    rbt.erase(3);
    rbt.print(++i);

    rbt.erase(8);
    rbt.print(++i);

    rbt.erase(7);
    rbt.print(++i);

    rbt.erase(9);
    rbt.print(++i);
}

//leaks --atExit -- ./a.out
//leaks a.out