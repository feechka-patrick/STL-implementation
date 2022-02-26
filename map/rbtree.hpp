#pragma once

#include <iostream>

namespace ft{
	enum colors {red, black, bnil}; // bnil - black null node

	template<typename T, class Allocator = std::allocator<T> >
	class rbtree{
		public:
			typedef T			value_type;
			typedef Allocator	allocator_type;

		private:
			// typedef struct t_base_node{
			// 	typedef t_base_node	bnode;

			// bnode*	left;
			// bnode*	right;
			// bnode*	parent;
			// colors	color;// bool мб

			// 	t_base_node() : left(nullptr), right(nullptr), parent(nullptr), color(bnil) {}
			// 	t_base_node(bnode* _left, bnode* _right, bnode* _parent)
			// 		: left(_left), right(_right), parent(_parent) {}

			// }	base_node;

			typedef struct t_node {
				typedef t_node node;

				struct t_node*	left;
				struct t_node*	right;
				struct t_node*	parent;
				colors	color;// bool мб
				value_type	data;

				t_node() : left(nullptr), right(nullptr), parent(nullptr), color(bnil) {}
				t_node(node* _left, node* _right, node* _parent, value_type _data)
					: left(_left), right(_right), parent(_parent), data(_data) {}

				t_node(node* _left, node* _right, node* _parent, colors c, value_type _data)
					: left(_left), right(_right), parent(_parent), color(c), data(_data) {
					}
			}	node;

			node*		nil;
			node* 		store;
			allocator_type	alloc;
		
		public:

			rbtree() : nil(new node()), store(nil), alloc(allocator_type()){}
			rbtree(const rbtree& obj) : store(obj.store), alloc(obj.alloc) {} // leaks?
			
			~rbtree() {}

			void	insert(const value_type& _data){
				node* current = store;
				node* x = new node(nil, nil, current->parent, red, _data);
				x->left->parent = x;
				x->right->parent = x;

				if (current->color == bnil){
					 store = x;
					 return;
				}

				while(current->color != bnil){
					if (_data.first < current->data.first)
						current = current->left;
					else
						current = current->right;
				}
				if (_data.first < current->parent->data.first)
					current->parent->left = x;
				else 
					current->parent->right = x;

				//if (current->parent->color == black) ok
				//else not ok - balansirovka
			
			}

			void print_b(node* p, int level){
				//std::cout << p->color << std::endl;

				if(p->color != bnil)
				{
					print_b(p->left, level + 1);
					for(int i = 0; i < level; i++) std::cout<<"   ";
					std::cout << p->data.first << std::endl;
					print_b(p->right,level + 1);
				}
			}

			void print(){
				print_b(store, 0); 
			}
	};
}
