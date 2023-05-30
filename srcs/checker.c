/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:10 by lupin             #+#    #+#             */
/*   Updated: 2023/05/30 13:43:14 by akorompa         ###   ########.fr       */
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

int	invalid_characters(char *str, int row, int *foundplayer)
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
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			*foundplayer += 1;
		if (str[i + 1] == '\n' && ft_isspace(str[i]))
			maperror_v2("extra space at end of line", row + 1, i);
		i++;
	}
	return (0);
}
