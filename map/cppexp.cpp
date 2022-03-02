#include "pair.hpp"
#include "map.hpp"
#include "vector"

int main()
{
    int _ratio = 300;
    int i = 0;

    ft::map<int, int> rbt;
    for (int i = 0; i < 10; i++)
        rbt.insert(ft::pair<int, int>(i, 1));
    for (ft::map<int, int>::iterator it = rbt.begin(); it != rbt.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    
    ft::map<int,int> tmp;

    rbt.print(++i);

    tmp = rbt;

    tmp.print(++i);


    // std::vector<int> v;

    // for (int i = 0, j = 10; i < 3 * _ratio; ++i, ++j) {
    //     rbt.insert(ft::make_pair(i, j));
    // }
    // rbt.print(++i);
    // ft::map<int, int> mp2(rbt.begin(), rbt.end());
    // ft::map<int, int>::iterator it = mp2.begin();
    // for (int i = 0; i < 3 * _ratio; ++i, it++) {
    //     v.push_back(it->first);
    //     v.push_back(it->second);
    // }

    // rbt.print(++i);

    //auto a = ft::pair<const int, int>(5, 9);

    // rbt.insert(ft::pair<const int, int>(5, 9));
    // rbt.insert(ft::pair<const int, int>(3, 9));
    // rbt.insert(ft::pair<const int, int>(8, 9));
    // rbt.insert(ft::pair<const int, int>(7, 9));
    // rbt.insert(ft::pair<const int, int>(9, 9));
    // rbt.insert(ft::pair<const int, int>(4, 9));

    // rbt.print(++i);

    // rbt.erase(5);
    // rbt.print(++i);

    // rbt.erase(3);
    // rbt.print(++i);

    // rbt.erase(3);
    // rbt.print(++i);

    // rbt.erase(8);
    // rbt.print(++i);

    // rbt.erase(7);
    // rbt.print(++i);

    // rbt.erase(9);
    // rbt.print(++i);
}

//leaks --atExit -- ./a.out
//leaks a.out