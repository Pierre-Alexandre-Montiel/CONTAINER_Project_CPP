/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:33 by pmontiel          #+#    #+#             */
/*   Updated: 2022/02/03 12:23:49 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <iterator>
#include <string>
#include <cassert>
#include <algorithm>
#include <math.h>
#include "vector.hpp"


namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public :
            typedef size_t										size_type;
			typedef T											value_type;
			typedef Container							        container_type;
			typedef T&								            reference;
			typedef const T&								    const_reference;
            typedef T*								            pointer;
			typedef const T*								    const_pointer;

        explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}
        stack(const stack& x) : _cont(x._cont) {}
        ~stack() {}

        void push (const value_type& val)
        {
            _cont.push_back(val);
        }
        void pop ()
        {
            _cont.pop_back();
        }
        size_type size() const
        {
            size_type len = _cont.size();
            return (len);
        }
        void print1()
		{
            size_type len = _cont.size();
			for (size_type i = 0; i < len; i++) 
			{
				std::cout << _cont[i] << " ";
			}
			std::cout << std::endl;
		}
        bool empty() const
        {
            bool res = _cont.empty();
            return (res);
        }
        value_type& top()
        {
            reference res = _cont.back();
            return (res);
        }
        const value_type& top() const
        {
            const_reference res = _cont.back();
            return (res);
        }
        stack &operator=(stack const &x) 
        {
    		_cont = x._cont;
    		return (*this);
    	}
       // template <class T, class Container>
        friend bool operator==(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)	
        {
            return (lhs._cont == rhs._cont);
        }
      //  template <class T, class Container>
        friend bool operator!=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)
        {
            return (lhs._cont != rhs._cont);
        }
       // template <class T, class Container>
        friend bool operator<(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)
        {
            return (lhs._cont < rhs._cont);
        }
      //  template <class T, class Container>
        friend bool operator<=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)
        {
            return (lhs._cont <= rhs._cont);
        }
      //  template <class T, class Container>
        friend bool operator>(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)
        {
            return (lhs._cont > rhs._cont);
        }
      //  template <class T, class Container>
        friend bool operator>=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs)
        {
            return (lhs._cont >= rhs._cont);
        }
        private :
            container_type _cont;
    };
}
#endif