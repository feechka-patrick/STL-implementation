#pragma once

#include <iostream>
#include <iterator> // std::iterator_traits

namespace ft{
	template<class Iter>
	class reverse_iterator
	{
		public:
			typedef Iter							iterator_type;
			typedef typename Iter::value_type		value_type;
			typedef typename Iter::difference_type	difference_type;
			typedef typename Iter::pointer			pointer;
			typedef typename Iter::reference		reference;
			// Iter:: -> std::iterator_traits<Iter>
			
			// -- CONSTRUCTORS

			reverse_iterator();

			explicit reverse_iterator( iterator_type x );

			template< class U >
			reverse_iterator( const reverse_iterator<U>& other );

			~reverse_iterator() {}

			// -- MEMBER FUNCTIONS

			iterator_type base() const { return it; }

		private:
			iterator_type it;
	};	
}