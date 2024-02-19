/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:25:09 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/19 19:47:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	return (find(container.begin(), container.end(), value));
}
