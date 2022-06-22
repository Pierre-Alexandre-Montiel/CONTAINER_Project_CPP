/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
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
#include "ft_vector_iterator.hpp"
#include "ft_vector_reverse_iterator.hpp"
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"

namespace ft
{
	template <class T, typename Allocator = std::allocator<T> >	
		class vector
	{
		public:
			typedef size_t										size_type;
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef T&      									reference;
			typedef const T& 									const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::vector_iterator<T>						iterator;			
			typedef ft::vector_iterator<T const>				const_iterator;			
			typedef ft::reverse_iterator<iterator>          	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
			typedef std::ptrdiff_t 								difference_type;

			//###############################################################################
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc)
			{
				my_capacity = 0;
				my_size = 0;
				tab = nullptr;
			};
			//###############################################################################
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), my_size(0), my_capacity(0), tab(nullptr)
			{
				for (size_type i = 0; i < n; i++)
				{
					push_back(val);
				}
			}
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc)
			{
				my_capacity = 0;
				my_size = 0;
				size_type i = 0;
				while (first != last)
				{
					push_back(*first);
					first++;
					i++;
				}				
			}
			//###############################################################################
			vector(const vector& x)
			{
				tab = _alloc.allocate(x.capacity());
				std::copy(x.begin(), x.end(), begin());
				my_size = x.size();
				my_capacity = x.capacity();
			}
			//###############################################################################
			iterator begin()
			{
				return iterator(tab);
			}
			const_iterator begin() const
			{
				return const_iterator(tab);
			}
			//###############################################################################
			iterator end()
			{
				return (iterator(tab + size()));
			}
			const_iterator end() const
			{
				return (const_iterator(tab + size()));
			}
			//###############################################################################
			reference front()
			{
				return (tab[0]);
			}
			//###############################################################################
			const_reference front() const
			{
				return (tab[0]);
			}
			//###############################################################################
			reference back()
			{
				return (tab[my_size - 1]);
			}
			//###############################################################################
			const_reference back() const
			{
				return (tab[my_size - 1]);
			}
			//###############################################################################
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			//###############################################################################
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}
			//###############################################################################
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}
			//###############################################################################
			template <class InputIterator>
 	 		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			//###############################################################################
			void assign (size_type n, const value_type& val)
			{
				if (n)
				{
					clear();
					size_type i = 0;
					while (i < n)
					{
						push_back(val);
						i++;
					}
				}
			}
			//###############################################################################
			iterator insert(iterator position, const value_type& val)
			{
				//T* temp; 
				ft::vector<value_type> copy;
				iterator comp = begin();
				iterator len = end();
				//size_type i = 0;
				//size_type j = 0;
				size_type copyy = 0;
				/*if (my_size + 1 > my_capacity)
				{
					temp = _alloc.allocate(2 * my_capacity);
					my_capacity *= 2;
				}
				else
					temp = _alloc.allocate(my_capacity);*/
				while (comp != position) 
				{
					//std::cout << "COMP = " << *comp << "\n";
					//_alloc.construct(&temp[i], tab[i]);
					copy.push_back(*comp);
					comp++;
					copyy++;
					//i++;
				}
				//copy++;
				//_alloc.construct(&temp[i], val);
				copy.push_back(val);
				//i++;
				//j = i - 1;
				while (comp != len) 
				{
					copy.push_back(*comp);
				//	_alloc.construct(&temp[i], tab[j]);
					comp++;
					//i++;
					//j++;
				}
				_alloc.destroy(tab);
				//tab = temp;
				my_size++;
				*this = copy;
				return iterator(tab + copyy);
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type i = 0;
				(void)n;
				while (i < n)
				{
					position = insert(position, val);
					i++;
				}	
			}
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				ft::vector<value_type> copy;
			//	iterator stock = first;
				iterator comp1 = begin();
				iterator finish = end();
				//size_type i = 0;
				/*while (first != last) 
				{
					first++;
					i++;
				}*/
				/*if (my_capacity < my_size + i)
				{
					reserve(my_size + i);
				}*/
				while (comp1 != position)
				{
					copy.push_back(*comp1);
					comp1++;
				}
				while (first != last) 
				{
					copy.push_back(*first);
					first++;
				}
				while (comp1 != finish)
				{
					copy.push_back(*comp1);
					comp1++;
				}
				_alloc.destroy(tab);
				*this = copy;
			}
			iterator erase (iterator position)
			{
				size_type i = 0;
				size_type j = 0;
				size_type len = 0;
				//ft::vector<value_type> copy;
				iterator comp = begin();
				iterator comp1 = end();
				T* temp;
				temp = _alloc.allocate(my_capacity);
				while (comp != position)
				{
					//copy.push_back(*comp);
					_alloc.construct(&temp[j], tab[i]);
					i++;
					j++;
					comp++;
				}
				len = i;
				i++;
				//comp++;
				while (comp != comp1)
				{
					//copy.push_back(*comp);
					_alloc.construct(&temp[j], tab[i]);
					j++;
					i++;
					comp++;
				}
				_alloc.destroy(tab);
				//_alloc.deallocate(tab, my_capacity);
				tab = temp;
				my_size--;
				//*this = copy;
				if (position == comp1)
					return iterator(tab + i);
				return iterator(tab + len);
			}
			iterator erase (iterator first, iterator last)
			{
				ft::vector<value_type> copy;
				size_type i = 0;
				//size_type j = 0;
				size_type len = 0;
				iterator comp = begin();
				iterator comp1 = end();
				//value_type save = *last;
				//std::cout << "LAST = " << save << "\n";
				//T* temp;
				//temp = _alloc.allocate(my_capacity);
				while (comp != first)
				{
					copy.push_back(*comp);
					//_alloc.construct(&temp[j], tab[i]);
					i++;
					//j++;
					comp++;
				}
				if (comp == end())
					return (end());
				len = i;
				while(comp != last)
				{
					comp++;
				}
				//std::cout << "COMP = " << *comp << "\n";
				//std::cout << "COMP1 = " << *comp1 << "\n";
				while (comp != comp1)
				{
					copy.push_back(*comp);
					//_alloc.construct(&temp[j], tab[*comp]);
					//j++;
					i++;
					comp++;
				}
				//_alloc.destroy(tab);
				//_alloc.deallocate(tab, my_capacity);
				//tab = temp;
				*this = copy;
				//my_size = i;
				//iterator p = begin();
			//	std::cout << "BEGIN = " << *p << "\n";
				/*while (*p != save || p != end())
				{
					j++;
				}*/
				return iterator(tab + len);
			}
			//###############################################################################
			reference operator[](size_type n)
			{
				return (tab[n]);
			}
			//###############################################################################
			const_reference operator[](size_t n) const
			  {
			  	return (tab[n]);
			  }
			vector& operator=(const vector &x)
			{
				clear();
				/*while (x.begin() != x.end())
				{
					push_back(*x.begin());
					x.begin()++;
				}*/
				//this->clear();
				if (this != &x)
				{
					assign(x.begin(), x.end());	
				}
				return (*this);
			}
			size_type size() const
			{
				return (my_size);
			}
			size_type capacity() const
			{
				return (my_capacity);
			}
			//###############################################################################
			void push_back(const value_type& val)
			{
				T* temp = NULL;
				if (my_size + 1 > my_capacity) 
				{
					if (my_capacity == 0)
						my_capacity += 1;
					if (tab)
					{
						temp = _alloc.allocate(2 * my_capacity);
						for (size_type i = 0; i < my_size; i++) 
						{
							_alloc.construct(&temp[i], tab[i]);
						}
						_alloc.destroy(tab);
						tab = temp;
						my_capacity *= 2;
					}
					else
					{
						tab = _alloc.allocate(1);
					}			
				}	
				_alloc.construct(tab + my_size, val);
				my_size++;
			}
			//###############################################################################
			void pop_back()
			{
				T* temp = _alloc.allocate(my_capacity);
				size_type i = 0;
				if (my_size)
				{
					while (i < my_size - 1)
					{
						_alloc.construct(&temp[i], tab[i]);
						i++;
					}
				}
				_alloc.destroy(tab);
				tab = temp;
				my_size--;
			}
			//###############################################################################
			void clear()
			{
				size_type i = my_size;
				while (i > 0)
				{
					_alloc.destroy(tab + i);
					i--;
				}
				my_size = 0;
			}
			void swap (vector& x)
			{
    			std::swap(tab, x.tab);
    			std::swap(my_capacity, x.my_capacity);
   				std::swap(my_size, x.my_size);
			}
			//###############################################################################
			reference at(size_type n) 
			{
				if(n >= my_size)
					throw std::out_of_range("");
				else
					return (tab[n]);
			}
			const_reference at(size_type n) const 
			{
				if(n >= my_size)
					throw std::out_of_range("");
				else
					return (tab[n]);
			}
			//###############################################################################
			void reserve(size_type new_cap)
			{
				if (new_cap > my_capacity)
				{
					T* temp = _alloc.allocate(new_cap);
					my_capacity = new_cap;
					if (my_size > 0) 
					{
						for (size_type i = 0; i < my_capacity; i++) 
						{
							_alloc.construct(temp + i, tab[i]);
						}
					}
					_alloc.destroy(tab);
					tab = temp;
				}
			}
			//###############################################################################
			void resize (size_type n, value_type val = value_type())
			{
				size_type i = 0;
				iterator it = end();
				iterator ite = begin();
				ite += n;
				if (n < my_size)
				{
					i = my_size - n;
					while (it != ite)
					{
						it--;
						i++;
						my_size--;
					}
				}
				else if (n > my_size && val >= 0)
				{
					int j = size();
					i = 0;
					while (i < (n - j))
					{
						push_back(val);
						i++;
					}
				}
				else if (n > my_size && n < my_capacity)
				{
					int j = size();
					i = 0;
					while (i < (n - j))
					{
						push_back(0);
						i++;
					}
				}
			}
			//###############################################################################
			bool empty() const
			{
				if (my_size == 0)
					return (true);
				else
					return (false);
			}
			//###############################################################################
			size_type max_size() const
			{
				size_type i;
				//avoir la plus grande valeur d'un size_t
				i = size_type(-1) / sizeof(value_type);
				return (i);
			}
			//###############################################################################
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			//###############################################################################
			void print()
			{
				for (size_type i = 0; i < my_size; i++) 
				{
					std::cout << tab[i] << " ";
				}
				std::cout << std::endl;
			}
			void print_const() const
			{
				for (size_type i = 0; i < my_size; i++) 
				{
					std::cout << tab[i] << " ";
				}
				std::cout << std::endl;
			}
			//###############################################################################
			~vector()
			{
				clear();
				_alloc.deallocate(tab, my_capacity);
				my_capacity = 0;
			};
			//###############################################################################
			
			//###############################################################################
		private:
			allocator_type	_alloc;
			size_type		my_size;
			size_type		my_capacity;
			T *				tab;
	};
	template <class T, class Alloc>
 	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		else
			return (false);
	}
	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}