/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:22:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:57:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	if ((res = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		res[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
	{
		res[len1 + len2] = s2[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}
