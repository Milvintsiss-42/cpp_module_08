/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/19 20:03:41 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include "easyfind.hpp"

void print_int(int i)
{
	std::cout << i << " ";
}

int	main(void)
{
	int array[4] = {1337, 21, 42, 19};

	std::vector<int> v(array, array + 4);
	std::for_each(easyfind(v, 42), v.end(), &print_int);
	std::cout << std::endl;

	std::list<int> l(array, array + 4);
	std::for_each(easyfind(l, 21), l.end(), &print_int);
	std::cout << std::endl;

	std::deque<int> d(array, array + 4);
	std::for_each(easyfind(d, 1337), d.end(), &print_int);
	std::cout << std::endl;

	return (0);
}
