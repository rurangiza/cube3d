/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:10 by lupin             #+#    #+#             */
/*   Updated: 2023/05/24 16:46:49 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	return (0);
}

int	isvoid(char ch)
{
	if (ft_isspace(ch) || ch == '\n')
		return (TRUE);
	return (FALSE);
}

int	invalid_characters(char *str, int row)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0'
			&& str[i] != '1'
			&& str[i] != 'N'
			&& str[i] != 'S'
			&& str[i] != 'E'
			&& str[i] != 'W'
			&& !ft_isspace(str[i]))
		{
			return (maperror_v2("invalid character", row + 1, i));
		}
		i++;
	}
	return (0);
}
