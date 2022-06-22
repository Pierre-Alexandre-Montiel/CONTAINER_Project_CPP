/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-alexandremontiel <pierre-alexand    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:33 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/26 23:00:38 by pierre-alex      ###   ########.fr       */
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
    template < typename Iterator >
    class map_reverse_iterator
    {
        public :
        typedef typename Iterator::t_iterator                        t_iterator;
        typedef typename Iterator::size_type                         size_type;
        typedef typename Iterator::key_compare                       key_compare;
        typedef typename Iterator::value_type                        value_type;
        typedef typename Iterator::difference_type                   difference_type;
        typedef typename Iterator::reference                         reference;
        typedef typename Iterator::const_reference                   const_reference;
        typedef typename Iterator::pointer                           pointer;
        typedef typename Iterator::const_pointer                     const_pointer;

        private :
        Iterator                                         	_p;
        key_compare                                        _comp;

        public :
        map_reverse_iterator(Iterator node1) : _p(node1) {}
        map_reverse_iterator(const key_compare &comp = key_compare()) : _p(nullptr), _comp(comp) {}
        template<class Iter>
		map_reverse_iterator(const map_reverse_iterator<Iter>& iter) : _p(iter.base()) {};
		~map_reverse_iterator(void) {};
        Iterator	base() const 
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
        map_reverse_iterator &operator=(const map_reverse_iterator &rhs)
		{
			_p = rhs._p;
			return (*this);
		}
		Iterator operator++(void)
		{
			Iterator _head = _p->parent;
			Iterator _r;
			if (_p->left)
			{
				_r = _p->left;
				while (_r->right)
					_r = _r->right;
				_p = _r;
				return (_p);
			}
			while(_head->left == _p)
			{
				_p = _head;
				_head = _head->parent;
			}
			_p = _head;
			return _p;
		};
		map_reverse_iterator operator++(int)
		{
			map_reverse_iterator tmp(*this);
			operator++();
			return (tmp);
		};
		Iterator operator--(void)
		{
			Iterator _head = _p->parent;
			Iterator _r;
			if (_p->right)
			{
				_r = _p->right;
				while (_r->left)
					_r = _r->left;
				_p = _r;
				return (_p);
			}
			while(_head->right == _p)
			{
				_p = _head;
				_head = _head->parent;
			}
			_p = _head;
			return _p;
		};
		map_reverse_iterator operator--(int)
		{
			map_reverse_iterator tmp(*this);
			operator--();
			return (tmp);
		}
		friend bool operator==(const map_reverse_iterator &rhs, const map_reverse_iterator &lhs)
		{
			return (rhs.base() == lhs.base());
		};
		friend bool operator!=(const map_reverse_iterator &rhs, const map_reverse_iterator &lhs)
		{
			return (rhs.base() != lhs.base());
		};
    };
}

