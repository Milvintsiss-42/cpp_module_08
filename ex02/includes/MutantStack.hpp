/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:29:55 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/22 03:24:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template<typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence> {
public:
	typedef typename Sequence::iterator iterator;
	typedef typename Sequence::const_iterator const_iterator;
	typedef typename Sequence::reverse_iterator reverse_iterator;
	typedef typename Sequence::const_reverse_iterator const_reverse_iterator;

	MutantStack();
	MutantStack(MutantStack const &src);
	~MutantStack();

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	MutantStack<T, Sequence> &operator=(MutantStack<T, Sequence> const &rhs);
};

#include "MutantStack.tpp"
