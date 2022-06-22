/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/08 16:02:09 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <string>
#include <cassert>
#include <algorithm>
#include <math.h>

namespace ft
{
	template<class Iterator>
	struct iterator_traits
	{
		typedef	typename Iterator::diffrence_type		diffrence_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};
	
	template<class T>
	struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t						diffrence_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
	
	template<class T>
	struct iterator_traits<T *const>
	{
		typedef	std::ptrdiff_t						diffrence_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
}
#endif