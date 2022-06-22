/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/27 11:35:34 by pmontiel         ###   ########.fr       */
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
    template <class T>
    struct is_integral 
    { 
        static const bool value = false; 
    };

    template <> struct is_integral<bool> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<char> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<wchar_t> 
    {  
        static const bool value = true; 
    };
    template <> struct is_integral<signed char>
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<short int>
    {  
        static const bool value = true; 
    };
    template <> struct is_integral<int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<long int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<long long int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<unsigned char> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<unsigned short int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<unsigned int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<unsigned long int> 
    { 
        static const bool value = true; 
    };
    template <> struct is_integral<unsigned long long int> 
    { 
        static const bool value = true; 
    };
}