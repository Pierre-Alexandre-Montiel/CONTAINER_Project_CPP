/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:33 by pmontiel          #+#    #+#             */
/*   Updated: 2022/01/05 14:38:08by pmontiel         ###   ########.fr       */
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
#include "ft_pair.hpp"
#include "binary_tree.hpp"
#include "ft_map_iterator.hpp"
#include "ft_map_const_iterator.hpp"
#include "ft_map_reverse_iterator.hpp"
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"
#include "ft_vector_reverse_iterator.hpp"

namespace ft
{
    template < class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public :
        typedef Key                                                                                                             key_type;
        typedef T                                                                                                               mapped_type;
        typedef size_t                                                                                                          size_type;
        typedef Allocator                                                                                                       allocator_type;
        typedef Compare                                                                                                         key_compare;
        typedef ft::pair<const Key, T>                                                                                         value_type;
        typedef std::ptrdiff_t                                                                                                  difference_type;
        typedef T&                                                                                                              reference;
        typedef const T&                                                                                                        const_reference;
        typedef T*                                                                                                              pointer;
        typedef const T*                                                                                                        const_pointer;
        typedef ft::map_iterator<ft::binary_tree_node<key_type, mapped_type>, value_type, key_compare>                          iterator;
        typedef ft::const_map_iterator<ft::binary_tree_node<key_type, mapped_type>, value_type, key_compare>                    const_iterator;
        typedef ft::reverse_iterator<iterator>                                                                                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                                                        const_reverse_iterator;
        typedef ft::binary_t<key_type, mapped_type, key_compare, allocator_type>                                                binary_tree;

        class value_compare : ft::binary_function<value_type, value_type, bool>
        {
            friend class map<Key, T, Compare, Allocator>;
            public:
                bool operator()(const value_type& left, const value_type& right) const
                {
                    return (comp(left.first, right.first));
                }
                value_compare(key_compare pred) : comp(pred) {};
            protected:
                key_compare comp;
        };

        //######### MAP CONSTRUCTORS ###########
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _comp(comp), _alloc(alloc), _size(0) {};
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _comp(comp), _alloc(alloc), _size(0)
        {
            _size = 0;
            while (first != last)
            {
               // _tree.insert_map(*first);
                insert(*first);
                first++;
                //_size++;
            }
        }
        map (const map& x) : _comp(x._comp), _alloc(x._alloc), _size(0)
        {
            (*this) = x;
        }
        ~map()
        {
            this->clear();
        }
        //######### MAP CONSTRUCTORS END ###########

        map& operator=(const map& x)
        {
            clear();
            insert(x.begin(), x.end());
            _size = x._size;
            _comp = x._comp;
            _alloc = x._alloc;
            return (*this);
        }
        mapped_type& operator[] (const key_type& k)
        {
            if (_tree.search_it(k))
            {
                return (_tree.search(k));
            }
            else
            {
                insert(ft::make_pair(k, mapped_type()));
                mapped_type &i = _tree.search(k);
                return (i);
            }
        }
        pair<iterator, bool> insert(const value_type& val)
        {
            if (_tree.search_it(val.first))
            {
                return (ft::pair<iterator, bool>(_tree.search_it(val.first), false));
            }
            else
            {
                _tree.insert_map(val);
                _size++;
            }
            return (ft::pair<iterator, bool>(_tree.search_it(val.first), true));
        }
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            return ((insert(pair<key_type, mapped_type>(val.first,val.second))).first);
        }
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }
        
        void    print_tree()
        {
            size_type len = 0;
            len = _tree.print_map();
        }
        iterator begin()
        {
            return iterator(_tree.node_min());
        }
        iterator end()
        {
            iterator it = _tree.node_max();
            if (empty())
                return iterator(_tree.node_min());
            else
            {
                ++it;
                return iterator(it);
            }
        }
        const_iterator begin() const
        {
            return const_iterator(_tree.node_min());
        }
        const_iterator end() const
        {
            const_iterator it = _tree.node_max();
            if (empty())
                return const_iterator(_tree.node_min());
            else
            {
                ++it;
                return const_iterator(it);
            }
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(_tree.node_min());
        }
        const_reverse_iterator rbegin() const
        {
           return const_reverse_iterator(_tree.node_max()); 
        }
        const_reverse_iterator rend() const
        {
           return const_reverse_iterator(_tree.node_min()); 
        }
        size_type size() const
        {
            return (_size);
        }
        void clear()
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                erase(it);
                it++;
            }
            erase(it);
            _size = 0;
        }
        size_type count (const key_type& k) const
        {
            if (_tree.search_it(k))
                return (1);
            else
                return (0);
            //return (_tree.count_value_map(k));
        }
        bool empty() const
        {
            if (_size == 0)
					return (true);
				else
					return (false);
        }
        void erase (iterator position)
        {
            _tree.delete_node_map(position->first);
            _size--;
        }
        size_type erase (const key_type& k)
        {
            size_type len = 1;
            if (_tree.search_it(k) == NULL)
                return (0);
            else
            {
                _tree.delete_node_map(k);
                _size--;
            }
            return (len);
        }
        void erase (iterator first, iterator last)
        {
            size_type i = std::distance(first, last);
            while (i)
            {
                _tree.delete_node_map(first->first);
                first++;
                i--;
                _size--;
            }
        }
        iterator find (const key_type& k)
        {
            iterator it = _tree.search_it(k);
            return (it);
        }
        const_iterator find (const key_type& k) const
        {
            const_iterator it = _tree.search_it(k);
            return (it);
        }
        allocator_type get_allocator() const
        {
            return (_alloc);
        } 
        key_compare key_comp() const
        {
            return (_comp);
        }
        size_type max_size() const
        {
            return (_tree.max_size());
        }
        value_compare value_comp() const
        {
            return (value_compare(key_compare()));
        }
        void swap (map& x)
        {
            _tree.swap(x._tree);
            std::swap(x._size, _size);
        }
        iterator lower_bound (const key_type& k)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {   
                if (it->first == k || !(_comp(it->first, k)))
                    return (it);
                it++;
            }
            return (it);
        }
        const_iterator lower_bound (const key_type& k) const
        {   
            const_iterator it = begin();
            const_iterator ite = end();
            while (it != ite)
            {   
                if (it->first == k || !(_comp(it->first, k)))
                    return (it);
                it++;
            }
            return (it);
        }
        iterator upper_bound (const key_type& k)
        {
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {   
                if (it->first == k)
                    return (++it);                    
                if (!(_comp(it->first, k)))
                    return (it);
                it++;
            }
            return (it);
        }
        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator it = begin();
            const_iterator ite = end();
            while (it != ite)
            {   
                if (it->first == k)
                    return (++it);                    
                if (!(_comp(it->first, k)))
                    return (it);
                it++;
            }
            return (it);
        }
        ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
        }
        ft::pair<iterator,iterator> equal_range (const key_type& k)
        {
            return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
        }
        private :
            binary_tree                                        _tree;
            key_compare                                        _comp;
            allocator_type                                     _alloc;
            size_type                                          _size;
            ft::binary_tree_node<key_type, mapped_type>        _node;
    };
    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator== (const map<Key,T,Compare, Alloc>& lhs, const map<Key,T, Compare, Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		else
			return (false);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return (rhs < lhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
};