#pragma once

#include <iostream>
#include "../utils.hpp"
#include <utility> //make_pair

namespace ft{
	enum colors {red, black}; 

	template<typename Key, typename Data, class Allocator = std::allocator<std::pair<const Key, Data> > >
	class rbtree{
		public:
			typedef std::pair<const Key, Data>	value_type;
			typedef Allocator					allocator_type;

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
				t_node(const node* obj)
					: left(obj->left), right(obj->right), parent(obj->parent), color(obj->color), data(obj->data) {
					}

				void copy(const node* obj){
					left = obj->left;
					right = obj->right;
					parent = obj->parent;
					color = obj->color;
				}
			}	node;

			node*		nil;
			node* 		store;
			allocator_type	alloc;
		
		public:

			rbtree() : nil(new node()), store(nil), alloc(allocator_type()){}
			rbtree(const rbtree& obj) : store(obj.store), alloc(obj.alloc) {} // leaks?
			

			
			void deleteTree(node** _x){ //posOrder
				node* x = *_x;
				if (x == nil) return;
				deleteTree(&x->left);
				deleteTree(&x->right);
				delete x;
			}
			~rbtree() {
				deleteTree(&store);
				delete nil;
			}
			
			void check(){
				deleteNode(std::pair<const int, int>(5, 9));
			}

			void	leftRotate(node** x){
				node* rightTree = (*x)->right;
				(*x)->right = rightTree->left;
				
				if (rightTree->left != nil)
					rightTree->left->parent = (*x);
				rightTree->parent = (*x)->parent;
				if ((*x)->parent == nil)
					store = rightTree;
				else if ((*x) == (*x)->parent->left)
					(*x)->parent->left = rightTree;
				else (*x)->parent->right = rightTree;
				rightTree->left = (*x);
				(*x)->parent = rightTree;
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

			node* nextNode(node* x){
				node* parent = x;
				x = x->right;
				while (x != nil)
				{
					parent = x;
					x = x->left;
				}
				return parent;
			}

			node* prevNode(node* x){
				node* parent = x;
				x = x->left;
				while (x != nil)
				{
					parent = x;
					x = x->right;
				}
				return parent;
			}

			node* _uncle(node* x) {
				node* grandpa = x->parent->parent;
				if (grandpa->left == x->parent)
					return grandpa->right;
				else return grandpa->left;
			}

			node* _brother(node* x) {
				if (x->parent->left == x)
					return x->parent->right;
				else return x->parent->left;
			}


			void 	insertFix(node* x){
				while(x->parent->color == red){
					node* uncle = _uncle(x);
					if (x->parent == x->parent->parent->left) // parent is left
					{
						//---- uncle red

						if (uncle->color == red){
							x->parent->color = black;
							uncle->color = black;
							x->parent->parent->color = red;
							x = x->parent->parent;
						}

						//---- uncle black

						else if (uncle->color == black){
							if (x->parent->right == x)
								leftRotate(&x->parent);
							rightRotate(&uncle->parent);
							uncle->parent->parent->color = black;
							uncle->parent->parent->left->color = red;
							uncle->parent->parent->right->color = red;
							return;
						}
					}
					else // parent is right
					{
						//---- uncle red

						if (uncle->color == red){
							x->parent->color = black;
							uncle->color = black;
							x->parent->parent->color = red;
							x = x->parent->parent;
						}

						//---- uncle black

						else if (uncle->color == black){
							if (x->parent->left == x)
								rightRotate(&x->parent);
							leftRotate(&uncle->parent);
							uncle->parent->parent->color = black;
							uncle->parent->parent->left->color = red;
							uncle->parent->parent->right->color = red;
							return;
						}
					}
				}
				store->color = black;
			}

			void	insert(const value_type& _data){
				node* current = store;
				node* x = new node(nil, nil, nil, red, _data);

				if (current == nil){
					x->color = black;
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
				
				return insertFix(x);
			}

			//node *find(const Key& key)
			node* find(const value_type& _data){
				node* current = store;
				node* parent = nullptr;
				while(current != nil && current->data.first != _data.first){
					parent = current;
					if (_data.first < current->data.first)
						current = current->left;
					else
						current = current->right;
				}
				return current;
			}

			void replaceNode(node* x, node* newx){
				if (newx != nil)
					newx->parent = x->parent;
				if (x == store) {
					store = newx;
					return;
				}
				if (x->parent->left == x)
					x->parent->left = newx;
				else x->parent->right = newx;
			}
			void swapNode(node* x, node* next){
				value_type tmp = std::make_pair<const Key, Data>(x->data.first, x->data.second);
				//free pairs
				x->data = std::make_pair<const Key, Data>(next->data.first, next->data.second);
				next->data = std::make_pair<const Key, Data>(tmp.first, tmp.second);
			}

			void	deleteFix(node* x){
				while (x != store && x->color == black)
				{
					node* brother = _brother(x);
					if (x->parent->left == x){
						if (brother->color == red){
							brother->color = black;
							brother->parent->color = red;
							leftRotate(&x->parent);
							brother = x->parent->left;
						}
						if (brother->color == black){
							if (brother->left->color == black 
									&& brother->right->color == black){
								brother->color = red;
								x = x->parent;
							}
							else if (brother->right->color == black){
								brother->color = red;
								brother->left->color = black;
								rightRotate(&brother);
								brother = x->parent->right;
							}
							if (brother->right->color == red){
								brother->color = brother->parent->color;
								brother->right->color = black;
								brother->parent->color = black;
								leftRotate(&x->parent);
							}
						}
					}
					else  {
						if (brother->color == red){
							brother->color = black;
							brother->parent->color = red;
							rightRotate(&x->parent);
							brother = x->parent->right;
						}
						if (brother->color == black){
							if (brother->right->color == black 
									&& brother->left->color == black){
								brother->color = red;
								x = x->parent;
							}
							else if (brother->left->color == black){
								brother->color = red;
								brother->right->color = black;
								leftRotate(&brother);
								brother = x->parent->left;
							}
							if (brother->left->color == red){
								brother->color = brother->parent->color;
								brother->left->color = black;
								brother->parent->color = black;
								rightRotate(&x->parent);
							}
						}
					}
				}
				x->color = black;
			}

			void	deleteNode(const value_type& _data){
				node* x = find(_data);

				bool isBlack = x->color;

				if (x == nil) return;
				
				node* next = nil;
				if (x->left == nil && x->right == nil){ // not child
					nil->parent = x->parent;
					replaceNode(x, nil);
					delete x;
				}
				else if (x->left != nil && x->right != nil){ // 2 childs
					next = nextNode(x);
					swapNode(x, next);
					deleteNode(next->data);
					isBlack = false;
				}
				else{ // 1 ребенок
					next = (x->left != nil) ? x->left : x->right;
					isBlack = next->color;
					replaceNode(x, next);
					next->color = black; // recolor in black
					delete x;
				}
				
				if (isBlack) deleteFix(next); //balancing
			}

			node* getRoot() { return store; }

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

			void print(int i){
				std::cout << "print "  << i << std::endl;
				print_b(store, 0); 
				std::cout << " ------------- " << std::endl;
			}
	};
}
