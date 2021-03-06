/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:22:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 == 0 || s2 == 0)
		return (-1);
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
