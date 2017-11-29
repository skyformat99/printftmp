/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:24:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ignorechr(char *s, char c)
{
	while (*s != 0 && *s == c)
		s++;
	return (s);
}

static char		*ignoreword(char *s, char c)
{
	while (*s != 0 && *s != c)
		s++;
	return (s);
}

static int		len_words(char *s, char c, int *num)
{
	int		res;

	*num = 0;
	res = 0;
	s = ignorechr(s, c);
	while (*s)
	{
		s = ignoreword(s, c);
		s = ignorechr(s, c);
		res++;
	}
	return (res);
}

static int		len_word(char *s, char c, int *num)
{
	int		length;

	*num = 0;
	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	int		length_tot;
	int		length_word;
	int		index[2];
	char	*tmp;
	char	**res;

	if (s == 0)
		return (0);
	length_tot = len_words((char *)s, c, index);
	tmp = ignorechr((char *)s, c);
	if ((res = (char **)malloc(sizeof(char *) * (length_tot + 1))) == NULL)
		return (NULL);
	while (index[0] < length_tot)
	{
		length_word = len_word(tmp, c, index + 1);
		if ((res[index[0]] =
			(char *)malloc(sizeof(char) * (length_word + 1))) == NULL)
			return (NULL);
		while (index[1] < length_word)
			res[index[0]][index[1]++] = *(tmp++);
		res[index[0]++][index[1]] = 0;
		tmp = ignorechr(tmp, c);
	}
	res[index[0]] = 0;
	return (res);
}
