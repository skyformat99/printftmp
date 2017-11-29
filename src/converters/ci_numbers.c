/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:40:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers.h"

/*
** 1 => left empty
** 2 => right empty
** 3 => both zero
*/

static char			*adaptcasebycase(char *prefix, char *str, int gabarit,
		int id)
{
	char	*tmp;

	tmp = ft_strsetnew(gabarit, (id == 3) ? '0' : ' ');
	if (id == 2)
		ft_strncpy(tmp + gabarit - ft_strlen(prefix) - ft_strlen(str), prefix,
			ft_strlen(prefix));
	else
		ft_strncpy(tmp, prefix, ft_strlen(prefix));
	if (id == 1)
		ft_strncpy(tmp + ft_strlen(prefix), str, ft_strlen(str));
	else
		ft_strncpy(tmp + gabarit - ft_strlen(str), str, ft_strlen(str));
	return (tmp);
}

static char			*adaptgabarit(char *prefix, char *str, t_treat_data *data)
{
	char	*res;

	if (data->gabarit > (int)(ft_strlen(str) + ft_strlen(prefix)))
	{
		if (data->minus_flag)
			res = adaptcasebycase(prefix, str, data->gabarit, 1);
		else if (data->precision != -1)
			res = adaptcasebycase(prefix, str, data->gabarit, 2);
		else
		{
			if (data->zero_flag)
				res = adaptcasebycase(prefix, str, data->gabarit, 3);
			else
				res = adaptcasebycase(prefix, str, data->gabarit, 2);
		}
	}
	else
		res = adaptcasebycase(prefix, str, ft_strlen(str) + ft_strlen(prefix),
			1);
	free(str);
	free(prefix);
	return (res);
}

char				*buildumeri(va_list va, t_treat_data *data)
{
	char	*str;
	char	*prefix;

	str = get_rep_with_prec(va, data);
	prefix = get_prefix(&str, data);
	return (adaptgabarit(prefix, str, data));
}
