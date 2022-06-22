/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <pmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:28 by pmontiel          #+#    #+#             */
/*   Updated: 2022/03/17 16:46:23 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
//#include <stack>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
//#include <iostream>
/*#define TESTED_TYPE foo<int>
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;*/
void    is_empty(ft::vector<int> const &vct)
{
        std::cout << "is_empty: " << vct.empty() << std::endl;
}
void    checkErase(ft::vector<std::string> const &vct,
    ft::vector<std::string>::const_iterator const &it)
{
        static int i = 0;
		std::cout << "IT = " << *it << "\n";
       std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
        //printSize(vct);
}
void    checkErase1(std::vector<std::string> const &vct,
    std::vector<std::string>::const_iterator const &it)
{
        static int i = 0;
		std::cout << "IT 1 = " << *it << "\n";
       std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
        //printSize(vct);
}
void print_const(std::vector<std::string> const &res)
{
	for (size_t i = 0; i < res.size(); i++) 
	{
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
}
void    prepost_incdec(ft::vector<int> &vct)
{
        ft::vector<int>::iterator it = vct.begin();
        ft::vector<int>::iterator it_tmp;

        std::cout << "Pre inc" << std::endl;
        it_tmp = ++it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Pre dec" << std::endl;
        it_tmp = --it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post inc" << std::endl;
        it_tmp = it++;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post dec" << std::endl;
        it_tmp = it--;
        std::cout << *it_tmp << " | " << *it << std::endl;
        std::cout << "###############################################" << std::endl;
}
#define T1 int
#define T2 int
struct ft_more {
        bool    operator()(const T1 &first, const T1 &second) const {
                return (first > second);
        }
};

typedef ft::pair<const T1, T2> T3;

int main(void)
{
	/*std::list<T3> lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3(lst_size - i, i));

        ft::map<T1, T2> mp(lst.begin(), lst.end());
        std::cout << "\t-- MP AT START --" << std::endl;
		mp.print_tree();
        ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

        ft::map<T1, T2> mp_range(it, --(--ite));
        std::cout << "\t-- MP_RANGE AT START --" << std::endl;
		mp_range.print_tree();

		std::cout << "end() = "<< ite->first << " = " << ite->second << "\n";
        for (int i = 0; it != ite; ++it)
		{
			std::cout << "before = "<< it->first << " = " << it->second << "\n";
            it->second = ++i * 5;
			std::cout << "after = " << it->first << " = " << it->second << "\n";
		}
		std::cout << "\t-- MP AFTER FIRST MODIF --" << std::endl;
		mp.print_tree();
        it = mp.begin(); ite = --(--mp.end());
        ft::map<T1, T2> mp_copy(mp);
		std::cout << "\t-- MP_COPY FIRST --" << std::endl;
		mp_copy.print_tree();

        for (int i = 0; it != ite; ++it)
                it->second = ++i * 7;
		std::cout << "\t-- MP END --" << std::endl;
		mp.print_tree();
        std::cout << "\t-- PART ONE --" << std::endl;
       // printSize(mp);
       // printSize(mp_range);
       // printSize(mp_copy);

        std::cout << "\t-- MP --" << std::endl;
		mp.print_tree();
        std::cout << "\t-- RANGE --" << std::endl;
		mp_range.print_tree();
        std::cout << "\t-- COPY --" << std::endl;
		mp_copy.print_tree();

        mp = mp_copy;
        mp_copy = mp_range;
        mp_range.clear();

        std::cout << "\t-- PART TWO --" << std::endl;
//        printSize(mp);
  //      printSize(mp_range);
    //    printSize(mp_copy);
		while (1)
			;
        return (0);*/
 	/*	std::list<T3> lst;
        unsigned int lst_size = 6;
        for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
        ft::map<T1, T2> mp(lst.begin(), lst.end());

    std::cout << "\t-- MP 1--" << std::endl;
	mp.print_tree();
        for (int i = 2; i < 4; ++i)
                mp.erase(i);

    std::cout << "\t-- MP 2--" << std::endl;
	mp.print_tree();
        mp.erase(mp.begin()->first);
    std::cout << "\t-- MP 3--" << std::endl;
	mp.print_tree();
        mp.erase((--mp.end())->first);
    std::cout << "\t-- MP 4--" << std::endl;
	mp.print_tree();

        mp[-1] = "Hello";
        mp[10] = "Hi there";
        mp[10] = "Hi there";

    std::cout << "\t-- MP 5--" << std::endl;
	mp.print_tree();
        mp.erase(0);
    std::cout << "\t-- MP 6--" << std::endl;
	mp.print_tree();
        mp.erase(1);
    std::cout << "\t-- MP 7--" << std::endl;
	mp.print_tree();

        return (0);*/
	/*ft::map<int, int> mp;
    ft::map<int, int>::const_iterator it(mp.begin());
		(void)it;
        return (0);*/
	/*std::map<T1, T2, ft_more> m;
    m[0] = "AAAAAAAAAAAAA";
    m[1] = "BBBBBBBBBBB";
    m[2] = "CCCCCCCCC";
    m[3] = "DDDDDDDD";
    m[4] = "EEEEEE";
	m[5] = "FFFF";
	m[6] = "GGG";
	m[7] = "HH";
	m[8] = "I";
	std::map<int, std::string>::iterator re (--m.begin());
	re++;*/
	/*ft::map<int, std::string>::iterator ree (m.end());
	ft::map<int, std::string>::iterator yy (m.begin());
	std::cout << "RR BEGIN = " << re->first << " = " << re->second << "\n";
	std::cout << "END = " << ree->first << " = " << ree->second << "\n";*/
	//std::cout << "BEGIN = " << yy->first << " = " << yy->second << "\n";
	/*m.insert(ft::make_pair(4, "TCHUPPA"));
	ft::map<int, std::string> ft_mp;
    ft_mp[0] = "AAAAAAAAA";
    ft_mp[1] = "BBBBBBB";
  	ft_mp[2] = "CCCCCC";
    ft_mp[3] = "DDDDDD";
    ft_mp[4] = "EEEEE";
	ft::map<int, std::string>::iterator it = ft_mp.begin();
	ft::map<int, std::string>::iterator ite = ft_mp.end();
	//it++;
	//it++;
	std::cout << "POINTER BEGIN = " << it->first << " = " << it->second << "\n";
	ft_mp.erase(it);
	it = ft_mp.begin();
	for (;it != ite; it++)
	{
		std::cout << "_ " << it->first << " = " << it->second << "\n";
	}*/
/*	std::list<T3> lst;
        unsigned int lst_size = 10;
        for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
        ft::map<T1, T2> mp(lst.begin(), lst.end());
      //  printSize(mp);
		mp.print_tree();
    std::cout << "\t-- MP 1--" << std::endl;
        mp.erase(++mp.begin());

		mp.print_tree();
    std::cout << "\t-- MP 2--" << std::endl;
        mp.erase(mp.begin());
		mp.print_tree();
    std::cout << "\t-- MP 3--" << std::endl;
        mp.erase(--mp.end());
		mp.print_tree();
    std::cout << "\t-- MP 4--" << std::endl;

       mp.erase(mp.begin(), ++(++(++mp.begin())));
		mp.print_tree();
    std::cout << "\t-- MP 5--" << std::endl;
      	mp.erase(--(--(--mp.end())), --mp.end());
		mp.print_tree();
    std::cout << "\t-- MP 6--" << std::endl;

        mp[10] = "Hello";
        mp[11] = "Hi there";
		mp.print_tree();
    std::cout << "\t-- MP 7--" << std::endl;
	    mp.erase(--(--(--mp.end())), mp.end());
		mp.print_tree();
    std::cout << "\t-- MP 8--" << std::endl;

        mp[12] = "ONE";
        mp[13] = "TWO";
        mp[14] = "THREE";
        mp[15] = "FOUR";
		mp.print_tree();
    std::cout << "\t-- MP 9--" << std::endl;
        mp.erase(++mp.begin(), mp.end());
		mp.print_tree();
    std::cout << "\t-- MP 10--" << std::endl;*/
	/*std::list<T3> lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3(lst_size - i, i));
    ft::map<T1, T2> mp(lst.begin(), lst.end());
	mp.print_tree();
    std::cout << "\t-- MP --" << std::endl;
    ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	//std::cout << "\t-- MP END() --" << ite->first << " = " << ite->second <<std::endl;
	ft::map<T1, T2> mp_range(it, --(--ite));
    for (int i = 0; it != ite; ++it)
            it->second = ++i * 5;
	mp_range.print_tree();
    std::cout << "\t-- MP RANGE --" << std::endl;
    it = mp.begin(); ite = --(--mp.end());
	std::cout << "\t-- MP END() --" << ite->first << " = " << ite->second <<std::endl;
    ft::map<T1, T2> mp_copy(mp);
    for (int i = 0; it != ite; ++it)
        it->second = ++i * 7;
	mp_copy.print_tree();
    std::cout << "\t-- MP COPY --" << std::endl;
  //  printSize(mp);
  //  printSize(mp_range);
  //  printSize(mp_copy);
    mp = mp_copy;
	mp.print_tree();
    std::cout << "\t-- MP COPY --" << std::endl;
    mp_copy = mp_range;
	mp_copy.print_tree();
    mp_range.clear();
    std::cout << "\t-- PART TWO --" << std::endl;
   // printSize(mp);
   // printSize(mp_range);
   // printSize(mp_copy);
    return (0);*/
	//ft::map<char, char> zizi;
	//	ft::map<char, char> tutu;
	/*std::map<T1, T2> ft_mpp;
    ft_mpp[1] = 3;
    ft_mpp[2] = 6;
    ft_mpp[3] = 9;
    ft_mpp[4] = 12;
    ft_mpp[5] = 15;
	ft_mpp[6] = 18;
	ft_mpp[7] = 21;
	ft_mpp[8] = 24;
	ft_mpp[9] = 27;
	ft_mpp[10] = 30;*/
	//ft_mpp.print_tree();
/*	std::map<T1, T2>::const_iterator it = ft_mpp.begin();
	std::map<T1, T2>::const_iterator ite = ft_mpp.end();
	std::cout << "POINTER END = " << ite->first << " = " << ite->second << "\n";
	while (it != ite)
	{
		std::cout << "_ " << it->first << " = " << it->second << "\n";
		it++;
	}
	ft_mpp.erase(10);
	std::map<T1, T2>::const_iterator it = ft_mpp.begin();
	std::map<T1, T2>::const_iterator ite = ft_mpp.end();
	std::cout << "POINTER END = " << ite->first << " = " << ite->second << "\n";
	while (it != ite)
	{
		std::cout << "_ " << it->first << " = " << it->second << "\n";
		it++;
	}*/
    std::cout << "###############################################" << std::endl;
	ft::map<int, int> ft_mp;
    ft_mp[50] = 3;
    ft_mp[2] = 6;
  	ft_mp[1] = 9;
    ft_mp[4] = 12;
    ft_mp[200] = 15;
	ft_mp[6] = 18;
	ft_mp[100] = 21;
	ft_mp[8] = 24;
	ft_mp[999] = 27;
	ft_mp[10] = 30;
	ft_mp.insert(ft::make_pair(8, 10));
	ft_mp.insert(ft::make_pair(4, 80));
	ft_mp.insert(ft::make_pair(1, 70));
	ft_mp.insert(ft::make_pair(9, 50));
	ft_mp.insert(ft::make_pair(2, 40));
	ft_mp.insert(ft::make_pair(78, 880));
	ft_mp.find(100);
//	ft_mp.print_tree();
	/*ft::map<T1, T2>::iterator itt = ft_mp.begin();
	ft::map<T1, T2>::iterator itee = ft_mp.end();
	std::cout << "POINTER BEGIN = " << itt->first << " = " << itt->second << "\n";
	std::cout << "POINTER END = " << itee->first << " = " << itee->second << "\n";
	for (;itt != itee; itt++)
	{
		std::cout << "_ " << itt->first << " = " << itt->second << "\n";
	}*/
	/*ft::map<int, int>::iterator yy = ft_mp.begin();
	ft::map<int, int>::iterator ee = ft_mp.end();
	ft_mp.erase(yy);
	ft::map<int, int>::iterator itt = ft_mp.begin();
	ft::map<int, int>::iterator itee = ft_mp.end();
	std::cout << "POINTER BEGIN = " << itt->first << " = " << itt->second << "\n";
	std::cout << "POINTER END = " << itee->first << " = " << itee->second << "\n";
	for (;itt != itee; itt++)
	{
		std::cout << "_ " << itt->first << " = " << itt->second << "\n";
	}*/
	//ft_mp.print_tree();
	/*
  std::cout << "###############################################" << std::endl;
	ft::map<T1, T2> mp(ft_mp.begin(), ft_mp.end());
	ft::map<T1, T2>::iterator it = mp.begin();
	ft::map<T1, T2>::iterator ite = mp.end();
	std::cout << "POINTER BEGIN = " << it->first << " = " << it->second << "\n";
	std::cout << "POINTER END = " << ite->first << " = " << ite->second << "\n";
	for (;it != ite; it++)
	{
		std::cout << "_ " << it->first << " = " << it->second << "\n";
	}
    std::cout << "###############################################" << std::endl;
	it = mp.begin();
	i``te = mp.end();
	ft::map<T1, T2> range (it, --ite);
	std::cout << "POINTER BEGIN = " << it->first << " = " << it->second << "\n";
	std::cout << "POINTER END = " << ite->first << " = " << ite->second << "\n";
	for (;it != ite; it++)
	{
		std::cout << "_ " << it->first << " = " << it->second << "\n";
	}*/
	//ft_mp_it = ft_mp.lower_bound(10);
//	std::cout << "lower = " << ft_mp_it->first << " = " << ft_mp_it->second << "\n";
//	std::cout << "##########" << "\n";
/*	ft::map<T1, T2, ft::less<T1> > ft_mp;
    ft_mp[0] = "AAAAAAAAAAAAA";
    ft_mp[1] = "BBBBBBBBBBB";
    ft_mp[2] = "CCCCCCCCC";
    ft_mp[3] = "DDDDDDDD";
    ft_mp[4] = "EEEEEE";
	ft_mp[5] = "FFFF";
	ft_mp[6] = "GGG";
	ft_mp[7] = "HH";
	ft_mp[8] = "I";
	ft::map<T1, T2, ft_more>::iterator ft_mp_it = ft_mp.begin();
	ft::map<T1, T2, ft_more>::iterator ft_mp_ite = ft_mp.end();
	std::cout << "BEGIN = " << ft_mp_it->first << " = " << ft_mp_it->second << "\n";
	std::cout << "END = " << ft_mp_ite->first << " = " << ft_mp_ite->second << "\n";
	//(--(--(--ft_mp_it)));
	//std::cout << "END = " << ft_mp_it->first << "\n";
	ft_mp.print_tree();
	ft_mp.erase(++ft_mp.begin());
	std::cout << "END = " << ft_mp_it->first << " = " << ft_mp_it->second << "\n";
	std::cout << "##########" << "\n";
	ft_mp.print_tree();
	std::cout << "##########" << "\n";
	ft_mp.erase(++(++ft_mp.begin()));
	std::cout << "END = " << ft_mp_it->first << " = " << ft_mp_it->second << "\n";
	ft_mp.print_tree();
	std::cout << "##########" << "\n";*/
	//ft_mp.print_tree();
	/*std::map<T1, T2, ft::more<T1> > ft_mp;
    ft_mp[42] = 10;
    ft_mp[27] = 1;
    ft_mp[80] = 5;
    ft_mp[12] = 9;
	ft_mp[25] = 200;*/
	//ft_mp.print_tree();
	//std:: cout << ft_mp.max_size() << "\n";
	//ft::map<T1, T2, ft_more>::iterator ft_mp_it = ft_mp.begin();
	//(++(++ft_mp_it));
	/*std::cout << "FIRST" << ft_mp_it->first << "\n";
	std::cout << "COUNT2" << "\n";
	std::cout << "COUNT3" << "\n";
	std::cout << "COUNT4" << "\n";
	std::cout << "COUNT5" << "\n";
    ft_mp[27] = "bee";
	std::cout << "COUNT6" << "\n";
    ft_mp[90] = "8";
	std::cout << "COUNT7" << "\n";
	return (0);*/
	/*zizi.insert(ft::pair<const char, char>('i','j'));
	zizi.insert(ft::pair<const char, char>('c','h'));
	zizi.insert(ft::pair<const char, char>('f','h'));
	zizi.insert(ft::pair<const char, char>('b','x'));
	zizi.insert(ft::pair<const char, char>('a','s'));
	zizi.insert(ft::pair<const char, char>('u','p'));
	zizi.insert(ft::pair<const char, char>('z','d'));
	zizi.insert(ft::pair<const char, char>('w','k'));
	zizi.insert(ft::pair<const char, char>('y','m'));
	zizi.insert(ft::pair<const char, char>('q','v'));
	ft::map<char,char>::iterator it = zizi.begin();
	ft::map<char,char>::iterator ite = zizi.end();
	ft::map<char,char>::reverse_iterator rit(it);
	std::cout << "FIRST = " << rit->first << " = ";
	std::cout << rit->second << '\n';*/
	//tutu = zizi;
	//ft::map<char,char>::const_iterator it = zizi.begin();
	//ft::map<char,char>::const_reverse_iterator ite = zizi.rbegin();
	//tutu.insert(it, ite);
	//it = zizi.insert(ite, std::pair<const char, char>('t','n'));
	//std::cout << "FIRST = " << it->first << " = ";
	//std::cout << it->second << '\n';
	//std::cout << "FIRST = " << ite->first << " = ";
	//std::cout << ite->second << '\n';
	//ft::map<char, char> kiki (zizi.begin(), zizi.end());
	//zizi.print_tree();
	//std::cout << "##########" << "\n";
	//ft_mp.print_tree();
	//tutu.print_tree();
	/*zizi.clear();
	std::cout << "##########" << "\n";
	zizi.print_tree();*/
	//std::cout << "zizi['a'] is " << zizi['a'] << '\n';
	//std::cout << "kiki['a'] is " << kiki['a'] << '\n';
	//zizi['l']='t';
	//std::cout << zizi.size() << "\n";
	//std::cout << "COUNT = " << zizi.count('c') << "\n";
	//std::cout << "EMPTY = " << zizi.empty() << "\n";
	//ft::map<char, int>::node_pointer it;
	//ft::map<char, int>::node_pointer ite;
	//it = zizi.creat_node(ft::make_pair('c', 5));
	//ite = zizi.creat_node(ft::make_pair('a', 10));
	/*ft::map<char,char>::iterator it = zizi.begin();
	ft::map<char,char>::iterator ite = zizi.end();
	//ft::map<char, int> key_type = zizi->first;
	std::cout << "### BEGIN ###" << "\n";
	std::cout << (*it).first << " = ";
	std::cout << (*it).second << "\n";
	std::cout << "### END ###" << "\n";
	std::cout << (*ite).first << " = ";
	std::cout << (*ite).second << "\n";
	std::cout << "##########" << "\n";*/
	//std::pair<char,int> highest = *zizi.begin(); 
	//tutu.swap(zizi);
	//zizi.print_tree();
	//tutu.print_tree();
/*	ft::map<char,char>::iterator it = zizi.lower_bound('o');
	std::cout <<  "LOWER = " << it->first << " = ";
	std::cout << it->second << "\n";*/
	/*ft::map<char,char>::iterator it = zizi.upper_bound('c');
	std::cout <<  "UPPER = " << it->first << " = ";
	std::cout << it->second << "\n";
	std::cout << "##########" << "\n";*/
	/*zizi.print_tree();
	ft::map<char,char>::iterator it = zizi.begin();
	ft::map<char,char>::iterator ite = zizi.end();
	it++;
	ite--;		
	zizi.erase(it, ite);
	std::cout << "##########" << "\n";
	zizi.print_tree();*/
	/*std::cout << ite->first << " = ";
	while (it != ite)
	{	
		std::cout << it->first << " = ";
		std::cout << it->second << "\n";
		it++;		
	}*/
	/*std::cout << " BEGIN " << it->first << " = ";
	std::cout << it->second << "\n";
	it++;
	std::cout << " ++ " << it->first << " = ";
	std::cout << it->second << "\n";
	it++;
	std::cout << " ++ " << it->first << " = ";
	std::cout << it->second << "\n";
	it++;
	std::cout << " ++ " << it->first << " = ";
	std::cout << it->second << "\n";
	it++;
	std::cout << " ++ " << it->first << " = ";
	std::cout << it->second << "\n";
	it++;
	std::cout << " ++ " << it->first << " = ";
	std::cout << it->second << "\n";*/
	//zizi.clear();
	/*zizi.print_tree();
	std::cout << "##########" << "\n";
	ft::map<char,char>::iterator it = zizi.end();
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	it--;
	std::cout << "IT = " << it->first << "\n";
	zizi.erase(it);
	zizi.print_tree();
	std::cout << "##########" << "\n";*/
	/*std::cout << "##########" << "\n";
	find = zizi.find('c');
	std::cout << find->first << "\n";
	std::cout << "##########" << "\n";
	std::cout << find->second << "\n";
	std::cout << "##########" << "\n";
	std::cout << "Max Size = " << zizi.max_size() << "\n";*/
//	std::cout << it->second << " = ";
	/*std::cout << it->value.first << " = ";
	std::cout << it->value.second << "\n";
	std::cout << ite->value.first << " = ";
	std::cout << ite->value.second << "\n";*/
	//std::cout << zizi << "\n";
	//zizi['a'] = 10;
	//zizi['b'] = 20;
	//zizi.btree_apply_prefix(it);

	//######### ASSIGN TEST ##############
	/*std::vector<int> vct(7);
	std::vector<int>::const_iterator ite = vct.end();
	std::vector<int>::iterator it(ite);
    std::cout << *it << std::endl;*/
 /*   ft::vector<int> vct_two(4);
    ft::vector<int> vct_three;
    ft::vector<int> vct_four;
    for (unsigned long int i = 0; i < vct.size(); ++i)
         vct[i] = (vct.size() - i) * 3;
    std::cout << "VTC Start" << std::endl;
	vct.print();
    for (unsigned long int i = 0; i < vct_two.size(); ++i)
    	 vct_two[i] = (vct_two.size() - i) * 5;
    std::cout << "VTC TWO Start" << std::endl;
	vct_two.print();
    std::cout << "VTC THREE Start" << std::endl;
	vct_three.print();
    std::cout << "VTC FOUR Start" << std::endl;
	vct_four.print();
    //printSize(vct);
    //printSize(vct_two);
    vct_three.assign(vct.begin(), vct.end());
    std::cout << "VTC THREE 1er Ass" << std::endl;
	vct_three.print();
    vct.assign(vct_two.begin(), vct_two.end());
    std::cout << "VTC 1er Ass" << std::endl;
	vct.print();
    vct_two.assign(2, 42);
    std::cout << "VTC TWO 1er ASS" << std::endl;
	vct_two.print();
    vct_four.assign(4, 21);
    std::cout << "VTC FOUR 1er ASS" << std::endl;
	vct_four.print();
    std::cout << "\t### After assign(): ###" << std::endl;
//    printSize(vct);
  //  printSize(vct_two);
    //printSize(vct_three);        
//	printSize(vct_four);
    vct_four.assign(6, 84);
 //   printSize(vct_four);
    std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;
    vct.assign(5, 53);
    vct_two.assign(vct_three.begin(), vct_three.begin() + 3);
  //  printSize(vct);
  //  printSize(vct_two);
	//po.print1();
	vct.print();
	vct_three.print();
	vct_two.print();
	vct_four.print();
	//######### ASSIGN TEST END ##############
*/
	//######### AT TEST ##############
	/*ft::vector<int> vct(7);
    for (unsigned long int i = 0; i < vct.size(); ++i)
    {
    	vct.at(i) = (vct.size() - i) * 3;
        std::cout << "vct.at(): " << vct.at(i) << " | ";
        std::cout << "vct[]: " << vct[i] << std::endl;
    }
    vct.print();
	ft::vector<int> const vct_c(vct);
    vct_c.print_const();
    std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
    std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;
    try {
        vct.at(10) = 42;
    }
    catch (std::out_of_range &e) {
        std::cout << "Catch out_of_range exception!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Catch exception: " << e.what() << std::endl;
    }
	return (0);
	//######### AT TEST END ##############
*/
	//######### COPY CONSTRUCT TEST ##############
	/*ft::vector<int> vct(5);
	ft::vector<int>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	ft::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	ft::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	vct.print();
	vct_range.print();
	vct_copy.print();

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	vct.print();
	vct_range.print();
	vct_copy.print();
	return (0);

	//######### COPY CONSTRUCT TEST END ##############
*/
	//######### ERASE TEST ##############

	/*	ft::vector<std::string> vct(10);
		std::vector<std::string> vct1(10);

        for (unsigned long int i = 0; i < vct.size(); ++i)
            vct[i] = std::string((vct.size() - i), i + 65);
		for (unsigned long int i = 0; i < vct1.size(); ++i)
            vct1[i] = std::string((vct1.size() - i), i + 65);
        vct.print();
		std::cout << "################" << "\n";
        print_const(vct1);*/
	//	std::cout << "size vct = " << vct.size() << "\n";
	//	std::cout << "size vct1 = " << vct1.size() << "\n";
        //checkErase(vct, vct.erase(vct.begin() + 2));
        //checkErase1(vct1, vct1.erase(vct1.begin() + 2));
//        vct.print();
	//	std::cout << "SIZE 1 = " << vct.size() << "\n";
	//	std::cout << "################" << "\n";
  //      print_const(vct1);

//        checkErase(vct, vct.erase(vct.begin()));
//       checkErase1(vct1, vct1.erase(vct1.begin()));
//        vct.print();
	//	std::cout << "SIZE 2 = " << vct.size() << "\n";
		//std::cout << "################" << "\n";
//        print_const(vct1);
		//ft::vector<std::string>::iterator ite = vct.end() - 1;
		//ft::vector<std::string>::iterator p = vct.end();
		//std::cout << "end - 1 = " << *ite << "\n";
		//while (1)
		//	;
		//std::cout << "end = " << *p << "\n";
       /*checkErase(vct, vct.erase(vct.end() - 1));
        checkErase1(vct1, vct1.erase(vct1.end() - 1));
        vct.print();
	//	std::cout << "SIZE 3 = " << vct.size() << "\n";
		std::cout << "################" << "\n";
        print_const(vct1);
        print_const(vct1);
		checkErase(vct, vct.erase(vct.end() - 4));
		checkErase1(vct1, vct1.erase(vct1.end() - 4));
        vct.print();
		std::cout << "################" << "\n";
        print_const(vct1);*/

        /*checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
        checkErase1(vct1, vct1.erase(vct1.begin(), vct1.begin() + 3));
        vct.print();
	//	std::cout << "SIZE 4 = " << vct.size() << "\n";
		std::cout << "#######uuuuuu#########" << "\n";
        print_const(vct1);
		//ft::vector<std::string>::iterator ite = vct.end() - 1;
		//std::vector<std::string>::iterator p = vct1.end() - 1;
		//std::cout << "end - 1 = " << *ite << "\n";
		//std::cout << "end - 1 = " << *p << "\n";
        checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));
       	checkErase1(vct1, vct1.erase(vct1.end() - 3, vct1.end() - 1));
        vct.print();
	//	std::cout << "SIZE 5 = " << vct.size() << "\n";
		std::cout << "#######iiii######" << "\n";
        print_const(vct1);*/

       // vct.push_back("Hello");
      //  vct1.push_back("Hello");
      //  vct.push_back("Hi there");
      //  vct1.push_back("Hi there");
      //  vct.print();
	//	std::cout << "SIZE 6 = " << vct.size() << "\n";
	//	std::cout << "################" << "\n";
      // print_const(vct1);
      /*  checkErase(vct, vct.erase(vct.end() - 3, vct.end()));
        checkErase1(vct1, vct1.erase(vct1.end() - 3, vct1.end()));
        vct.print();
	//	std::cout << "SIZE 7 = " << vct.size() << "\n";
		std::cout << "################" << "\n";
        print_const(vct1);

        vct.push_back("ONE");
        vct1.push_back("ONE");
        vct.push_back("TWO");
        vct1.push_back("TWO");
        vct.push_back("THREE");
        vct1.push_back("THREE");
        vct.push_back("FOUR");
     vct1.push_back("FOUR");
        vct.print();
	//	std::cout << "SIZE 8 = " << vct.size() << "\n";
		std::cout << "################" << "\n";
        print_const(vct1);

        checkErase(vct, vct.erase(vct.begin(), vct.end() - 1));
        checkErase1(vct1, vct1.erase(vct1.begin(), vct1.end() - 1));
        vct.print();
	//	std::cout << "SIZE 9 = " << vct.size() << "\n";
		std::cout << "################" << "\n";
        print_const(vct1);
        return (0);*/
	//######### ERASE TEST END ##############*/

	//######### ITE TEST ##############*/
	/*	const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::iterator it = vct.begin();
        ft::vector<int>::const_iterator ite = vct.begin();

        for (int i = 0; i < size; ++i)
                it[i] = (size - i) * 5;
        prepost_incdec(vct);
		vct.print();
        it = it + 5;
        //std::cout << *it << std::endl;
        it = 1 + it;
        it = it - 4;
        //std::cout << *it << std::endl;
        std::cout << *(it += 2) << std::endl;
        //std::cout << *it << std::endl;
        std::cout << *(it -= 1) << std::endl;
        //std::cout << *it << std::endl;

        *(it -= 2) = 42;
        *(it += 2) = 21;
		//vct.print();
        //std::cout << *it << std::endl;

        std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
        std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

//        std::cout << *it << std::endl;
  //      std::cout << *ite << std::endl;
        std::cout << "(it == const_it): " << (ite == it) << std::endl;
    //    std::cout << *ite << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

        //printSize(vct, true);
        return (0);
*/
	//######### ITE TEST END ##############*/

	//######### ITE ARROW TEST ##############*/

		/*const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::iterator it(vct.begin());
        ft::vector<int>::const_iterator ite(vct.end());

        for (int i = 1; it != ite; ++i)
                *it++ = i;
        //printSize(vct, 1);
		vct.print();
        it = vct.begin();
        ite = vct.begin();
        std::cout << *ite << "\n";
        std::cout << *ite << "\n";
        std::cout << "#############" << "\n";
        std::cout << *(++ite) << "\n";
        std::cout << *(ite++) << std::endl;
        std::cout << "#############" << "\n";
        std::cout << *ite++ << std::endl;
        std::cout << *++ite << std::endl;
        std::cout << "#############" << "\n";

        it->m();
        ite->m();

        std::cout << *(++it) << std::endl;
        std::cout << *(it++) << std::endl;
        std::cout << "#############" << "\n";
        std::cout << *it++ << std::endl;
        std::cout << *++it << std::endl;
        std::cout << "#############" << "\n";
        std::cout << *(--ite) << std::endl;
        std::cout << *(ite--) << std::endl;
        std::cout << "#############" << "\n";
        std::cout << *--ite << std::endl;
        std::cout << *ite-- << std::endl;
        std::cout << "#############" << "\n";

        (*it).m();
        (*ite).m();

        std::cout << "#############" << "\n";
        std::cout << *(--it) << std::endl;
        std::cout << *(it--) << std::endl;
        std::cout << "#############" << "\n";
        std::cout << *it-- << std::endl;
        std::cout << *--it << std::endl;
        std::cout << "#############" << "\n";

        return (0);
*/
	//######### ITE ARROW TEST END##############*/

	//######### RITE TEST##############*/
	/*	const int size = 5;
       	ft::vector<int> vct(size);
       	std::vector<int> vct1(size);
		ft::vector<int>::reverse_iterator it = vct.rbegin();
		std::vector<int>::reverse_iterator it1 = vct1.rbegin();
        ft::vector<int>::const_reverse_iterator ite = vct.rbegin();
        //std::vector<int>::const_reverse_iterator ite1 = vct1.rbegin();
        for (int i = 0; i < size; ++i)
                it[i] = ((size - i) * 5);
		for (int i = 0; i < size; ++i)
                it1[i] = ((size - i) * 5);
		vct.print();
        std::cout << "FT 1 = ";
        std::cout << *it << std::endl;
        std::cout << "STD 1 = ";
        std::cout << *it1 << std::endl;
        it = it + 5;
        it1 = it1 + 5;
        std::cout << "FT 2 = ";
        std::cout << *it << std::endl;
        std::cout << "STD 2 = ";
        std::cout << *it1 << std::endl;
        it = 1 + it;
        it1 = 1 + it1;
        std::cout << "FT 3 = ";
        std::cout << *it << std::endl;
        std::cout << "STD 3 = ";
        std::cout << *it1 << std::endl;
        it = it - 4;
        it1 = it1 - 4;
        std::cout << "FT 4 = ";
        std::cout << *it << std::endl;
        std::cout << "STD 4 = ";
        std::cout << *it1 << std::endl;
        std::cout << *(it += 2) << std::endl;
        std::cout << *(it -= 1) << std::endl;

		vct.print();
        std::cout << *it << std::endl;
        *(it -= 2) = 42;
        *(it += 2) = 21;

		vct.print();
        std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

        std::cout << "(it == const_it): " << (ite == it) << std::endl;
        std::cout << *it << std::endl;
        std::cout << *ite << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

//        printSize(vct, true);
        return (0);*/
	//######### RITE TEST END##############*/


       /* ft::vector<int>  ctnr;

        ctnr.push_back(21);
        ctnr.push_back(42);
        ctnr.push_back(1337);
        ctnr.push_back(19);
        ctnr.push_back(0);
        ctnr.push_back(183792);
        ft::stack<int> stck(ctnr);

        stck.push(1);
        stck.push(2);
        stck.push(3);
        stck.push(4);
        stck.push(5);
        stck.push(6);

		stck.print1();
        std::cout << "Added some elements" << std::endl;

        std::cout << "empty: " << stck.empty() << std::endl;

        return (0);*/
	//######### PUSH POP TEST ##############*/
	/*	ft::vector<std::string> vct;
		vct.print();
        //ft::vector<std::string> vct2;
		//std::string t = "salur";
        //ft::vector<std::string>::iterator it = vct.begin();
		//size_t i = 0;
		std::cout << "SIZE VCT = " << vct.size() << "\n";
		//std::cout << "SIZE VCT2 = " << vct2.size() << "\n";
		std::cout << "CAPACITY VCT = " << vct.capacity() << "\n";
		//std::cout << "CAPACITY VCT2 = " << vct2.capacity() << "\n";
        while (it != vct.end() - 1)
		{
            *it = std::string((vct.size() - i), i + 65);
			it++;
			i++;
		}

		vct.print();
//		vct.print();
		std::cout << "#####################" << "\n";
  //      vct.push_back("One long string");
        vct.push_back("One long string");
       // vct2.push_back("Another long string");
		//vct.print();
		vct.print();
		//vct2.print();

    //	vct.pop_back();
	//	vct.print();
   // 	vct2.pop_back();
//		vct2.print();
 //  		vct.pop_back();
	//	vct.print();
   //    	vct2.pop_back();
     //   vct2.print();
        return (0);
*/
	//######### PUSH POP TEST END##############

	//######### SIZE TEST ##############

		/*const int start_size = 7;
        ft::vector<int> vct(start_size, 20);
		vct.print();
        ft::vector<int> vct2;
        ft::vector<int>::iterator it = vct.begin();

        for (int i = 2; i < start_size; ++i)
            it[i] = (start_size - i) * 3;
       // printSize(vct, true);
		//std::cout << "PROUTE" << "\n";
		vct.print();
		//vct2.print();
        std::cout << "WWWWWWWWW" << std::endl;
        vct.resize(10, 42);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
//        printSize(vct, true);
		vct.resize(2, 42);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
        vct.resize(18, 43);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
//        printSize(vct, true);
        vct.resize(10);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
  //      printSize(vct, true);
        vct.resize(23, 44);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
    //    printSize(vct, true);
        vct.resize(5);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
      //  printSize(vct, true);
        vct.reserve(5);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
        vct.reserve(3);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
      //  printSize(vct, true);
        vct.resize(87);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
        vct.resize(5);
		vct.print();
        std::cout << "WWWWWWWWW" << std::endl;
//        printSize(vct, true);

        is_empty(vct2);
        vct2 = vct;
		vct.print();
        is_empty(vct2);
        vct.reserve(vct.capacity() + 1);
//        printSize(vct, true);
  //      printSize(vct2, true);

        vct2.resize(0);
        is_empty(vct2);
//        printSize(vct2, true);
        return (0);*/
	//######### SIZE TEST END ##############

	//######### INSERT TEST ##############*/
		/*ft::vector<int> vct(10);
        ft::vector<int> vct2;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
        vct.print();
		
		vct2.insert(vct2.end(), 42);
        vct2.print();
        vct2.insert(vct2.begin(), 2, 21);
        vct2.print();

        vct2.insert(vct2.end() - 2, 42);
        vct2.print();

        vct2.insert(vct2.end(), 2, 84);
        vct2.print();

        vct2.resize(4);
        vct2.print();

        vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
        vct2.print();
        vct.clear();
        return (0);*/
	//######### INSERT TEST END ##############*/

	/*ft::vector<pair<int, string>> vec1 = {{12, "twelve"},
                                      		{32, "thirty-two"},
                                      		{43, "forty-three"}};*/
	//	std::cout << "char: " << ft::is_integral<float>::value << std::endl;
	//	ft::vector<int> tab;
	//	tab.push_back(2);
	//	tab.print();
	/*	ft::vector<int> tab2(5, 100);
	ft::vector<int> tab1;
	std::vector<int> tab;
	std::vector<int> tab3(5, 100);
	ft::vector<int>::const_iterator const it = tab1.begin();
	ft::vector<int>::const_iterator const last = tab1.end();
	//std::cout << "IT = " << *it + *last << "\n";
	//tab2.print();
	//tab1 = tab2;
	//tab1.print();
	tab1.assign(tab2.begin(), tab2.end());
	tab.assign(tab3.begin(), tab3.end());
	tab1.erase(it);
tSize(vctt << "FT VECTOR OUTPUT " << "\n";
	tab1.print();
	std::vector<int>::iterator ptr = tab.begin();
	std::cout << "STL VECTOR OUTPUT " << "\n";
	while (ptr != tab.end())
	{
		std::cout << *ptr << " ";
		ptr++;
	}
	ft::vector<int> tab2(5, 100);
	ft::stack<int> s;
	ft::stack<int> s2;
		ft::stack<int, ft::vector<int> > s (tab2);
	ft::stack<int,ft::vector<int> > s;
	s.push(5);
	s.push(100);
	s.push(80);
	s.push(50);
	s.print1();
		s.pop();
	s.print1();
	const size_t len = s.size();
	std::cout << "SIZE OF S = " << len << "\n";
	std::cout << "TOP = " << s.top() << "\n";
	s2 = s;
	s2.print1();
	ft::stack<int> s2;
	s.pop();
		ft::stack<int, ft::vector<int> > one (tab2);
	ft::vector<int> tab3(tab2.begin(), tab2.end());
	tab2.print();
	tab3.print();
	ft::vector<int> vec1;
	std::cout << "BBBB" << "\n";
	vec1.push_back(2);
	vec1.push_back(8);
	vec1.push_back(77);
	vec1.push_back(55);
	ft::vector<int> vec2;
	std::cout << "CCCC" << "\n";
 	vec2.insert(vec2.begin(), vec1.begin(), vec1.end());
	std::cout << "DDDD" << "\n";
	vec1.print();
	vec2.print();
	int *p;
	p = tab.get_allocator().allocate(5);
	ft::vector<int> tab1(3, 100);
	ft::vector<int> tab2(5, 200);
	std::cout << "tab1 ";
	tab1.print();
	std::cout << "tab2 ";
	tab2.print();
	tab1.swap(tab2);
	std::cout << "#########" << "\n";
	std::cout << "tab1 ";
	tab1.print();
	std::cout << "tab2 ";
	tab2.print();
	tab1.push_back(100);
	tab1.push_back(300);
	tab1.push_back(200);
	tab.push_back(2);
	tab.push_back(8);
	tab.push_back(77);
	tab.push_back(55);
	tab.push_back(99);
	tab.push_back(1);
	tab.push_back(7);
	tab.print();
	ft::vector<int>::iterator ptr = tab.begin();
	std::cout << "ptr = " << *ptr << "\n";
	ft::vector<int>::iterator rev = tab.rbegin();
	ft::vector<int>::iterator rev1 = tab.rend();
	ft::vector<int>::iterator ptr1 = tab1.begin();
	std::cout << "rev1 = " << *rev1 << "\n";
	std::cout << "rev = " << *rev << "\n";
	ptr1++;
	ptr1++;
 	tab1.insert(ptr1, tab.begin(), tab.end());
	tab1.print();
	tab.print();
	std::cout << tab.at(1) << "\n";
	std::cout << tab.front() << "\n";
	std::cout << tab.back() << "\n";
	tab.print();
	tab.assign(tab1.begin(), tab1.end());
	tab.print();
   std::cout << "I = " << i << std::endl;
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator ptr2 = tab.end();
	ptr++;
	tab.insert(ptr, 4, 500);
	std::cout << "PTR = " << *ptr << "\n";
	ptr = tab.insert(ptr, 300);
	tab.print();
	ft::vector<int>::iterator ptr2 = tab.begin();
	ft::vector<int>::iterator ptr3 = tab.end();
	const size_t capacity2 = tab.capacity();
	const size_t size1 = tab.size();
	std::cout << "SIZE : " << (int)size1 << "\n";
	std::cout << "CAPACITY : " << (int)capacity2 << "\n";
	ptr2++;
	tab.erase(ptr2);
	tab.erase(ptr2, ptr3);
	tab.print();
	ptr++;
    std::cout << "premiere valeur " << *ptr << std::endl;
    std::cout << "derniere valeur " << *ptr2 << std::endl;
 	std::cout << "The vector elements are : ";
    for (it = tab2.begin(); it < tab2.end(); it++)
        std::cout << *it << " ";
	tab1.max_size();
	tab2.print();
	
	tab2.pop_back();
	tab1.push_back(100);
	tab2.resize(12, 4);
	tab1.print();
	while (!tab2.empty())
  	{
     	tab2.pop_back();
		tab2.print();
 	}
	tab2.pop_back();
	tab2.print();
	tab2.clear();
	tab2.print();
	tab1.push_back(50);
	tab1.push_back(10);
	tab1.push_back(56);
	tab.push_back(5);
	const size_t size = tab2.size();
	const size_t capacity = tab2.capacity();
	std::cout << "SIZE : " << (int)size << "\n";
	std::cout << "CAPACITY : " << (int)capacity << "\n";
	tab.reserve(20);
	tab.print();
	tab.pop_back();
	tab.print();
	const size_t size1 = tab.size();
	const size_t capacity1 = tab.capacity();
	std::cout << "SIZE : " << (int)size1 << "\n";
	std::cout << "CAPACITY : " << (int)capacity1 << "\n";
	int i = tab.at(0);
	printf("%d\n", i);
	return (0);*/
}