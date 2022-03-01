#pragma once

#include "../utils.hpp" // std::conditional
#include <memory> // std::addressof
#include "rbtree.hpp"

namespace ft {

	template<typename Node, bool IsConst = false>
	class BidirectionalIterator {
		public:
			typedef Node										value_type;
			typedef typename ft::conditional<IsConst,
					const value_type*, value_type*>::type	pointer;
			typedef typename ft::conditional<IsConst, 
					const value_type&, value_type&>::type	reference;
			typedef BidirectionalIterator<T, IsConst>		iterator;
			typedef std::ptrdiff_t							difference_type;
			typedef std::bidirectional_iterator_tag			iterator_category;

			BidirectionalIterator() : node() {}
			BidirectionalIterator(pointer _node) : node(_node) {}
			BidirectionalIterator(const BidirectionalIterator<value_type>& other) :
				node(other.get_pointer()) {}
			
			iterator& operator= (const iterator& other)
			{
				node = other.node;
				return *this;
			}

			~BidirectionalIterator() {}

			reference operator*() const { return node->data; }

			pointer operator->() { return std::addressof(node->data); }

			// ++it
			iterator& operator++() {
				node = ft::rbtree.nextNode(node);
				return *this;
			}

			// it++
			iterator operator++(int) {
				iterator old = *this;
				node = ft::rbtree.nextNode(node);
				return old;
			}

			// --it
			iterator& operator--() {
				node = ft::rbtree.prevNode(node);
				return *this;
			}

			// it--
			iterator operator--(int) {
				iterator old = *this;
				node = ft::rbtree.prevNode(node);
				return old;
			}

			pointer get_pointer() const { return node; }

            bool operator == ( const iterator &src ) const	{ return node == src.node; }
			bool operator != ( const iterator &src ) const	{ return node != src.node; }
			bool operator > ( const iterator &src ) const	{ return node->data > src.node->data; }
			bool operator < ( const iterator &src ) const	{ return node->data < src.node->data; }
			bool operator >= ( const iterator &src ) const	{ return node->data >= src.node->data; }
			bool operator <= ( const iterator &src ) const	{ return node->data <= src.node->data; }

		private:
			pointer node;
	};

}