/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:44 by akorompa          #+#    #+#             */
/*   Updated: 2023/05/17 13:42:40 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->cam.move_up = true;
	if (keycode == 1)
		data->cam.move_back = true;
	if (keycode == 0)
		data->cam.move_left = true;
	if (keycode == 2)
		data->cam.move_right = true;
	//pivot gauche
	if (keycode == 123)
	{
		data->cam.turn = true;
		data->cam.speedRotation = -0.1;
	}
	//pivot droit
	if (keycode == 124)
	{
		data->cam.turn = true;
		data->cam.speedRotation = 0.1;
	}
	return(1);
}

int ft_key_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->cam.move_up = false;
	if (keycode == 1)
		data->cam.move_back = false;
	if (keycode == 0)
		data->cam.move_left = false;
	if (keycode == 2)
		data->cam.move_right = false;
	if (keycode == 123)
		data->cam.turn = false;
	if (keycode == 124)
		data->cam.turn = false;
	return(1);
}