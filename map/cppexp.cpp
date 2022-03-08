#include "map.hpp"
#include <vector>
#include "pair.hpp"

#define _map ft::map

void show_vector_info(std::vector<int>& vector) {
    std::cout << "size    : " << vector.size()     << std::endl;
    std::cout << "capacity: " << vector.capacity() << std::endl;
    std::cout << "arr     :" << std::endl;
    for (size_t i = 0; i < vector.size(); ++i) {
        if (i != 0 && i % 20 == 0)
            std::cout << std::endl;
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

template <class T, class V, class C>
void fillMap(std::map<T, V, C>& mp){
   mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

std::vector<int> comparator_test_std() {
    std::map<int, int> mp;
    std::vector<int> v;
    fillMap(mp);
    for ( std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    std::map<int, int, std::greater<int> > mp2;
    mp2.insert(std::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    std::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for ( std::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for ( std::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for ( std::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for ( std::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for ( std::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    std::map<int, int, std::logical_and<int> > mp8;
    fillMap(mp8);
    for ( std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    v.push_back(mp1.size());
    return v;
}

template <class T, class V, class C>
void fillMap_1(ft::map<T, V, C>& mp){
    mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

std::vector<int> comparator_test_ft() {
    ft::map<int, int> mp;
    std::vector<int> v;
    fillMap_1(mp);
    for ( ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater<int> > mp1;
    fillMap_1(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    ft::map<int, int, std::greater<int> > mp2;
    mp2.insert(ft::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap_1(mp3);
    for ( ft::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::minus<int> > mp4;
    fillMap_1(mp4);
    for ( ft::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater_equal<int> > mp5;
    fillMap_1(mp5);
    for ( ft::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::multiplies<int> > mp6;
    fillMap_1(mp6);
    for ( ft::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::bit_xor<int> > mp7;
    fillMap_1(mp7);
    for ( ft::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::logical_and<int> > mp8;
    fillMap_1(mp8);
    for ( ft::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    v.push_back(mp1.size());

    return v;
}

int main() {
    std::vector<int> vv;

    vv = comparator_test_std();
    show_vector_info(vv);

    vv = comparator_test_ft();
    show_vector_info(vv);
}