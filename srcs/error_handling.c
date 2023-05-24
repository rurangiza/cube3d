/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:57 by lupin             #+#    #+#             */
/*   Updated: 2023/05/24 16:05:01 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	errormsg(char *msg, int code)
{
	printf(CRED"Error\n"CRESET);
	printf("%s\n", msg);
	return (code);
}

int	maperror(t_number line, t_number col)
{
	printf(CBOLD CRED"Error\n"CRESET);
	printf(CBOLD"map: "CRESET);
	printf("not closed at %s(ln %d, col %d)%s\n", CBLUE, line, col, CRESET);
	return (1);
}
