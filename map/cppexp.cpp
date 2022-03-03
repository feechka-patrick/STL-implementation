#include "pair.hpp"
#include "map.hpp"
#include "vector"

int main()
{


    //10057%
    // int k = 0;
    int _ratio = 1;
    // ft::map<int,int> mp;
    //  for (int i = 0, j = 0; i < 20 * _ratio; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));
    // std::cout << (mp.size());
    // mp.print(++k);
    // for (int i = 0; i < 7 * _ratio; ++i)
    // {
    //     mp.print(++k);
    //     mp.erase(i);
    // }
    // std::cout << (mp.size());

//     ft::map<int,int> mp;
//     for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
//         mp.insert(ft::make_pair(i, j));
    
//    // mp.print(1);
//    ft::map<int, int>::iterator it1 = mp.begin();
//    ft::map<int, int>::iterator it2 = --mp.end();
//     mp.erase(mp.begin(), --mp.end());
//    // mp.print(2);
//     std::cout << (mp.begin()->first);


    // int _ratio = 1;
    // std::map<int,int> mp;
    //  for (int i = 0, j = 0; i < 20 * _ratio; ++i, ++j)
    //     mp.insert(std::make_pair(i, j));
    // std::cout << (mp.size());
    // for (int i = 0; i < 7 * _ratio; ++i)
    // {
    //     mp.erase(i);
    // }
    // std::cout << (mp.size());

    
    //753135105353
    // std::map<int,int> mp;

    // mp.insert(std::make_pair(5, 5));
    // mp.insert(std::make_pair(3, 3));
    // mp.insert(std::make_pair(7, 7));
    // std::map<int, int>::reverse_iterator rit = mp.rbegin();
    // std::map<int, int>::reverse_iterator rit2 = mp.rend();
    // std::cout << (rit->first);
    // rit++;
    // rit2--;
    // std::cout << (rit->first);
    // std::cout << (rit2->first);
    // rit++;
    // std::cout << (*rit == *rit2);
    // rit2--;
    // std::cout << (rit->first);
    // std::cout << (rit2->first);
    // std::cout << (*rit2 > *rit);
    // std::cout << (*rit2 < *rit);
    // std::cout << ((--rit)->first);
    // std::cout << ((++rit2)->first);
    // std::cout << ((rit--)->first);
    // std::cout << ((rit2++)->first);

    // ft::map<int,int> mp;
    // for (int i = 0, j = 10; i < 5; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));


    int i = 0;

    ft::map<int, int> rbt;
    for (int i = 0; i < 10; i++)
        rbt.insert(ft::pair<int, int>(i, 1));
    for (ft::map<int, int>::iterator it = rbt.begin(); it != rbt.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    
    ft::map<int,int> mp;

    ft::map<int, int> mpp;
    for ( ft::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int> mp0;
    mp0.print(++i);
    ft::map<int, int>::iterator ii = mp0.insert(ft::make_pair(3, 3)).first;
    mp0.print(++i);
    ii++;
    std::cout << ((--ii)->first);
    ft::map<int, int>::iterator it = mp.begin();
    ft::map<int, int>::iterator it2 = mp.end();
    std::cout << (it->first);
    it++;
    it++;
    it++;
    it++;
    std::cout << (it->first);
    it++;
    it--;
    std::cout << (it->first);
    it2--;
    std::cout << (it2->first);
    std::cout << (it2 == it);
    std::cout << ((--it2)->first);
    std::cout << ((it2--)->first);
    std::cout << ((it2++)->first);
    std::cout << ((++it2)->first);


    // std::vector<int> v;

    // for (int i = 0, j = 10; i < 3 * _ratio; ++i, ++j) {
    //     rbt.insert(ft::make_pair(i, j));
    // }
    // rbt.print(++i);
    // ft::map<int, int> mp2(rbt.begin(), rbt.end());
    // ft::map<int, int>::iterator it = mp2.begin();
    // for (int i = 0; i < 3 * _ratio; ++i, it++) {
    //     std::cout << (it->first);
    //     std::cout << (it->second);
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