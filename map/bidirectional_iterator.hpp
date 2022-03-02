#pragma once

#include "../utils.hpp" // std::conditional
#include <memory> // std::addressof
#include "rbtree.hpp"
#include "node.hpp"

namespace ft {

	template<typename Key, typename Value, bool IsConst = false>
	class BidirectionalIterator {
		public:
			typedef ft::pair<const Key, Value>					value_type;
			typedef t_node<value_type>*							node_type;
			typedef typename ft::conditional<IsConst,
					const value_type*, value_type*>::type	pointer;
			typedef typename ft::conditional<IsConst, 
					const value_type&, value_type&>::type	reference;
			// typedef value_type*	pointer;
			// typedef value_type&	reference;


			typedef BidirectionalIterator<Key, Value, IsConst>		iterator;
			typedef std::ptrdiff_t							difference_type;
			typedef std::bidirectional_iterator_tag			iterator_category;

			BidirectionalIterator() : node() {}
			BidirectionalIterator(node_type _node) : node(_node) {}
			BidirectionalIterator(const BidirectionalIterator<Key, Value>& other) :
				node(other.get_pointer()) {}
			
			iterator& operator= (const iterator& other)
			{
				node = other.node;
				return *this;
			}

			~BidirectionalIterator() {}

			reference operator*() const { return (node->data); }

			pointer operator->() { return std::addressof(node->data); }

			// ++it
			iterator& operator++() {
				node = ft::rbtree<Key, Value>::nextNode(node);
				return *this;
			}

			// it++
			iterator operator++(int) {
				iterator old = *this;
				node = ft::rbtree<Key, Value>::nextNode(node);
				return old;
			}

			// --it
			iterator& operator--() {
				node = ft::rbtree<Key, Value>::prevNode(node);
				return *this;
			}

			// it--
			iterator operator--(int) {
				iterator old = *this;
				node = ft::rbtree<Key, Value>::prevNode(node);
				return old;
			}

			node_type get_pointer() const { return node; }

            bool operator == ( const iterator &src ) const	{ return node == src.get_pointer(); }
			bool operator != ( const iterator &src ) const	{ return node != src.get_pointer(); }
			bool operator > ( const iterator &src ) const	{ return node->data > src.get_pointer()->data; }
			bool operator < ( const iterator &src ) const	{ return node->data < src.get_pointer()->data; }
			bool operator >= ( const iterator &src ) const	{ return node->data >= src.get_pointer()->data; }
			bool operator <= ( const iterator &src ) const	{ return node->data <= src.get_pointer()->data; }

		private:
			node_type node;
	};

}