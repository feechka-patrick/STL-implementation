#pragma once

#include "../utils.hpp" // std::conditional
#include <memory> // std::addressof
#include "rbtree.hpp"
#include "node.hpp"

namespace ft {

	template<typename Value, bool IsConst = false>
	class BidirectionalIterator {
		public:
			typedef Value									value_type;
			typedef t_node<value_type>*						node_type;
			typedef typename ft::conditional<IsConst,
					const value_type*, value_type*>::type	pointer;
			typedef typename ft::conditional<IsConst, 
					const value_type&, value_type&>::type	reference;
			// typedef value_type*	pointer;
			// typedef value_type&	reference;


			typedef BidirectionalIterator<Value, IsConst>		iterator;
			typedef std::ptrdiff_t							difference_type;
			typedef std::bidirectional_iterator_tag			iterator_category;

			BidirectionalIterator() : node() {}
			BidirectionalIterator(node_type _node) : node(_node) {}
			BidirectionalIterator(const BidirectionalIterator<Value>& other) :
				node(other.get_pointer()) {}
			
			iterator& operator= (const iterator& other)
			{
				node = other.node;
				return *this;
			}

			~BidirectionalIterator() {}

			reference operator*() const { return (node->data); }

			pointer operator->() const { return &(node->data); }

			// ++it
			iterator& operator++() {
				node = nextNode(node);
				return *this;
			}

			// it++
			iterator operator++(int) {
				iterator old = *this;
				node = nextNode(node);
				return old;
			}

			// --it
			iterator& operator--() {
				node = prevNode(node);
				return *this;
			}

			// it--
			iterator operator--(int) {
				iterator old = *this;
				node = prevNode(node);
				return old;
			}

			node_type get_pointer() const { return node; }
			pointer	get_value() const { return node->data; }

            bool operator == ( const iterator &src ) const	{ return node == src.get_pointer(); }
			bool operator != ( const iterator &src ) const	{ return node != src.get_pointer(); }
			bool operator > ( const iterator &src ) const	{ return node->data > src.get_pointer()->data; }
			bool operator < ( const iterator &src ) const	{ return node->data < src.get_pointer()->data; }
			bool operator >= ( const iterator &src ) const	{ return node->data >= src.get_pointer()->data; }
			bool operator <= ( const iterator &src ) const	{ return node->data <= src.get_pointer()->data; }

		private:
			node_type node;

			node_type nextNode(node_type x){
				if (x->isNil) {
					if (x->parent) return x->parent;
					return x->left;
				}
				if (x->right->isNil == false){
					node_type parent = x;
					x = x->right;
					while (x->isNil == false)
					{
						parent = x;
						x = x->left;
					}
					return parent;
				}
				node_type tmp = x;
				node_type y = x->parent;
				while (y->isNil == false && x == y->right){
					x = y;
					y = y->parent;
				}
				if (y->isNil) y->parent = tmp;
				return y;
			}

			node_type prevNode(node_type x){
				if (x->isNil) {
					if (x->parent) return x->parent;
					return x->right;
				}
				if (x->left->isNil == false){
					node_type parent = x;
					x = x->left;
					while (x->isNil == false)
					{
						parent = x;
						x = x->right;
					}
					return parent;
				}
				node_type tmp = x;
				node_type y = x->parent;
				while (y->isNil == false && x == y->left){
					x = y;
					y = y->parent;
				}
				if (y->isNil) y->parent = tmp;
				return y;
			}
	};

}