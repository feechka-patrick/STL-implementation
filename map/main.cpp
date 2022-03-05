
#include <iostream>
#include <vector>
#include <map>
#include "map.hpp"
#include "../vector/vector.hpp"

class B
{
	public:
		std::string a;
		std::string b;
		char *str;
		B()
		{
			a = "Hello";
			b = ", World!";
		}
};

template <class T1, class T2>
void print_map(ft::map<T1, T2> &v)
{
	(void)v;
	typename ft::map<T1, T2>::iterator begin = v.begin();
	typename ft::map<T1, T2>::iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

template <class T1, class T2>
void print_map(const ft::map<T1, T2> &v)
{
	(void)v;
	typename ft::map<T1, T2>::const_iterator begin = v.begin();
	typename ft::map<T1, T2>::const_iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

void test_constructors()
{
	ft::map<int, int> one;
	print_map(one);
	one[0] = 0;
	one[1] = 1;
	one[2] = 3;
	one[100] = 100;
	one[3] = 3;
	print_map(one);

	ft::map<int, int> two(one);
	print_map(two);
	std::cout << (one == two) << std::endl;
	std::vector<ft::pair<int, int> > vector;
	for (int i = 0; i < 10000; i++)
		vector.push_back(ft::pair<int, int>(i, i));
	std::vector<ft::pair<int, int> >::iterator begin = vector.begin();
	std::vector<ft::pair<int, int> >::iterator end = vector.end();
	ft::map<int, int> three(begin, end);
	print_map(three);

	three = one;
	print_map(three);
}

void test_iterators()
{
	ft::map<int, int> a;
	a[0] = 20;
	a[10] = 40;
	a[1] = 60;
	a[2] = 80;
	a[5] = 100;
	ft::map<int, int>::iterator begin = a.begin();
	ft::map<int, int>::iterator end = a.end();
	ft::map<int, int>::const_iterator cbegin = a.begin();
	ft::map<int, int>::const_iterator cend = a.end();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void test_reverse_iterators()
{
	ft::map<int, int> a;
	a[0] = 20;
	a[10] = 40;
	a[1] = 60;
	a[2] = 80;
	a[5] = 100;
	ft::map<int, int>::reverse_iterator begin = a.rbegin();
	ft::map<int, int>::reverse_iterator end = a.rend();
	ft::map<int, int>::const_reverse_iterator cbegin = a.rbegin();
	ft::map<int, int>::const_reverse_iterator cend = a.rend();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;

	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void test_empty()
{
	ft::map<char, int> a;
	std::cout << a.empty() << std::endl;
	a['a'] = 1;
	print_map(a);
	std::cout << a.empty() << std::endl;
	a.erase('a');
	std::cout << a.empty() << std::endl;
	ft::map<char, int> b(a);
	std::cout << b.empty() << std::endl;
	print_map(a);
}

void test_size()
{
	ft::map<char, int> map;
	std::cout << map.size() << std::endl;
	map['a'] = 1;
	std::cout << map.size() << std::endl;
	for (char a = 'a'; a <= 'z'; a++)
		map[a] = a;
	std::cout << map.size() << std::endl;
	print_map(map);
	std::cout << map.max_size() << std::endl;
}

void test_element_access()
{
	ft::map<int, int> map;
	print_map(map);
	map[0] = 0;
	print_map(map);
	for (int i = 0; i < 100; i++)
		map[i] = i;
	print_map(map);
	for (int i = 0; i < 50; i++)
		std::cout << map[i] << " ";
	std::cout << std::endl;
}

void test_insert1()
{
	ft::map<int, int> map;
	for (int i = 0; i < 1000000; i++)
		map.insert(ft::pair<int, int>(i, i));
	map.insert(ft::pair<int, int>(10, 10));
	map.insert(ft::pair<int, int>(11, 10));
	map.insert(ft::pair<int, int>(11, 0));
	std::cout << map[11] << std::endl;
	print_map(map);
}

void test_insert2()
{
	ft::map<int, int> map;
	ft::map<int, int>::iterator it = map.begin();
	for (int i = 0; i < 1000000; i++)
		map.insert(it, ft::pair<int, int>(i, i+1));
	print_map(map);
	ft::map<int, int>::iterator it2 = map.begin();
	(it2++)++;
	for (int i = 0; i < 1000000; i++)
		map.insert(it2, ft::pair<int, int>(i, i+1));
	print_map(map);
	for (int i = 0; i < 1000000; i++)
		map.insert(it2 = map.end(), ft::pair<int, int>(i, i+1));
	print_map(map);
}

void test_insert3()
{
	ft::map<int, int> map;
	for (int i = 0; i < 10000; i++)
		map[i] = i;
	print_map(map);
	ft::map<int, int>::iterator begin = map.begin();
	ft::map<int, int>::iterator end = map.end();
	ft::map<int, int> map2;
	map2.insert(begin, end);
	print_map(map2);

	std::vector<ft::pair<int, int> > vector;
	for (int i = 0; i < 1000; i++)
		vector.push_back(ft::pair<int, int>(i, i));
	std::vector<ft::pair<int, int> >::iterator begin_v = vector.begin();
	std::vector<ft::pair<int, int> >::iterator end_v = vector.end();
	ft::map<int, int> map3;
	map3[1999] = 9;
	map3.insert(begin_v, end_v);
	print_map(map3);
}

void test_erase1()
{
	std::vector<ft::pair<int, int> > vector;
	for (int i = 0; i < 1000; i++)
		vector.push_back(ft::pair<int, int>(i, i));
	std::vector<ft::pair<int, int> >::iterator begin_v = vector.begin();
	std::vector<ft::pair<int, int> >::iterator end_v = vector.end();
	ft::map<int, int> map;
	map[1999] = 9;
	map.insert(begin_v, end_v);
	print_map(map);

	ft::map<int, int>::iterator last = map.end();
	last--;
	map.erase(map.begin());
	print_map(map);
	map.erase(last);
	print_map(map);
}

void test_erase2()
{
	ft::map<int, int> map;
	for (int i = 0; i < 10000; i++)
		map[i] = i;
	print_map(map);
	for (int i = 0; i < 10000; i++)
		map.erase(i);
	print_map(map);
}

void test_erase3()
{
	ft::map<int, int> map;
	for (int i = 0; i < 10000; i++)
		map[i] = i;
	print_map(map);
	ft::map<int, int>::iterator begin_1 = map.begin();
	ft::map<int, int>::iterator end_1 = map.end();
	begin_1++;
	end_1--;
	map.erase(begin_1, end_1);
	print_map(map);
}

void test_swap_clear()
{
	ft::map<int, int> map;
	for (int i = 0; i < 10000; i++)
		map[i] = i;
	print_map(map);
	ft::map<int, int> map_swap;
	for (int i = 0; i < 10; i++)
		map[i] = i;
	print_map(map_swap);
	map.swap(map_swap);
	print_map(map_swap);
	print_map(map);
	std::swap(map_swap, map);
	print_map(map_swap);
	print_map(map);
	map.clear();
	map_swap.clear();
	print_map(map_swap);
	print_map(map);
}

void test_key_comp__value_comp()
{
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();
		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		std::cout << "mymap contains:\n";
		char highest = mymap.rbegin()->first;		 // key value of last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		std::cout << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		std::cout << "mymap contains:\n";
		ft::pair<char,int> highest = *mymap.rbegin();					// last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
}

void test_find()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('a');
	if (it != mymap.end())
		mymap.erase(it);
	print_map(mymap);

	it = mymap.find('c');
	if (it != mymap.end())
		mymap.erase(it);
	print_map(mymap);

	it = mymap.find('Z');
	if (it != mymap.end())
		mymap.erase(it);
	print_map(mymap);
}

void test_equal_range()
{
	ft::map<char, int> a;
	ft::map<char, int>::iterator it;
	a['a'] = 10;
	a['b'] = 20;
	a['c'] = 30;
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << "->" << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << "->" << ret.second->second << std::endl;
	ret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << "->" << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << "->" << ret.second->second << std::endl;
	ft::pair<ft::map<char,int>::const_iterator,ft::map<char,int>::const_iterator> cret;
	cret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << cret.first->first << "->" << cret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << cret.second->first << "->" << cret.second->second << std::endl;
	cret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << cret.first->first << "->" << cret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << cret.second->first << "->" << cret.second->second << std::endl;
}

void test_upper_lower_bound()
{
	ft::map<char,int> a;
	ft::map<char,int>::iterator itlow, itup;
	ft::map<char,int>::const_iterator citlow, citup;

	a['a'] = 20;
	a['b'] = 40;
	a['c'] = 60;
	a['d'] = 80;
	a['e'] = 100;

	itlow = a.lower_bound ('b');
	itup = a.upper_bound ('d');
	std::cout << itlow->first << " " << itlow->second << std::endl;
	std::cout << itup->first << " " << itup->second << std::endl;
	citlow = a.lower_bound ('b');
	citup = a.upper_bound ('d');
	std::cout << citlow->first << " " << citlow->second << std::endl;
	std::cout << citup->first << " " << citup->second << std::endl;
	print_map(a);
	a.erase(itlow,itup);
	print_map(a);
	itlow = a.lower_bound ('a');
	itup = a.upper_bound ('e');
	a.erase(itlow,itup);
	print_map(a);
}

int main()
{
	test_constructors();
	test_iterators();
	test_reverse_iterators();
	test_empty();
	test_size();
	test_element_access();
	test_insert1();
	test_insert2();
	test_insert3();
	test_erase1();
	test_erase2();
	test_erase3();
	test_swap_clear();
	test_key_comp__value_comp();
	test_find();
	test_equal_range();
	test_upper_lower_bound();
	//while (1);
}
