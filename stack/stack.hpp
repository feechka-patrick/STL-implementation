#pragma once

#include <iostream>
#include "../vector/vector.hpp"

namespace ft{
	template<class T, class Container = ft::vector<T> > 
	class stack{
		
		public:

		// -- member types

		typedef Container							container_type;
		typedef T									value_type;
		typedef std::size_t							size_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;


		// -- constructors, destructor

		explicit stack( const container_type& cont = container_type() )
				: c(cont) {}

		stack( const stack& other )
				: c(other.c) {}

		stack& operator=( const stack& other ) {
			c = other.c;
			return *this;
		}

		~stack() {}


		// -- member functions
		
		reference top() { return c.back(); }

		const_reference top() const { return c.back(); }

		bool empty() const { return c.empty(); }

		size_type size() const { return c.size(); }

		void push( const value_type& value ) { c.push_back(value); }

		void pop() { c.pop_back(); }

		container_type get_container() const { return this->c; }

		private:
			container_type c;

	};

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() == rhs.get_container() ; }
	
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() != rhs.get_container() ; }
	
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() < rhs.get_container() ; }
	
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() <= rhs.get_container() ; }
	
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() > rhs.get_container() ; }
	
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{ return lhs.get_container() >= rhs.get_container() ; }
}