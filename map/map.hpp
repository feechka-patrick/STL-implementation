#pragma once

#include <iostream>

namespace ft{
	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> > > 
	class map
	{
		public:
			//	-- MEMBER TYPES
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			//typedef 										iterator;
			//typedef 										const_iterator;
			//typedef std::reverse_iterator<iterator> 		reverse_iterator;
			//typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
	};
}