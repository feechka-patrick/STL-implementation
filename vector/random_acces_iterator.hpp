#pragma once

#include "../utils.hpp" // std::conditional

namespace ft {

	template<typename T, bool IsConst = false>
	class RandomAccessIterator {
		public:
			typedef T										value_type;
			typedef typename ft::conditional<IsConst,
					const value_type*, value_type*>::type	pointer;
			typedef typename ft::conditional<IsConst, 
					const value_type&, value_type&>::type	reference;
			typedef RandomAccessIterator<T, IsConst>		iterator;
			typedef std::ptrdiff_t							difference_type;
			typedef std::random_access_iterator_tag			iterator_category;

			RandomAccessIterator() : arr(0) {}
			RandomAccessIterator(pointer _arr) : arr(_arr) {}
			RandomAccessIterator(const RandomAccessIterator<value_type>& other) :
				arr(other.get_pointer()) {}
			
			iterator& operator= (const iterator& other)
			{
				arr = other.arr;
				return *this;
			}

			~RandomAccessIterator() {}

			reference operator*() const { return *arr; }

			pointer operator->() { return arr; }

			// ++it
			iterator& operator++() {
				++arr;
				return *this;
			}

			// it++
			iterator operator++(int) {
				iterator old = *this;
				arr++;
				return old;
			}

			// --it
			iterator& operator--() {
				--arr;
				return *this;
			}

			// it--
			iterator operator--(int) {
				iterator old = *this;
				arr--;
				return old;
			}

			// it += int
			iterator& operator+=(difference_type n) {
				arr += n;
				return *this;
			}

			// it -= int
			iterator& operator-=(difference_type n) {
				arr -= n;
				return *this;
			}

			// it + n
			iterator operator+(difference_type n) const {
				return iterator(arr + n);
			}

			//  it - n
			iterator operator-(difference_type n) const {
				return iterator(arr - n);
			}
			
			reference operator[](difference_type ind) {
				return arr[ind];
			}


			pointer get_pointer() const { return arr; }

		private:
			pointer arr;
	};

	// n + it
	template<typename T, bool IsConst> 
	RandomAccessIterator<T, IsConst> operator+(const typename RandomAccessIterator<T, IsConst>::difference_type n,
			 const RandomAccessIterator<T, IsConst>& rhs)
	{
		return rhs + n;
	}

	// it - it
	template<typename T, bool IsConstL, bool IsConstR> 
	std::size_t operator-(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		if (lhs > rhs)
			return lhs.get_pointer() - rhs.get_pointer();
		else return rhs.get_pointer() - lhs.get_pointer();
	}

	template<typename T, bool IsConstL, bool IsConstR> 
	bool operator==(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() == rhs.get_pointer();
	}


	template<typename T, bool IsConstL, bool IsConstR>
	bool operator!=(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() != rhs.get_pointer();
	}

	template<typename T, bool IsConstL, bool IsConstR>
	bool operator<(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() < rhs.get_pointer();
	}

	template<typename T, bool IsConstL, bool IsConstR>
	bool operator>(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() > rhs.get_pointer();
	}

	template<typename T, bool IsConstL, bool IsConstR>
	bool operator<=(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() <= rhs.get_pointer();
	}

	template<typename T, bool IsConstL, bool IsConstR>
	bool operator>=(const RandomAccessIterator<T, IsConstL>& lhs, const RandomAccessIterator<T, IsConstR>& rhs)
	{
		return lhs.get_pointer() >= rhs.get_pointer();
	}
}