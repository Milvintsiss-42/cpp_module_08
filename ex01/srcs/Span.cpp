/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:05:41 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/20 18:18:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers(std::vector<int>())
{
}

Span::Span(unsigned int N) : _maxSize(N), _numbers(std::vector<int>())
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

std::vector<int> &Span::getNumbers()
{
	return this->_numbers;
}

void Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw SizeOverflowException();
	this->_numbers.push_back(number);
}

void Span::addback_numbers_range(
		std::vector<int>::iterator r_begin, std::vector<int>::iterator r_end)
{
	if (this->_numbers.size() + std::distance(r_begin, r_end) > this->_maxSize)
		throw SizeOverflowException();
	this->_numbers.insert(
		this->_numbers.begin() + this->_numbers.size(),
		r_begin,
		r_end);
}

unsigned int Span::shortestSpan()
{
	if (this->_numbers.size() <= 1)
		throw NotEnoughElementsException();

	std::vector<unsigned int> diffs(this->_numbers.size());
	sort(this->_numbers.begin(), this->_numbers.end());
    adjacent_difference(
		this->_numbers.begin(),
		this->_numbers.end(),
		diffs.begin());
	return (*min_element(++diffs.begin(), diffs.end()));
}

unsigned int Span::longestSpan() const
{
	if (this->_numbers.size() <= 1)
		throw NotEnoughElementsException();

	std::vector<int>::const_iterator max = max_element(
		this->_numbers.begin(),
		this->_numbers.end()
		);
	std::vector<int>::const_iterator min = min_element(
		this->_numbers.begin(),
		this->_numbers.end()
		);
	return (*max - *min);
}

Span &Span::operator=(Span const &rhs)
{
	this->_maxSize = rhs._maxSize;
	this->_numbers = rhs._numbers;
	return *this;
}
