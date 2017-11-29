/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:16:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 19:40:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_values_treat_data2.h"

int		set_converter_treat_data2(char cpy)
{
	if (cpy == 'S')
		return (CI_SMAJ);
	else if (cpy == 'D')
		return (CI_DMAJ);
	else if (cpy == 'O')
		return (CI_OMAJ);
	else if (cpy == 'U')
		return (CI_UMAJ);
	else if (cpy == 'X')
		return (CI_XMAJ);
	else if (cpy == 'C')
		return (CI_CMAJ);
	else if (cpy == 'E')
		return (CI_EMAJ);
	else if (cpy == 'F')
		return (CI_FMAJ);
	else if (cpy == 'G')
		return (CI_GMAJ);
	else if (cpy == 'A')
		return (CI_AMAJ);
	return (-1);
}

void	update_uppercase_for_l_lm(char letter, t_treat_data *data)
{
	if (letter == 'D' || letter == 'O' || letter == 'U')
	{
		data->length_modifier_id = LM_L;
		data->converter_id = data->converter_id - 1;
	}
	else if (letter == 'p')
	{
		data->length_modifier_id = LM_LL;
		data->hashtag_flag = 1;
	}
}
