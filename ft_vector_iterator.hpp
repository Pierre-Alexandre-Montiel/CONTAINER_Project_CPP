/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/10 19:46:56by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iterator>
#include <cassert>
#include <algorithm>
#include <math.h>
#include "ft_iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class vector_iterator
    {
        public:
           	typedef T                                               value_type;
            typedef size_t                                          size_type;
            typedef std::random_access_iterator_tag                 iterator_category;
            typedef T&                                              reference;
            typedef const T&                                        const_reference;
            typedef T*                                              pointer;
            typedef const T*                                        const_pointer;
			typedef std::ptrdiff_t									diffrence_type;

        private:
            pointer _p;   

        public:
            vector_iterator(void) {};
			explicit vector_iterator(pointer p) : _p(p) {};
			template<class Iter>
			vector_iterator(const vector_iterator<Iter>& iter) : _p(iter.base()) {};
            ~vector_iterator(void) {};

			vector_iterator &operator=(const vector_iterator &rhs)
			{
				_p = rhs._p;
				return (*this);
			};
			vector_iterator &operator++(void)
			{
				_p++;
				return (*this);
			};
			vector_iterator operator++(int)
			{
				vector_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			vector_iterator &operator--(void)
			{
				_p--;
				return (*this);
			};
			vector_iterator operator--(int)
			{
				vector_iterator tmp(*this);
				operator--();
				return (tmp);
			};
			reference operator*(void) const
			{
				return (*_p);
			};
			pointer operator->(void) const
			{
				return &(operator*());
			};
			pointer base() const
			{
				return (_p);
			}
			vector_iterator operator+(diffrence_type rhs)
			{ 
				return vector_iterator(_p + rhs); 
			};
			diffrence_type operator-(const vector_iterator &rhs ) const
			{ 
				return (_p - rhs._p); 
			}
			vector_iterator operator-(int n) const
			{
				vector_iterator t(*this);
				t -= n;
				return (t);
			};
			vector_iterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			};
			vector_iterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};
			reference &operator[](size_type index) const
			{
				return (_p[index]);
			}
	};
	template <typename iterator1, typename iterator2>
	bool operator==(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() == lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator!=(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() != lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator>(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() > lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator>=(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() >= lhs.base());
	};	
	template <typename iterator1, typename iterator2>
	bool operator<(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() < lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator<=(const vector_iterator<iterator1> &rhs, const vector_iterator<iterator2> &lhs)
	{
		return (rhs.base() <= lhs.base());
	};

	template <typename iterator1>
   	vector_iterator<iterator1> operator+(const typename vector_iterator<iterator1>::diffrence_type &lhs, vector_iterator<iterator1> & rhs)
    {
        return vector_iterator<iterator1>(rhs.base() + lhs);
    }
	template <typename iterator1, typename iterator2>
   	typename vector_iterator<iterator2>::diffrence_type operator-(const vector_iterator<iterator1> &lhs, const vector_iterator<iterator2> & rhs)
    {
        return (lhs.base() - rhs.base());
    }
}; 