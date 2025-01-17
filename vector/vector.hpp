#pragma once

#include <iostream>
#include "../utils.hpp" // ft::swap 
#include "random_acces_iterator.hpp" // iterator
#include "../reverse_iterator.hpp" // iterator
#include <iterator> // std::reverse_iterator, std::distance
#include <vector> // iterator from vector
#include <algorithm> // ft::lexicographical_compare, std::copy_backward
#include <limits> // std::numeric_limits

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			//	-- MEMBER TYPES

			typedef T 											value_type;
			typedef Allocator 									allocator_type;
			typedef std::size_t 								size_type;
			typedef std::ptrdiff_t 								difference_type;
			typedef value_type& 								reference;
			typedef const value_type& 							const_reference;
			typedef value_type*									pointer;
			typedef const value_type* 							const_pointer;
	
			typedef typename ft::RandomAccessIterator<value_type> 		iterator;
			typedef typename ft::RandomAccessIterator<value_type,true>	const_iterator;

			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			//	-- CONSTRUCTORS

			//vector();

			explicit vector(const allocator_type &_alloc = allocator_type())
				: alloc(_alloc), array(0), vsize(0), csize(0) {}

			explicit vector(size_type count,
							const value_type &value = value_type(),
							const allocator_type &_alloc = allocator_type())
							: alloc(_alloc), vsize(0), csize(0) 
			{
				try{
					array = alloc.allocate(count);
				}
				catch(const std::exception& e){
					throw vector::MemoryException();
				}
				csize = count;
				vsize = count;
				for (size_type i = 0; i < vsize; ++i) {
					alloc.construct(array + i, value);
				}
			}

			template <class InputIt>
			vector(InputIt first, InputIt last,
				const allocator_type &_alloc = allocator_type(),
				typename ft::enable_if<!std::numeric_limits<InputIt>::is_integer>::type* = 0) : alloc(_alloc)
			{
				vsize = std::distance(first, last);
				csize = vsize;
				try{
					array = alloc.allocate(csize);
				}
				catch(const std::exception& e){
					throw vector::MemoryException();
				}
				for (size_type i = 0; i < vsize; ++i) {
					alloc.construct(array + i, *first);
					first++;
				}
			}

			vector( const vector& other ) :  alloc(other.alloc) , vsize(0), csize(0)
			{
				try{
					array = alloc.allocate(other.vsize);
				}
				catch(const std::exception& e){
					throw vector::MemoryException();
				}
				csize = other.vsize;
				vsize = other.vsize;
				for (size_type i = 0; i < vsize; ++i) {
					alloc.construct(array + i, other[i]);
				}
			}


			//	-- DESTRUCTOR

			~vector()
			{
				for (size_type i = 0; i < vsize; i++){
					alloc.destroy(array + i);
				}
				alloc.deallocate(array, csize);
				array = 0;
				vsize = 0;
				csize = 0;
			}

			// -- OPERATOR=

			vector& operator= (const vector& other)
			{
				clear();
				if (other.csize > csize){
					alloc.deallocate(array, csize);
					array = alloc.allocate(other.csize);
					csize = other.csize;
				}
				vsize = other.vsize;
				for (size_type i = 0; i < vsize ; ++i) {
					alloc.construct(array + i, other[i]);
				}
				return (*this);
			}


			// -- MEMBER FUNCTIONS

			void assign( size_type count, const T& _value )
			{
				const T value = _value;
				clear();
				insert(this->begin(), count, value);
			}

			template< class InputIt >
			void assign( InputIt first, InputIt last,
				typename enable_if< !std::numeric_limits<InputIt>::is_specialized >::type* = 0)
			{
				if (first > last || std::distance(first, last) + vsize > this->max_size())
					{
						this->~vector();
						throw vector::LengthException();
					}

				vector<value_type> vv(first, last);
				clear();				
				insert(this->begin(), vv.begin(), vv.end());
			}

			allocator_type get_allocator() const { return alloc; }

			reference at( size_type pos )
			{
				if (!(pos < this->size()))
					throw vector::RangeException();
				return array[pos];
			}

			const_reference at( size_type pos ) const
			{
				if (!(pos < this->size()))
					throw vector::RangeException();
				return array[pos];	
			}
			
			reference operator[]( size_type pos ) { return array[pos]; }

			const_reference operator[]( size_type pos ) const { return array[pos]; }

			reference front() { return *array; }

			const_reference front() const { return *array; }

			reference back() { return *(array + vsize - 1); }

			const_reference back() const { return *(array + vsize - 1); }

			T* data() { return array; }

			const T* data() const { return array; }

			// -- ITERATORS

			iterator begin() const { return iterator(array); }

			const_iterator cbegin() const {return const_iterator(array); }

			iterator end() const { return iterator(array + vsize); }

			const_iterator cend() const { return const_iterator(array + vsize); }

			// ------------------------------------------
			// ------------------------------------------

			reverse_iterator rbegin() { 
				if (vsize == 0)
					return reverse_iterator(iterator(array + vsize));
				return reverse_iterator(iterator(array + vsize - 1)); 
				//return reverse_iterator(iterator(array + vsize - 1));
			}

			const_reverse_iterator crbegin() const { 
				return const_reverse_iterator(this->end() - (vsize == 0 ? 0 : 1)); 
			}

			reverse_iterator rend() { 
				return reverse_iterator(this->begin() - (vsize == 0 ? 0 : 1)); 
			}

			const_reverse_iterator crend() const { 
				return const_reverse_iterator(this->begin() - (vsize == 0 ? 0 : 1)); 
			}

			// ------------------------------------------
			// ------------------------------------------

			// -- CAPACITY

			bool empty() const { return vsize == 0 ? true : false; }

			size_type size() const { return vsize; }

			size_type max_size() const { return alloc.max_size(); }

			void reserve( size_type new_cap )
			{
				if (new_cap > this->max_size())
					throw vector::LengthException();
				if (new_cap <= csize) return;

				//new array
				pointer newarray = alloc.allocate(new_cap);

				csize = new_cap;
				std::copy(this->begin(), this->end(), iterator(newarray));
				
				// //free
				// for (size_type i = 0; i < vsize; i++){
				// 	alloc.destroy(array + i);
				// }
				if (csize != 0) alloc.deallocate(array, csize);

				array = newarray;
			}

			size_type capacity() const { return csize; }

			// -- MODIFIERS

			void clear()
			{
				for (size_type i = 0; i < vsize; i++){
					alloc.destroy(array + i);
				}
				vsize = 0;
			}

			// ------------------------------------------
			// ------------------------------------------

			iterator insert( iterator pos, const T& _value ) { //1
				size_type i = pos - begin();
				const T value = _value;

				if (pos == this->end()) {
					this->push_back(value);
					return this->end();
				}
				if (vsize == csize) reserve(2 * csize);
				
				pos = iterator(array + i);
				std::copy_backward(pos, this->end(), this->end() + 1);
				vsize++;

				alloc.construct(array + i, value);
				return pos;
			}

			void insert( iterator pos, size_type count, const T& _value ) { //3
				size_type dist = pos - this->begin();
				const T value = _value;

				if (2 * csize < count + vsize) reserve(count + vsize);
				else if (csize < count + vsize) reserve(2 * csize);

				pos = iterator(array + dist);
				std::copy_backward(pos, this->end(), this->end() + count);
				vsize += count;

				for (size_type i = dist; count > 0; --count, ++i)
					alloc.construct(array + i, value);
			}

			// void print(vector<value_type> vv) 
			// {
			// 	std::cout << "print current state\n";
			// 	for (size_t i = 0; i < vv.size(); i++) {
			// 		std::cout << vv[i].some_ << " ";
			// 	}
			// 	std::cout << "\nsize-> " << vv.size() << "\n";
			// 	std::cout << "cap -> " << vv.capacity() << "\n\n";
			// }

			template< class InputIt>
			void insert( iterator pos, InputIt first, InputIt last, 
				typename ft::enable_if<!std::numeric_limits<InputIt>::is_integer>::type* = 0) {//4
				if (first > last || std::distance(first, last) + vsize > this->max_size())
					throw vector::LengthException();

				size_type dist = pos - this->begin();
				ft::vector<T> value(first, last);	

				const size_type count = last - first;
				if (2 * csize < count + vsize) reserve(count + vsize);
				else if (csize < count + vsize) reserve(2 * csize);

				pos = iterator(array + dist);

				if (this->end() - pos > 0)
					std::copy_backward(pos, this->end(), this->end() + count);
				vsize += count;
			

				std::copy(value.begin(), value.end(), pos);
				
			}

			iterator erase( iterator pos ) {
				if (vsize == 0) return this->begin();
				size_type dist = pos - this->begin();
	
				alloc.destroy(array + dist);
				
				pos = iterator(array + dist);
				//std::copy((pos + 1), this->end(), pos);
				memmove(
					array + dist,
					array + dist + 1,
					sizeof(value_type) * (vsize - dist - 1)
				);
				vsize--;
				return pos;
			}

			iterator erase( iterator first, iterator last ){
				iterator tmp;
				difference_type dist = first - begin();
				difference_type difr = std::distance(first, last);

				if (dist < 0 || difr < 0) return end();

				for (difference_type i = dist; i < difr + dist; ++i)
					alloc.destroy(array + i);

				memmove(
					array + dist,
					array + dist + difr,
					sizeof(value_type) * (vsize - dist - difr)
				);
				vsize -= difr;
				return iterator(array + dist);
			}

			// ------------------------------------------
			// ------------------------------------------

			void push_back( const T& _value )
			{
				const T value = _value;
				if (csize == 0) reserve(1);
				if (csize == vsize) reserve(2 * csize);
				alloc.construct(array + vsize, value);
				vsize++;
			}

			void pop_back()
			{
				if (vsize == 0) return;
				vsize--;
				alloc.destroy(array + vsize);
			}

			// просмотреть еще раз обязательно пишу поздно
			void resize( size_type count, T value = T() )
			{
				if (vsize > count)
				{
					for (size_type i = count; i < vsize; ++i)
						alloc.destroy(array + i);
					vsize = count;
					return;
				}
				if (csize >= count)
				{
					for (size_type i = vsize; i < count; ++i)
						alloc.construct(array + i, value);
					vsize = count;
					return;
				}

				if (csize < count) {
					if (2 * csize < count) reserve(count);
					else reserve(2 * csize);

					for (size_type i = vsize; i < count; ++i)
						alloc.construct(array + i, value);
					vsize = count;
				}
			}

			void swap( vector& other )
			{
				ft::swap(array, other.array);
				ft::swap(alloc, other.alloc);
				ft::swap(vsize, other.vsize);
				ft::swap(csize, other.csize);
			}

			// -- EXCEPTIONS

			class MemoryException : public std::exception {
				const char* what() const throw() {
					return "ft::bad_alloc";
				}
			};

			class LengthException : public std::exception {
				const char* what() const throw() {
					return "ft::length_error";
				}
			};
			
			class RangeException : public std::exception {
				const char* what() const throw() {
					return "ft::out_of_range";
				}
			};

		private:
			allocator_type		alloc; // allocator
			pointer				array; // pointer to first element
			size_type			vsize; // vector size
			size_type			csize; // size alocated memory		
	};

	template< class T, class Alloc>
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() 
			&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs.size() == rhs.size() 
			&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ) { lhs.swap(rhs); }
}

namespace std{
	template< class T, class Alloc >
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs){
		lhs.swap(rhs);
	}
}
