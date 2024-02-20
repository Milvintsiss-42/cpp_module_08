/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:20 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/20 09:01:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

class Span {
private:
	unsigned int _maxSize;

	// We could also use Set container here to not duplicate numbers
	std::vector<int> _numbers;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	~Span();

	std::vector<int> &getNumbers();

	void addNumber(int number);
	void addback_numbers_range(
		std::vector<int>::iterator r_begin, std::vector<int>::iterator r_end);
	unsigned int shortestSpan();
	unsigned int longestSpan() const;

	Span &operator=(Span const &rhs);

	class SizeOverflowException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Span::SizeOverflow");
		}
	};

	class NotEnoughElementsException : public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return ("Span::NotEnoughElements");
		}
	};
};

