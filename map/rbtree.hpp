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
			node* 			root;
			node*			nil;
		

		// --- UTILS -----------------------------------------------------

			
			void deleteTree(node** _x){ //posOrder
				node* x = *_x;
				if (x->isNil) return;
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
				while(!current->isNil && !assign(current->data, _data)){
					parent = current;
					if (comp(_data, current->data))
						current = current->left;
					else
						current = current->right;
				}
				return current;
			}

			void print_b(node* p, int level){

				if(!p->isNil)
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
				if (!newx->isNil)
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

			void	copyTreeByNode( node* node ) {
				if ( !node->left->isNil )
					copyTreeByNode( node->left );
				if ( !node->isNil )
					insert( node->data );
				if ( !node->right->isNil )
					copyTreeByNode( node->right );
			}

			void updateNIL(node* x){
				if (comp(x->data, nil->left->data) || nil->left->isNil)
					nil->left = x;
				if (comp(nil->right->data, x->data) || nil->right->isNil)
					nil->right = x;
			}

			void updateNIL(){
				nil->left = begin();
				nil->right = last();
			}

		// ---------------------------------------------------------------
		// ---------------------------------------------------------------

		public:

			// --- CONSTRUCTORS, destructor
			
			rbtree(const key_compare& _comp) : comp(_comp), alloc(allocator_type()){
				nil = alloc.allocate(1);
				alloc.construct(nil);
				root = nil;
				updateNIL();
			}

			rbtree(const rbtree& obj) : comp(obj.comp), alloc(obj.alloc){
				nil = alloc.allocate(1);
				alloc.construct(nil);
				root = nil;
				updateNIL();

				for (node* current = obj.begin(); current->isNil == false; current = nextNode(current))
					insert(current->data);
			}

			void deleteTree(){
				deleteTree(&root);
				root = nil;
			}
			
			void copyTree( const rbtree& other ){
				deleteTree();
				copyTreeByNode(other.get_root());
			}

			rbtree& operator=( const rbtree& other ){
				copyTree(other);
				return *this;
			}


			~rbtree() {
				deleteTree();
				freeNode(nil);					
			}

			void	leftRotate(node* x){
				node*	rightTree = x->right;

				rightTree->parent = x->parent;
				if ( !x->parent->isNil ) {
					if ( x->parent->left == x )
						x->parent->left = rightTree;
					else
						x->parent->right = rightTree;
				}
				x->right = rightTree->left;
				if ( rightTree->left )
					rightTree->left->parent = x;
				x->parent = rightTree;
				rightTree->left = x;
				if ( x == root ) root = rightTree;
			}

			void	rightRotate(node* x){
				node*	leftTree = x->left;

				leftTree->parent = x->parent;
				if ( x->parent ) {
					if ( x->parent->left == x )
						x->parent->left = leftTree;
					else
						x->parent->right = leftTree;
				}
				x->left = leftTree->right;
				if ( leftTree->right )
					leftTree->right->parent = x;
				x->parent = leftTree;
				leftTree->right = x;
				if ( x == root ) root = leftTree;
			}

			node* nextNode(node* x){
				if (x->right->isNil == false){
					node* parent = x;
					x = x->right;
					while (x->isNil == false)
					{
						parent = x;
						x = x->left;
					}
					return parent;
				}
				node* y = x->parent;
				while (y->isNil == false && x == y->right){
					x = y;
					y = y->parent;
				}
				return y;
			}

			node* prevNode(node* x){
				if (x->left->isNil == false){
					node* parent = x;
					x = x->left;
					while (x->isNil == false)
					{
						parent = x;
						x = x->right;
					}
					return parent;
				}
				node* y = x->parent;
				while (y->isNil == false && x == y->left){
					x = y;
					y = y->parent;
				}
				return y;
			}

			void swap(rbtree& x){
				node* tmp = root;
				root = x.get_root();
				x.root = tmp;

				tmp = nil;
				nil = x.nil;
				x.nil = tmp;
			}
			
			node* begin() const{
				node* current = root;
				node* parent = current;
				while(!current->isNil){
					parent = current;
					current = current->left;
				}
				return parent;
			}

			node* prebegin() const{
				return nil;
			}

			node* last() const{
				node* current = root;
				node* parent = current;
				while(!current->isNil){
					parent = current;
					current = current->right;
				}
				return parent;
			}

			node* end() const{
				nil->parent = nullptr;
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
							if (x->parent->right == x){
								leftRotate(x->parent);
								x = x->left;
							}
							rightRotate(x->parent->parent);
							x->parent->color = black;
							x->parent->left->color = red;
							x->parent->right->color = red;
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
							if (x->parent->left == x){
								rightRotate(x->parent);
								x = x->right;
							}
							leftRotate(x->parent->parent);
							x->parent->color = black;
							x->parent->left->color = red;
							x->parent->right->color = red;
							return;
						}
					}
				}
				root->color = black;
			}

			ft::pair<node*, bool>	insert(const value_type& _data){
				node* current = find(_data);
				if (current->isNil == false) return ft::make_pair(current, false);

				node* x = alloc.allocate(1);
				alloc.construct(x, node(nil, nil, nil, red, _data));

				if (root->isNil == true){
					x->color = black;
					root = x;
					updateNIL(x);
					return ft::make_pair(root, true);
				}
				
				current = root;
				node* parent = current;
				while (current->isNil == false)
				{
					parent = current;
					if (comp(_data, current->data))
						current = current->left;
					else
						current = current->right;
				}

				if (comp(_data, parent->data))
					parent->left = x;
				else 
					parent->right = x;
				x->parent = parent;

				updateNIL(x);
				
				insertFix(x);
				return ft::make_pair(x, true);
			}

			ft::pair<node*, bool>	insertByHint(node* hint, const value_type& _data){
				node* current;
				node* parent;
				node* x;

				current = hint;
				parent = nullptr;
				while (!current->isNil) {
					if (_data.first == current->data.first)
						return ft::make_pair(current, false);
					parent = current;
					current = comp(_data, current->data) ?
							current->left : current->right;
				}

				x = alloc.allocate(1);
				alloc.construct(x, node(nil, nil, parent, red, _data));

				if (parent) {
					if (comp(_data, parent->data))
						parent->left = x;
					else
						parent->right = x;
				} else {
					x->color = black;
					root = x;
				}

				updateNIL(x);

				//insertFix(x);
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
							leftRotate(x->parent);
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
								rightRotate(brother);
								brother = x->parent->right;
							}
							if (brother->right->color == red){
								brother->color = brother->parent->color;
								brother->right->color = black;
								brother->parent->color = black;
								leftRotate(x->parent);
							}
						}
					}
					else  {
						if (brother->color == red){
							brother->color = black;
							brother->parent->color = red;
							rightRotate(x->parent);
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
								leftRotate(brother);
								brother = x->parent->left;
							}
							if (brother->left->color == red){
								brother->color = brother->parent->color;
								brother->left->color = black;
								brother->parent->color = black;
								rightRotate(x->parent);
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
					next = (!x->left->isNil) ? x->left : x->right;
					isBlack = next->color;
					replaceNode(x, next);
					next->color = black; // recolor in black
					freeNode(x);
				}
				
				//if (isBlack) deleteFix(next); //balancing
				updateNIL();
				return true;
			}

			node* get_root() const { return root; }

			void print(int i){
				std::cout << "print "  << i << std::endl;
				print_b(root, 0); 
				std::cout << " ------------- " << std::endl;
			}
	};

	// template< class Key, class T, class Compare, class Allocator >
	// ft::t_node<ft::pair<const Key, T> >* rbtree<Key, T, Compare, Allocator>::nil = new t_node<ft::pair<const Key, T> >();
}
