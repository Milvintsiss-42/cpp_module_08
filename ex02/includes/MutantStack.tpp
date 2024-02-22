/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:23:33 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/22 03:23:56 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, typename Sequence>
MutantStack<T, Sequence>::MutantStack() : std::stack<T, Sequence>()
{
}

template <typename T, typename Sequence>
MutantStack<T, Sequence>::MutantStack(MutantStack const &src) : std::stack<T, Sequence>(src)
{
}

template <typename T, typename Sequence>
MutantStack<T, Sequence>::~MutantStack()
{
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::iterator MutantStack<T, Sequence>::begin()
{
	return this->c.begin();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::const_iterator MutantStack<T, Sequence>::begin() const
{
	return this->c.begin();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::iterator MutantStack<T, Sequence>::end()
{
	return this->c.end();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::const_iterator MutantStack<T, Sequence>::end() const
{
	return this->c.end();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::reverse_iterator MutantStack<T, Sequence>::rbegin()
{
	return this->c.rbegin();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::const_reverse_iterator MutantStack<T, Sequence>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::reverse_iterator MutantStack<T, Sequence>::rend()
{
	return this->c.rend();
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::const_reverse_iterator MutantStack<T, Sequence>::rend() const
{
	return this->c.rend();
}

template <typename T, typename Sequence>
MutantStack<T, Sequence> &MutantStack<T, Sequence>::operator=(MutantStack<T, Sequence> const &rhs)
{
	std::stack<T, Sequence>::operator=(rhs);
	return *this;
}
