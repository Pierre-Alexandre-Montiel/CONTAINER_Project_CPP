/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/27 11:40:16 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <math.h>
#include "ft_pair.hpp"
namespace ft
{
	template <bool Cond, class T = void>
    struct enable_if {};

	template<class T>
	struct enable_if<true, T> 
    {
		typedef T type;
	};
	template <class InputIterator1, class InputIterator2>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
	  while (first1!=last1) {
	    if (!(*first1 == *first2))
	      return false;
	    ++first1; ++first2;
	  }
	  return true;
	}
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
	  while (first1!=last1)
	  {
	    if (first2==last2 || *first2<*first1) return false;
	    else if (*first1<*first2) return true;
	    ++first1; ++first2;
	  }
	  return (first2!=last2);
	}
	template <class T1, class T2> 
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (lhs.first == rhs.first);
	}
	template <class T1, class T2> 
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(lhs == rhs));
	}
	template <class T1, class T2> 
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template <class T1, class T2> 
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (rhs < lhs);
	}
	template <class T1, class T2> 
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(lhs < rhs));
	}
	template <class T1, class T2> 
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(rhs < lhs));
	}
}