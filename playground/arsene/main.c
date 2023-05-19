/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:42 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/11 14:43:39 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* "SOCATOA"
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *
 * sin(θ) = opposite/hypotenuse  *
 * cos(θ) = adjacent/hypotenuse  *
 * tan(θ) = opposite/adjacent    *
 * hypothenuse² = (a² + ²)       *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *
*/

#define TILE_SIZE	32
#define MAP_NUM_ROWS	11
#define MAP_NUM_COLS 15

typedef struct global {
	char map[MAP_NUM_COLS][MAP_NUM_ROWS];
} global;

int	main(void)
{
	global	*game;
	
	game = malloc(sizeof(global));
}