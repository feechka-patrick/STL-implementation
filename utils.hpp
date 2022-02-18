#pragma once

namespace ft {
	
	// -- swap
	template<typename T>
	void swap(T& lhs, T& rhs){
		T tmp(lhs);

		lhs = rhs;
		rhs = tmp;
	}

	// -- conditional

	template<bool B, class T, class F>
	struct conditional { typedef T type; };
	
	template<class T, class F>
	struct conditional<false, T, F> { typedef F type; };


	// -- enable_if

	template<bool B, class T = void>
	struct enable_if{};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };

}