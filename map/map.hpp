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
			// typedef typename std::map<Key, T, Compare>::iterator		iterator;
			// typedef 										const_iterator;
			//typedef ft::reverse_iterator<iterator> 		reverse_iterator;
			//typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


			//	-- MEMBER CLASSES
			class value_compare {
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator()( const value_type& lhs, const value_type& rhs ) const{
						return comp(lhs.first, rhs.first);
					}
				
				protected:
					key_compare	comp;

					value_compare(const key_compare c) : comp(c) {}
			}

			//	-- CONSTRUCTORS / destructor

			map() : alloc(allocator_type()), kcomp(value_compare(key_compare())),
				size(0) {}

			explicit map( const Compare& comp,
						const Allocator& _alloc = Allocator() ) : alloc(_alloc),
				kcomp(comp), size(0) {}

			template< class InputIt >
			map( InputIt first, InputIt last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() );

	 		map( const map& other );

			~map();
			
			map& operator=( const map& other );

			allocator_type get_allocator() const { return alloc; }

		private:
			allocator_type 	alloc;
			value_compare	kcomp;
			size_type		size;
			node*			store;

			typedef struct t_node{
				t_node*		left;
				t_node*		right;
				t_node*		parent;
				bool		red;
				value_type	value;

			} node;

			node			nil(nullptr, nullptr, nullptr, false, 0);
	};
}