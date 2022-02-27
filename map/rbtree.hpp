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

			// 	t_base_node() : left(nullptr), right(nullptr), parent(nullptr), color(black) {}
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

				t_node() : left(nullptr), right(nullptr), parent(nullptr), color(black) {}
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
				print();
				rightRotate(&store);
			}

			void	leftRotate(node** x){
				node* rightTree = (*x)->right;
				(*x)->right = rightTree->left;
				rightTree->left->parent = (*x);
				rightTree->left = (*x);
				node* parentx = (*x)->parent;
				(*x)->parent = rightTree;
				rightTree->parent = parentx;
				(*x) = rightTree;
			}

			void	rightRotate(node** x){
				node* leftTree = (*x)->left;
				(*x)->left = leftTree->right;
				leftTree->right->parent = (*x);
				leftTree->right = (*x);
				node* parentx = (*x)->parent;
				(*x)->parent = leftTree;
				leftTree->parent = parentx;
				(*x) = leftTree;
			}

			node* _uncle(node* x) {
				node* grandpa = x->parent->parent;
				if (grandpa->left == x->parent)
					return grandpa->right;
				else return grandpa->left;
			}


			void 	insertFix(node* x){
				if (x->parent && x->parent->color == black) return;
				if (x == store) return;
				if (x->parent == store){
					store->color = black;
					return;
				}

				node* uncle = _uncle(x);
				//---- uncle red

				if (uncle->color == red){
					x->parent->color = black;
					uncle->color = black;
					x->parent->parent->color = red;
					insertFix(x->parent->parent);
				}

				if (x->parent && x->parent->color == black) return;/// exit??

				//---- uncle black

				if (uncle->color == black){
					if (x->parent->right == x)
						leftRotate(&x);
					rightRotate(&uncle->parent);
					uncle->parent->parent->color = black;
					uncle->parent->parent->left->color = red;
					uncle->parent->parent->right->color = red;
					return;
				}
			}

			void	insert(const value_type& _data){
				node* current = store;
				node* x = new node(nil, nil, nullptr, red, _data);

				if (current == nil){
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

				if (parent->color == black) return;
				
				return insertFix(x);
			}

			node* get_root() { return store; }

			void print_b(node* p, int level){
				if(p != nil)
				{
					print_b(p->right, level + 1);
					for(int i = 0; i < level; i++) std::cout<<"       ";
					std::cout << p->data.first;
					if (p->parent) std::cout << "p:" << p->parent->data.first;
					std::cout << "c:" << p->color << std::endl;
					print_b(p->left,level + 1);
				}
			}

			void print(){
				std::cout << "print" << std::endl;
				print_b(store, 0); 
			}
	};
}
