/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/26 13:46:05 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <math.h>

namespace ft
{
	template <class T1, class T2>
        struct pair 
        {
            public :
                typedef T1 first_type;
                typedef T2 second_type;
                first_type first;
                second_type second;
                pair() : first(), second() {}
                template<class U, class V> 
                pair (const ft::pair<U,V>& pr) : first(pr.first), second(pr.second) {}
                pair(const first_type &a, const second_type &b) : first(a), second(b) {}
                pair& operator= (const pair& pr) 
                {
                    first = pr.first;
                    second = pr.second;
                    return (*this);
                }
        };
        template <class T1,class T2>
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
          return (ft::pair<T1,T2>(x,y));
        };
        template <class Arg1, class Arg2, class Result>
        struct binary_function 
        {
            typedef Arg1 first_argument_type;
            typedef Arg2 second_argument_type;
            typedef Result result_type;
        };
        template <class T> 
        struct less : binary_function <T,T,bool>
        {
            bool operator() (const T& x, const T& y) const {return x<y;}
        };
        template <class T> 
        struct more : binary_function <T,T,bool>
        {   
            bool    operator()(const T &first, const T &second) const 
            {
                return (first > second);
            }
        };
}