/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:57 by lupin             #+#    #+#             */
/*   Updated: 2023/05/23 14:42:22 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	errormsg(char *msg, int code)
{
	printf(CRED"Error\n"CRESET);
	printf("%s\n", msg);
	return (code);
}

int	maperror(char *msg, t_number code, t_number line, t_number col)
{
	printf(CRED"Error: "CRESET);
	printf("%s at ln %d, col %d\n", msg, line, col);
	return (code);
}