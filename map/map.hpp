#pragma once

#include <iostream>
#include <functional> // std::binary_function
#include "rbtree.hpp"
#include "pair.hpp"
#include "bidirectional_iterator.hpp"
#include "node.hpp"
#include "../reverse_iterator.hpp"

namespace ft{
	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			//	-- MEMBER TYPES
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef ft::t_node<value_type>							node;
			typedef typename ft::BidirectionalIterator<node>		iterator;
			typedef typename ft::BidirectionalIterator<node, true>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;


			//	-- MEMBER CLASSES
			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
				
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
			};

			typedef rbtree<Key, T, value_compare, Allocator>	rbtree_type;
			
			// -- CONSTRUCTORS / destructor ----

			map() : alloc(allocator_type()), kcomp(key_compare()),
				size(0), rbt(kcomp) {}

			explicit map( const Compare& comp,
						const Allocator& _alloc = Allocator() ) : alloc(_alloc),
				kcomp(comp), size(0), rbt(kcomp) {}

			template< class InputIt >
			map( InputIt first, InputIt last,
				const Compare& comp = Compare(),
				const Allocator& _alloc = Allocator() ) : alloc(_alloc), kcomp(comp),
							size(0), rbt(kcomp) {

					for ( ; first != last; ++first )
					{
						insert( ft::make_pair( first->first, first->second ) );
						size++;
					}
			}

	 		map( const map& other ) {}

			~map(){}
			
			map& operator=( const map& other ){}

			allocator_type get_allocator() const { return alloc; }

			// -- AT, [] ---------------------

			mapped_type& at( const Key& key ){
				iterator it = this->find(key);
				if (x == this->end())
					throw std::out_of_range();
				return it->second;
			}

			const mapped_type& at( const Key& key ) const{
				iterator it = this->find(key);
				if (x == this->end())
					throw std::out_of_range();
				return it->second;
			}

			mapped_type& operator[]( const Key& key ){
				return insert(ft::make_pair(key, mapped_type())).first->second;
			}

			// -- ITERATORS ------------------

			iterator begin() { return iterator(rbt.begin()); }
			const_iterator begin() const { return const_iterator(rbt.begin()); }

			iterator end() { return iterator(rbt.end()); }
			const_iterator end() const { return const_iterator(rbt.end()); }

			reverse_iterator rbegin() { return iterator(rbt.last()); }
			const_reverse_iterator rbegin() const { return const_iterator(rbt.last()); }

			reverse_iterator rend() { return iterator(rbt.prebegin()); }
			const_reverse_iterator rend() const { return const_iterator(rbt.prebegin()); }

			// -- MODIFIERS ------------------

			void clear(){
				size = 0;
				rbt.deleteTree();
			}

			// -- INSERT ---------------------

			ft::pair<iterator, bool> insert( const value_type& value ){
				std::pair<node*, bool> p = rbt.insert(value);
				return ft::make_pair(iterator(p.first), p.second);
			}

			iterator insert( iterator hint, const value_type& value );

			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				for ( ; first != last; ++first )
				{
					insert( ft::make_pair( first->first, first->second ) );
					size++;
				}
			}

			// ------------------------------

			void erase( iterator pos ){
				if (rbt.deleteNode(*pos)) size--;
			}

			void erase( iterator first, iterator last ){
				iterator tmp;
				for ( ; first != last; ++first )
				{
					tmp = first
					erase(tmp);
				}
			}

			size_type erase( const Key& key ){
				iterator x = this->find(key);
				if (x == this->end()) return 0;
				erase(x);
				return 1;
			}

			void swap( map& other ) { std::swap(rbt, other.rbt); }

			// -- CAPACITY -------------------

			bool empty() const { return (size == 0); }

			size_type size() const { return size; }

			size_type max_size() const { return alloc.max_size(); }


			// -- FIND -----------------------

			iterator	find( const key_type &key ) {
				node* tmp = rbt.root();
				node* end = rbt.end();

				while (tmp != end) {
					if (key == tmp->data->first)
						return iterator(tmp);
					else
						tmp = kcomp(key, tmp->value->first) ? tmp->left : tmp->right;
				}
				return this->end();
			}

			const_iterator find( const Key& key ) const {
				node* tmp = rbt.root();
				node* end = rbt.end();

				while (tmp != end) {
					if (key == tmp->data->first)
						return iterator(tmp);
					else
						tmp = kcomp(key, tmp->value->first) ? tmp->left : tmp->right;
				}
				return this->end();
			}
			
			// ------------------------------

			size_type	count( const key_type &key ) const {
				return (find(key) == end() ) ? 0 : 1;
			}

			std::pair<iterator,iterator> equal_range( const Key& key ){
				return ft::make_pair( lower_bound( key ), upper_bound( key ) );
			}

			iterator lower_bound( const Key& key ){
				iterator it = begin();
				while (it != end() && !kcomp(it->first, key))
					it++;
				return it;
			}
	
			const_iterator lower_bound( const Key& key ) const{
				iterator it = begin();
				while (it != end() && !kcomp(it->first, key))
					it++;
				return it;
			}

			iterator upper_bound( const Key& key ){
				iterator it = begin();
				while (it != end() && !kcomp(key, it->first))
					it++;
				return it;
			}

			const_iterator upper_bound( const Key& key ) const{
				iterator it = begin();
				while (it != end() && !kcomp(key, it->first))
					it++;
				return it;
			}

			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				return ft::make_pair( lower_bound( key ), upper_bound( key ) );
			}

			key_compare	key_comp( void ) const	{ return kcomp; }

			ft::map<key_type, mapped_type, key_compare, allocator_type>::value_compare	value_comp( void ) const { 
				return value_compare( key_comp() ); 
			}

			friend bool	operator == ( const map &lhs, const map &rhs ) {
				return lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() );
			}

			friend bool	operator != ( const map &lhs, const map &rhs ) {
				return !( lhs == rhs );
			}

			friend bool	operator < ( const map &lhs, const map &rhs ) {
				return ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() );
			}

			friend bool	operator > ( const map &lhs, const map &rhs ) {
				return rhs < lhs;
			}

			friend bool	operator <= ( const map &lhs, const map &rhs ) {
				return !( rhs < lhs );
			}

			friend bool	operator >= ( const map &lhs, const map &rhs ) {
				return !( lhs < rhs );
			}

		private:
			allocator_type 	alloc;
			key_compare		kcomp;
			size_type		size;
			rbtree_type		rbt;

		public:
		// --- temporarily utils

		void print(int i) { rbt.print(i) };

		// -----------------------------------

	};
}