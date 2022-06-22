/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_const_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:33 by pmontiel          #+#    #+#             */
/*   Updated: 2022/02/02 16:46:35 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <math.h>
#include "map.hpp"

namespace ft
{
    template < typename node, class T, class Compare>
    class const_map_iterator
    {
        public :
        typedef node*                                       t_iterator;
        typedef size_t                                      size_type;
        typedef Compare                                     key_compare;
        typedef T                                           value_type;
        typedef std::ptrdiff_t                              difference_type;
        typedef const T&                                    reference;
        typedef const T*                                    pointer;
		typedef std::bidirectional_iterator_tag            iterator_category;
		typedef std::ptrdiff_t									diffrence_type;

        private :
        t_iterator                                         _p;
        key_compare                                        _comp;

        public :
        const_map_iterator(t_iterator node1) : _p(node1){}
        const_map_iterator(const key_compare &comp = key_compare()) : _p(nullptr), _comp(comp) {}
        template<class Iter, class fill1, class fill2>
		const_map_iterator(const ft::map_iterator<Iter, fill1, fill2>& iter) : _p(iter.base()) {};
		~const_map_iterator(void) {};
        t_iterator	base() const 
        {
			return (_p);
		}
        reference operator*() const
        {
			return (_p->key);
		}
		pointer operator->() const
        {
			return (&(operator*()));
		}
        const_map_iterator &operator=(const const_map_iterator &rhs)
		{
			_p = rhs._p;
			return (*this);
		}
		const_map_iterator operator++(void)
		{
			t_iterator _head = _p->parent;
			t_iterator _r;
			if (_p->right)
			{
				_r = _p->right;
				while (_r->left)
					_r = _r->left;
				_p = _r;
				return (_p);
			}
			while(_head != nullptr &&_head->right == _p)
			{
				_p = _head;
				_head = _head->parent;
			}
			_p = _head;
			return const_map_iterator(_p);
		};
		const_map_iterator operator++(int)
		{
			const_map_iterator tmp(*this);
			operator++();
			return (tmp);
		};
		const_map_iterator operator--(void)
		{
			t_iterator _head = _p->parent;
			t_iterator _r;
			if (_p->left)
			{
				_r = _p->left;
				while (_r->right)
					_r = _r->right;
				_p = _r;
				return (_p);
			}
			while(_head != nullptr && _head->left == _p)
			{
				_p = _head;
				_head = _head->parent;
			}
			_p = _head;
			return const_map_iterator(_p);
		};
		const_map_iterator operator--(int)
		{
			const_map_iterator tmp(*this);
			operator--();
			return (tmp);
		}
    };
	template <typename Node1, typename T1, typename Comp1, typename Node2, typename T2, typename Comp2>
	bool operator==(const const_map_iterator<Node1, T1, Comp1> &rhs, const const_map_iterator<Node2, T2, Comp2> &lhs)
	{
		return (rhs.base() == lhs.base());
	};
	template <typename Node1, typename T1, typename Comp1, typename Node2, typename T2, typename Comp2>
	bool operator==(const const_map_iterator<Node1, T1, Comp1> &rhs, const map_iterator<Node2, T2, Comp2> &lhs)
	{
		return (rhs.base() == lhs.base());
	};
	template <typename Node1, typename T1, typename Comp1, typename Node2, typename T2, typename Comp2>
	bool operator!=(const const_map_iterator<Node1, T1, Comp1> &rhs, const map_iterator<Node2, T2, Comp2> &lhs)
	{
		return (rhs.base() != lhs.base());
	};
	template <typename Node1, typename T1, typename Comp1, typename Node2, typename T2, typename Comp2>
	bool operator!=(const const_map_iterator<Node1, T1, Comp1> &rhs, const const_map_iterator<Node2, T2, Comp2> &lhs)
	{
		return (rhs.base() != lhs.base());
	};
}