/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_any.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 11:13:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_any(char *s, int (*f)(int c))
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) != 0)
			return (1);
		index++;
	}
	return (0);
}
