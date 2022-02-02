#pragma once

#include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		private:
			allocator_type		alloc; // allocator
			pointer				array; // pointer to first element
			size_type			vsize; // vector size
			size_type			msize; // size alocated memory

		public:
			//	-- member types

			typedef T 										value_type;
			typedef Allocator 								allocator_type;
			typedef std::size_t 							size_type;
			typedef std::ptrdiff_t 							difference_type;
			typedef value_type& 							reference;
			typedef const value_type& 						const_reference;
			typedef Allocator::pointer 						pointer;
			typedef Allocator::const_pointer 				const_pointer;
			//typedef 										iterator;
			//typedef 										const_iterator;
			typedef std::reverse_iterator<iterator> 		reverse_iterator;
			typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;


			//	-- constructors

			//vector();

			explicit vector(const allocator_type &alloc = allocator_type())
				: alloc(alloc), array(0), vsize(0), msize(0) {}

			explicit vector(size_type count,
							const value_type &value = value_type(),
							const allocator_type &alloc = allocator_type()) {
				try
				{
					this->array = alloc.allocate(n);
				}
				catch(const std::exception& e)
				{
					this->~vector();
					throw vector::MemoryException();
				}
				msize = count;
				array = value;
				// for (size_type i = 0; i < n; i++) {
				// 	alloc.construct(arr + i, value);
				// }
			}

			template <class InputIt>
			vector(InputIt first, InputIt last,
				const allocator_type &alloc = allocator_type());

			vector( const vector& other );


			//	-- destructor

			virtual ~vector()
			{
				for (size_type i = 0; i < vsize; i++){
					alloc.destroy(array + i);
				}
				alloc.deallocate(array, msize);
				array = 0;
				vsize = 0;
				msize = 0;
			}

			// -- operator=

			vector& operator= (const vector& other)
			{
				this->~vector();

			}

			// -- exceptions

			class MemoryException : public std::exception {
				const char* what() const throw() {
					return "Error memory allocate!";
				}
			}
	};
}