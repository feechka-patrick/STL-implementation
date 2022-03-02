#pragma once

namespace ft{
    enum colors {red, black}; 
    
    template< class value_type>
			struct t_node {
				typedef t_node  node;

				struct t_node*	left;
				struct t_node*	right;
				struct t_node*	parent;
				colors	color;// bool мб
				value_type	data;
				bool	isNil;

				t_node() : left(nullptr), right(nullptr), parent(nullptr), color(black), isNil(true) {}
				t_node(node* _left, node* _right, node* _parent, value_type _data)
					: left(_left), right(_right), parent(_parent), data(_data), isNil(false)  {}

				t_node(node* _left, node* _right, node* _parent, colors c, value_type _data)
					: left(_left), right(_right), parent(_parent), color(c), data(_data), isNil(false)  {
					}
				t_node(const node* obj)
					: left(obj->left), right(obj->right), parent(obj->parent), color(obj->color), data(obj->data),
						isNil(false) {
					}

				void copy(const node* obj){
					this->left = obj->left;
					this->right = obj->right;
					this->parent = obj->parent;
					this->color = obj->color;
				}
            };
}