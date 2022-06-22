/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
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
#include "ft_map_iterator.hpp"
#include "ft_vector_reverse_iterator.hpp"

static size_t len;

namespace ft
{
    template <class Key, class T>
    struct binary_tree_node
	{
	    typedef binary_tree_node*           _ptr;
	    typedef const binary_tree_node*     _const_ptr;
	    _ptr                    parent;
	    _ptr                    left;
        _ptr                    right;
        ft::pair<const Key, T>  key;
        
    };

    template < class Key, class T, class Compare, class Allocator >
    class binary_t
    {
        public :
            typedef ft::binary_tree_node<Key, T>                        node;
            typedef node*                                               pointer;
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef size_t                                              size_type;
            typedef Allocator                                           allocator_type;
            typedef Compare                                             key_compare;
            typedef ft::pair<const Key, T>                              value_type;
            typedef typename Allocator::template rebind<node>::other    _n_alloc;
            typedef ft::map_iterator<ft::binary_tree_node<key_type, mapped_type>, value_type, key_compare>                          iterator;
            typedef ft::map_iterator<ft::binary_tree_node<key_type, mapped_type>, const value_type, key_compare>                    const_iterator;
            typedef ft::reverse_iterator<iterator>                                                                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                                                        const_reverse_iterator;

            binary_t(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _comp(comp), _alloc(alloc), _root(nullptr) 
            {
                _end = _node_alloc.allocate(1);
                 _node_alloc.construct(_end, node());
            }
            binary_t(const binary_t &x)
            {
                (*this) = x;
            }
            binary_t& operator=(const binary_t &copy)
            {
                _comp = copy._comp;
                _alloc = copy._alloc;
                _node_alloc = copy._node_alloc;
                if (_root)
                {
                    while (_root)
                    {
                        _node_alloc.deallocate(_root, 1);
                       // _alloc.destroy(_root);
                    }
                }
                _root = creat_node(_root->key);
                return (*this);
            }
            ~binary_t() {};

            pointer creat_node(const value_type &val)
            {
                pointer Nnode = _node_alloc.allocate(1);
                _alloc.construct(&Nnode->key, val);
                Nnode->parent = nullptr;
                Nnode->left = nullptr;
                Nnode->right = nullptr;
                return (Nnode);
            }
            void destroy_tree()
            {
                size_type len = print_map();
                _node_alloc.deallocate(_root, len);
                _node_alloc.destroy(_root);
            }
            node* inpre(node* p)
            {
                while(p->right != NULL)
                    p = p->right;
                return p;    
            }
            node* insuc(node* p)
            {
                while(p->left != NULL)
                    p = p->left;
                return p;    
            }
            node* remove(node* t, const key_type &x)
            {
                if(t == NULL)
                {
                    _node_alloc.deallocate(t, 1);
                    return NULL;
                }
                else if (_comp(x, t->key.first))
                    t->left = remove(t->left, x);
                else if (x == t->key.first)
                {
                    node* save;
                    node* temp;
                    if( (t->left == NULL) || (t->right == NULL) )
                    {
                        temp = t->left ? t->left : t->right;
                        if(temp)
                        {
                            save = t;
                            temp->parent = t->parent;
                            t = temp;
                            t->parent = temp->parent;
                        }
                        else
                        {
                            temp = t;
                            t = NULL;
                        }
                    }
                    else
                    {
                        node *tmp = insuc(t->right);
                        _alloc.construct(&t->key, tmp->key);
					    t->right = remove(t->right, tmp->key.first);
                    }
                }
                else
                    t->right = remove(t->right, x);
                if (t == NULL)
                    return (t);
               return (t);
            }
            void delete_node_map(const key_type &k)
            {
				if (_root == NULL)
				    return ;
                _root = remove(_root, k);
            }
            size_type btree_apply_prefix(node *root)
            {
                if (root)
                {
                    std::cout << root->key.first << " = ";
                    std::cout << root->key.second << "\n";
                    if (root->left)
                    {  
                        btree_apply_prefix(root->left);
                        len++;
                    }
                    if (root->right)
                    {   
                        btree_apply_prefix(root->right);
                        len++;
                    }
                }
                return (len + 1);
            }
            size_type print_map()
            {
                size_type len = 0;
                len = btree_apply_prefix(_root);
                return (len);
            }
            size_type    count_value(node *root, const key_type &k) const
            {
                size_type size = 0;
                while (root->left)
                {
                    if (root->key.first == k)
                    {
                        size++;
                    }
                    root = root->left;
                }
                while (root->right)
                {
                    if (root->key.first == k)
                        size++;
                    root = root->right;
                }
                return (size);
            }
            size_type count_value_map(const key_type &k) const
            {
                size_type len = count_value(_root, k);
                return (len);
            }
             size_type    countt(node *root) const
            {
                size_type size = 0;
                while (root->left)
                {
                    size++;
                    root = root->left;
                }
                size++;
                while (root->right)
                {
                        size++;
                    root = root->right;
                }
                size++;
                return (size);
            }
            size_type countt_value_map() const
            {
                size_type len = countt(_root);
                return (len);
            }
            pointer insert_data(node *root, const value_type &val)
            {
                if (root == NULL)
                {
                    root = creat_node(val);    
                    return root;
                }
                else if (_comp(val.first, root->key.first))
                {
                    root->left = insert_data(root->left, val);
                    root->left->parent = root;                            
                }
                else if (val.first == root->key.first)
                    return (root);
                else
                {
                    root->right = insert_data(root->right, val);    
                    root->right->parent = root;
             //       root->parent = _end;
               //     _end->left = root;
                }
                return (root);
            }
            pointer    insert_map(const value_type val)
            {
                if (_root == NULL)
                    _root = creat_node(val);
                else
                {
                    _root = insert_data(_root, val);
                }
                _root = add_end_node(_root, _end);
                return (_root);
            }
            pointer	add_end_node(node *root, node *endN)
		    {
		    	root->parent = endN;
		    	endN->left = root;
		    	return (root);
		    }
            mapped_type &search(const key_type &val) const
            {
                pointer res = _root;
                while (res)
                {
                    if (_comp(val , res->key.first))
                        res = res->left;
                    else if (val == res->key.first)
                        return (res->key.second);
                    else
                        res = res->right;
                }
	            return (res->key.second);
            }
            pointer search_it(const key_type &val) const
            {
                pointer res = _root;
                while (res)
                {
                    if (_comp(val , res->key.first))
                        res = res->left;
                    else if (val == res->key.first)
                        return (res);
                    else
                        res = res->right;
                }
	            return (NULL);
            }
            int level_count(node *root);
            pointer node_min() const
            {
                pointer res = _root;
                if (res)
                {
                    while (res->left)
                    {
                        res = res->left;
                    }
                }
                else
                    return(_root);
                return (res);
            }
            pointer node_max() const
            {
                pointer res = _root;
                if (res && res->right != _end)
                {
                    while (res->right)
                    {
                        res = res->right;
                    }
                }
                return (res);
            }
            iterator end() const
            {
				return iterator(_end);
			}
            void  swap(binary_t &x)
            {
                std::swap(x._root, _root);
                std::swap(x._end, _end);
            }
            size_type btree_level_count(node *root)
            {
                size_type l = 0;
                size_type r = 0;
                if (root)
                {
                    l = btree_level_count(root->left);
                    r = btree_level_count(root->right);
                    if (l > r)
                        return (l + 1);
                    else
                        return (r + 1);
                }
                return (0);
            } 
            node * rotateright(node *x)
            {
                node *y;
                y = x -> left;
                x -> left = y -> right;
                y -> right = x;
                x -> ht = btree_level_count(x);
                y -> ht = btree_level_count(y);
                return(y);
            }
            node * rotateleft(node *x)
            {
                node *y;
                y = x -> right;
                x -> right = y -> left;
                y -> left = x;
                x -> ht = btree_level_count(x);
                y -> ht = btree_level_count(y);
                return(y);
            }
            node * RR(node *n)
            {
                n = rotateleft(n);
                return(n);
            }
            node * LL(node *n)
            {
                n = rotateright(n);
                return(n);
            }
            node * LR(node *n)
            {
                n -> left = rotateleft(n->left);
                n = rotateright(n);
                return(n);
            }
            node * RL(node *n)
            {
                n -> right = rotateright(n->right);
                n = rotateleft(n);
                return(n);
            }
            size_type balanceFactor(node *n)
            {
                size_type lh,rh;
                if(n == NULL)
                    return(0);
                if(n -> left == NULL)
                    lh = 0;
                else
                    lh = 1 + n->left->ht;
                if(n -> right == NULL)
                    rh = 0;
                else
                    rh = 1 + n -> right -> ht;
                return(lh-rh);
            }
            size_type max_size(void) const
            {
                return (_n_alloc().max_size());
            }
        private :
            key_compare                 _comp;
            allocator_type              _alloc;
            _n_alloc                    _node_alloc;
            pointer                     _root;  
            pointer                     _end;  

    };
    template <class T1, class T2> 
	bool operator==(const binary_tree_node<T1,T2>& lhs, const binary_tree_node<T1,T2>& rhs) 
	{
		return (lhs.key == rhs.key);
	}
}