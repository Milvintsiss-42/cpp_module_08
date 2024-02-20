/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/20 09:38:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

void print_int(int i)
{
	std::cout << i << " ";
}

void print_int_vector(std::vector<int> v)
{
	std::for_each(v.begin(), v.end(), &print_int);
	std::cout << std::endl;
}

int *rand_array(int size)
{
	int *array = new int[size]();

	for (int i = 0; i < size; i++)
		array[i] = rand();
	return array;
}

int	main(void)
{
	srand(time(NULL));
	Span sp = Span(8);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	int arr[3] = {41, 46, 120};
	std::vector<int> v_arr(arr, arr + 3);
	sp.addback_numbers_range(v_arr.begin(), v_arr.end());

	std::cout << "Basic span:" << std::endl;
	print_int_vector(sp.getNumbers());
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	try
	{
		std::cout << std::endl << "Overflow by range add:" << std::endl;
		Span overflow(4);

		int *arr_overflow = rand_array(4);
		std::vector<int> v_arr_overflow(arr_overflow, arr_overflow + 4);
		delete [] arr_overflow;

		overflow.addNumber(7);
		overflow.addback_numbers_range(
			v_arr_overflow.begin(), v_arr_overflow.end());
	}
	catch (Span::SizeOverflowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Overflow by number add:" << std::endl;
		Span overflow(4);

		int *arr_overflow = rand_array(4);
		std::vector<int> v_arr_overflow(arr_overflow, arr_overflow + 4);
		delete [] arr_overflow;

		overflow.addback_numbers_range(
			v_arr_overflow.begin(), v_arr_overflow.end());
		overflow.addNumber(7);
	}
	catch (Span::SizeOverflowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "NotEnoughElements Exception:" << std::endl;
		Span little(3);

		little.addNumber(7);
		little.longestSpan();
	}
	catch (Span::NotEnoughElementsException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "NotEnoughElements Exception:" << std::endl;
		Span little(3);

		little.shortestSpan();
	}
	catch (Span::NotEnoughElementsException &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span big_span = Span(20000);
	int *big_arr = rand_array(20000);
	std::vector<int> v_big_arr(big_arr, big_arr + 20000);
	delete [] big_arr;
	big_span.addback_numbers_range(v_big_arr.begin(), v_big_arr.end());
	std::cout << std::endl << "Big span:" << std::endl;
	// print_int_vector(big_span.getNumbers());
	std::cout << "shortest: " << big_span.shortestSpan() << std::endl;
	std::cout << "longest: " << big_span.longestSpan() << std::endl;
	return (0);
}
