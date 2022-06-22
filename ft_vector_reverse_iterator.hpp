/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reverse_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/10 14:36:13y pmontiel         ###   ########.fr       */
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
    template<typename Iterator>
    class reverse_iterator
    {
        public:
            typedef size_t                                                  size_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::diffrence_type		diffrence_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
        private:
            Iterator _p;   

        public:

            reverse_iterator(void) {};

			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rhs) : _p(rhs.base()) {};
			explicit reverse_iterator(const Iterator &rhs) : _p(rhs) {};
            ~reverse_iterator(void) {};

			reverse_iterator &operator=(const reverse_iterator &rhs)
			{
				_p = rhs._p;
				return (*this);
			};
			reverse_iterator &operator++(void)
			{
				_p--;
				return (*this);
			};
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			reverse_iterator &operator--(void)
			{
				_p++;
				return (*this);
			};
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				operator--();
				return (tmp);
			};
			reference operator*(void) const
			{
				Iterator t = _p;
				return (*(--t));
			};
			pointer operator->(void) const
			{
				return (&(operator*()));
			};
			Iterator base() const
			{
				return (_p);
			}
			diffrence_type operator-(reverse_iterator &rhs ) const
			{ 
				return (rhs._p + _p); 
			}
			reverse_iterator &operator+=(int n)
			{
				_p -= n;
				return (*this);
			};
			reverse_iterator &operator-=(int n)
			{
				_p += n;
				return (*this);
			};
			reference &operator[](size_type index) const
			{
				return (_p[- index - 1]);
			}
			reverse_iterator operator+(const diffrence_type val)
			{
				return reverse_iterator(_p - val);				
			}
			reverse_iterator operator-(const diffrence_type val)
			{
				return reverse_iterator(_p + val);				
			}
	        bool operator==(const reverse_iterator &rhs) const
            {
        		return (rhs._p == rhs);
        	};
	};
	template <typename iterator1, typename iterator2>
	typename reverse_iterator<iterator1>::diffrence_type operator-(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (lhs.base() - rhs.base());
	};
	template <typename iterator1>
	reverse_iterator<iterator1> operator+(const typename reverse_iterator<iterator1>::diffrence_type &lhs, const reverse_iterator<iterator1> &rhs)
	{
		return reverse_iterator<iterator1>(rhs.base() - lhs);
	};
   template <typename iterator1, typename iterator2>
	bool operator==(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() == lhs.base());
	};
	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() == lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator!=(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() != lhs.base());
	};
	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() != lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator>(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() < lhs.base());
	};
	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() < lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator>=(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() <= lhs.base());
	};	
	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() <= lhs.base());
	};	
	template <typename iterator1, typename iterator2>
	bool operator<(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() > lhs.base());
	};
	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() > lhs.base());
	};
	template <typename iterator1, typename iterator2>
	bool operator<=(const reverse_iterator<iterator1> &rhs, const reverse_iterator<iterator2> &lhs)
	{
		return (rhs.base() >= lhs.base());
	};
	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator> &rhs, const reverse_iterator<Iterator> &lhs)
	{
		return (rhs.base() >= lhs.base());
	};
};