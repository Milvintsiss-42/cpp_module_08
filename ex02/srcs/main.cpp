/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/22 04:06:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "With MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout <<  "Size: " << mstack.size() << std::endl << std::endl;
	mstack.pop();
	std::cout <<  "Size: " << mstack.size() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	it = mstack.begin();
	while (it != ite)
	{
		(*it)++;
		++it;
	}
	it = mstack.begin();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl;


	std::cout << "With list:" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	std::cout << "Top: " << mlist.back() << std::endl;
	mlist.push_back(17);
	std::cout << "Top: " << mlist.back() << std::endl;
	std::cout <<  "Size: " << mlist.size() << std::endl << std::endl;
	mlist.pop_back();
	std::cout <<  "Size: " << mlist.size() << std::endl << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator l_it = mlist.begin();
	std::list<int>::iterator l_ite = mlist.end();
	++l_it;
	--l_it;
	while (l_it != l_ite)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}

	l_it = mlist.begin();
	while (l_it != l_ite)
	{
		(*l_it)++;
		++l_it;
	}
	l_it = mlist.begin();
	while (l_it != l_ite)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}
	return 0;
}
