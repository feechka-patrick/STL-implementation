#pragma once

#include <iostream>
#include "../utils.hpp"
#include "pair.hpp"
#include "node.hpp"

namespace ft{

	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class rbtree{
		public:
			typedef ft::pair<const Key, T>									value_type;
			typedef ft::t_node<value_type>									node;
			typedef Compare													key_compare;
			typedef typename Allocator::template rebind<node>::other		allocator_type;

		private:
			key_compare		comp;
			allocator_type	alloc;
			node*			nil;
			node* 			root;
		

		// --- UTILS -----------------------------------------------------

			void deleteTree(node** _x){ //posOrder
				node* x = *_x;
				if (x == nil) return;
				deleteTree(&x->left);
				deleteTree(&x->right);
				freeNode(x);
			}
			
			void freeNode(node *x){
				alloc.destroy(x);
				alloc.deallocate(x, 1);
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

			bool assign(const value_type& lhs, const value_type& rhs){
				if (!comp(lhs, rhs) && !comp(rhs, lhs)) return true;
				else return false;
			}

			node *find(const Key& key) {
				return find(make_pair(key, 0));
			}

			node* find(const value_type& _data){
				node* current = root;
				node* parent = nullptr;
				while(current != nil && !assign(current->data, _data)){
					parent = current;
					if (comp(_data, current->data))
						current = current->left;
					else
						current = current->right;
				}
				current->parent = parent;
				return current;
			}

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

			void replaceNode(node* x, node* newx){
				if (newx != nil)
					newx->parent = x->parent;
				if (x == root) {
					root = newx;
					return;
				}
				if (x->parent->left == x)
					x->parent->left = newx;
				else x->parent->right = newx;
			}
			
			void swapNode(node* x, node* next){
				node* tmp = alloc.allocate(1);
				alloc.construct(tmp, next);

				replaceNode(next, tmp);
				replaceNode(x, next);
				next->copy(x);
				next->left->parent = next;
				next->right->parent = next;

				replaceNode(tmp, x);
				x->copy(tmp);
				x->right->parent = x;
				freeNode(tmp);
			}

		// ---------------------------------------------------------------
		// ---------------------------------------------------------------

		public:

			// --- CONSTRUCTORS, destructor

			rbtree() : comp(key_compare()), alloc(allocator_type()){
				nil = alloc.allocate(1);
				alloc.construct(nil);
				root = nil;
			}
			
			rbtree(const key_compare& _comp) : comp(_comp), alloc(allocator_type()){
				nil = alloc.allocate(1);
				alloc.construct(nil);
				root = nil;
			}

			rbtree(const rbtree& obj) : comp(obj.comp), alloc(obj.alloc){
				nil = alloc.allocate(1);
				alloc.constuct(nil);
				root = nil;

				for (node* current = obj.begin(); current != nil; current = nextNode(current))
					insert(current->data);
			}

			void deleteTree(){
				deleteTree(&root);
				root = nil;
			}

			~rbtree() {
				deleteTree();
				if (nil) freeNode(nil);
					
			}

			void	leftRotate(node** x){
				node* rightTree = (*x)->right;
				(*x)->right = rightTree->left;
				
				if (rightTree->left != nil)
					rightTree->left->parent = (*x);
				rightTree->parent = (*x)->parent;
				if ((*x)->parent == nil)
					root = rightTree;
				else if ((*x) == (*x)->parent->left)
					(*x)->parent->left = rightTree;
				else (*x)->parent->right = rightTree;
				rightTree->left = (*x);
				(*x)->parent = rightTree;
			}

			void	rightRotate(node** x){
				node* leftTree = (*x)->left;
				(*x)->left = leftTree->right;
				
				if (leftTree->right != nil)
					leftTree->right->parent = (*x);
				leftTree->parent = (*x)->parent;
				if ((*x)->parent == nil)
					root = leftTree;
				else if ((*x) == (*x)->parent->right)
					(*x)->parent->right = leftTree;
				else (*x)->parent->left = leftTree;
				leftTree->right = (*x);
				(*x)->parent = leftTree;
			}

			static node* nextNode(node* x){
				x = x->right;
				node* parent = x;
				while (x != nil)
				{
					parent = x;
					x = x->left;
				}
				return parent;
			}

			static node* prevNode(node* x){
				x = x->left;
				node* parent = x;
				while (x != nil)
				{
					parent = x;
					x = x->right;
				}
				return parent;
			}
			
			node* begin(){
				node* current = root;
				node* parent = current;
				while(current != nil){
					parent = current;
					current = current->left;
				}
				return parent;
			}

			node* prebegin(){
				nil->parent = begin();
				return nil;
			}

			node* last(){
				node* current = root;
				node* parent = current;
				while(current != nil){
					parent = current;
					current = current->right;
				}
				return parent;
			}

			node* end(){
				nil->parent = last();
				return nil;
			}


			// --- INSERT
			
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
				root->color = black;
			}

			ft::pair<node*, bool>	insert(const value_type& _data){
				node* current = find(_data);
				if (current != nil) return ft::make_pair(current, false);

				node* x = alloc.allocate(1);
				alloc.construct(x, nil, nil, nil, red, _data);

				if (root == nil){
					x->color = black;
					root = x;
					return ft::make_pair(root, true);
				}
				

				x->parent = current->parent;	
				if (comp(_data, x->parent->data))
					x->parent->left = x;
				else 
					x->parent->right = x;
				
				insertFix(x);
				return ft::make_pair(x, true);
			}

			// --- DELETE


			void	deleteFix(node* x){
				while (x != root && x->color == black)
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

			bool	deleteNode(const value_type& _data){
				node* x = find(_data);
				return deleteNode(x);
			}

			bool	deleteNode(node* x){
				bool isBlack = x->color;

				if (x == nil) return false;
				
				node* next = nil;
				if (x->left == nil && x->right == nil){ // not child
					nil->parent = x->parent;
					replaceNode(x, nil);
					freeNode(x);
				}
				else if (x->left != nil && x->right != nil){ // 2 childs
					next = nextNode(x);
					swapNode(x, next);
					deleteNode(x);
					isBlack = false;
				}
				else{ // 1 ребенок
					next = (x->left != nil) ? x->left : x->right;
					isBlack = next->color;
					replaceNode(x, next);
					next->color = black; // recolor in black
					freeNode(x);
				}
				
				if (isBlack) deleteFix(next); //balancing
				return true;
			}

			node* root() { return root; }

			node* begin()

			void print(int i){
				std::cout << "print "  << i << std::endl;
				print_b(root, 0); 
				std::cout << " ------------- " << std::endl;
			}
	};
}
