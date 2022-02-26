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
			
			void check(){
				leftRotate(&store);
			}

			void	leftRotate(node** x){
				node* rightTree = (*x)->right;
				(*x)->right = rightTree->left;
				rightTree->left->parent = (*x);
				rightTree->left = (*x);
				(*x)->parent = rightTree;
				rightTree->parent = nullptr;
				(*x) = rightTree;
			}

			void	rightRotate(node** x){
				node* leftTree = (*x)->left;
				(*x)->left = leftTree->right;
				leftTree->right->parent = (*x);
				leftTree->right = (*x);
				(*x)->parent = leftTree;
				leftTree->parent = nullptr;
				(*x) = leftTree;
			}

			void	insert(const value_type& _data){
				node* current = store;
				node* x = new node(nil, nil, nullptr, red, _data);

				if (current->color == bnil){
					 store = x;
					 return;
				}
				
				node* parent = nullptr;
				while(current != nil){
					parent = current;
					if (_data.first < current->data.first)
						current = current->left;
					else
						current = current->right;
				}

				x->parent = parent;		
				if (_data.first < parent->data.first)
					parent->left = x;
				else 
					parent->right = x;

				//if (parent->color == black) ok
				//else not ok - balansirovka
			
			}

			node* get_root() { return store; }
			void print_b(node* p, int level){
				if(p->color != bnil)
				{
					print_b(p->right, level + 1);
					for(int i = 0; i < level; i++) std::cout<<"       ";
					std::cout << p->data.first;
					if (p->parent)  std::cout << "p:" << p->parent->data.first << std::endl;
					print_b(p->left,level + 1);
				}
			}

			void print(){
				std::cout << "print" << std::endl;
				print_b(store, 0); 
			}
	};
}
