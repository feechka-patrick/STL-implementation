#pragma once

#include <type_traits> // std::conditional (c++11)

namespace ft {

	template<typename T, bool IsConst = false>
	class RandomAccessIterator {
		public:
			typedef T										value_type;
			typedef std::conditional_t<IsConst,
					const value_type*, value_type*>			pointer;
			typedef std::conditional_t<IsConst, 
					const value_type&, value_type&>			reference;
			typedef RandomAccessIterator<T, IsConst>		iterator;
			typedef int										difference_type;

			RandomAccessIterator() : arr(0) {}
			RandomAccessIterator(pointer _arr) : arr(_arr) {}
			RandomAccessIterator(const iterator& other) :
				arr(other.arr) {}
			
			iterator& operator= (const iterator& other)
			{
				arr = other.arr;
				return *this;
			}

			~RandomAccessIterator() {}

			reference operator*() { return *arr; }

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
			iterator operator--() {
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
			iterator operator+(difference_type n) const {
				return iterator(arr - n);
			}
			
			reference operator[](difference_type ind) {
				return arr[ind];
			}


			pointer get_pointer() { return arr; }

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
	template<typename T, bool IsConst> 
	RandomAccessIterator<T, IsConst> operator==(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() - rhs.get_pointer();
	}

	template<typename T, bool IsConst> 
	bool operator==(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() == rhs.get_pointer();
	}


	template<typename T, bool IsConst>
	bool operator!=(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() != rhs.get_pointer();
	}

	template<typename T, bool IsConst>
	bool operator<(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() < rhs.get_pointer();
	}

	template<typename T, bool IsConst>
	bool operator>(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() > rhs.get_pointer();
	}

	template<typename T, bool IsConst>
	bool operator<=(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() <= rhs.get_pointer();
	}

	template<typename T, bool IsConst>
	bool operator>=(const RandomAccessIterator<T, IsConst>& lhs, const RandomAccessIterator<T, IsConst>& rhs)
	{
		return lhs.get_pointer() >= rhs.get_pointer();
	}
}