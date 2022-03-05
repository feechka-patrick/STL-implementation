#include "pair.hpp"
#include "map.hpp"
#include "vector"

template <typename T, typename V>
void fillMap(std::map<T, V> mp){
    for (int i = 0, j = 0; i < 20; ++i, ++j)
         mp.insert(std::make_pair(i, j));
}

template <typename T, typename V, typename C>
void fillMap(std::map<T, V, C> mp){
    for (int i = 0, j = 0; i < 20; ++i, ++j)
         mp.insert(std::make_pair(i, j));
}

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


//     int i = 0;

//     ft::map<int, int> rbt;
//     for (int i = 0; i < 10; i++)
//         rbt.insert(ft::pair<int, int>(i, 1));
//     for (ft::map<int, int>::iterator it = rbt.begin(); it != rbt.end(); ++it)
//         std::cout << it->first << " " << it->second << std::endl;
    
//     std::map<int,int> mp;

//     std::map<int, int> mpp;
//     //std::map<int, int>::iterator it = --mpp.end();
//     for ( std::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++) { std::cout << (it->first); }
//     //for ( std::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { std::cout << (it->first); }
//     std::map<int, int> mp0;
//    // mp0.print(++i);
//     std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
//    // mp0.print(++i);
//     ii++;
//     std::cout << ((--ii)->first);
//     for (int i = 0, j = 10; i < 5; ++i, ++j)
//         mp.insert(std::make_pair(i, j));
//     std::map<int, int>::iterator it = mp.begin();
//     std::map<int, int>::iterator it2 = mp.end();
//     std::cout << (it->first);
//     it++;
//     it++;
//     it++;
//     it++;
//     std::cout << (it->first);
//     it++;
//     it--;
//     std::cout << (it->first);
//     it2--;
//     std::cout << (it2->first);
//     std::cout << (it2 == it);
//     std::cout << ((--it2)->first);
//     std::cout << ((it2--)->first);
//     std::cout << ((it2++)->first);
//     std::cout << ((++it2)->first);

    
    // ft::map<int,int> mp;
    // for (int i = 0, j = 0; i < 20; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));

    // ft::map<int,int> mp1;
    // for (int i = 20, j = 0; i < 40; ++i, ++j)
    //     mp1.insert(ft::make_pair(i, j));

    // mp.print(1);
    // mp1.print(1);

    // mp.swap(mp1);

    // mp.print(1);
    // mp1.print(1);

    
    // ft::map<int,int> mp;
    // for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));
    // ft::map<int, int> mp2;
    // for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, --j)
    //     mp.insert(ft::make_pair(i, j));
    // long *adr1 = reinterpret_cast<long *>(&mp);
    // long *adr2 = reinterpret_cast<long *>(&mp2);
    // mp.swap(mp2);
    // if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    // 	std::cout << (1) <<  std::endl;
    // std::cout << (mp2.size()) <<  std::endl;
    //  ft::map<int, int>::iterator it = mp2.begin();
    // for (; it != mp2.end(); ++it) {
    //     std::cout << (it->first) <<  std::endl;
    //     std::cout << (it->second) << std::endl;
    // }
    // ft::swap(mp, mp2);
    //  ft::map<int, int>::iterator it2 = mp2.begin();
    // for (; it2 != mp2.end(); ++it2) {
    //     std::cout << (it2->first) <<  std::endl;
    //     std::cout << (it2->second) << std::endl;
    // }

    namespace ft = std;
    ft::map<int,int> mp;
    fillMap(mp);
    for ( ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    std::cout << (mp1.begin()->first);
    mp1.erase(41);
    ft::cout << (mp1.begin()->first);
    mp1.erase(29);
    std::cout << (mp1.begin()->first);
    ft::map<int, int, std::greater<int> > mp2;
    mp2.insert(std::make_pair(3, 3));
    std::cout << (mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        std::cout << (1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for ( ft::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { std::cout << (it->first); }
    std::map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for ( ft::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for ( ft::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for ( ft::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for ( ft::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { std::cout << (it->first); }
    ft::map<int, int, std::logical_and<int> > mp8;
    fillMap(mp8);
    for ( ft::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { std::cout << (it->first); }
    for ( ft::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { std::cout << (it->first); }
    std::cout << (mp1.size());

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