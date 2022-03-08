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

	// -- equal

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	// -- lexicographical_compare

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	// -- iterator_traits

	template < class Iterator >
	class iterator_traits {
		public:
			typedef typename Iterator::iterator_type		iterator_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template < class T >
	class iterator_traits<T*> {
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

	template < class T >
	class iterator_traits<const T*> {
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

	// -- is_integral

	template < class T >
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral< bool > { static const bool value = true; };

	template <>
	struct is_integral< char > { static const bool value = true; };

	template <>
	struct is_integral< wchar_t > { static const bool value = true; };

	template <>
	struct is_integral< short > { static const bool value = true; };

	template <>
	struct is_integral< int > { static const bool value = true; };

	template <>
	struct is_integral< unsigned int > { static const bool value = true; };

	template <>
	struct is_integral< long > { static const bool value = true; };

	template <>
	struct is_integral< long long > { static const bool value = true; };

}


