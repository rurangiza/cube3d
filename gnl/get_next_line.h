/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:07 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/27 17:22:42 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../includes/cub3d.h"

# define BUFFER_SIZE 5

char	*ft_strjoin_mod(char *old_stash, char *buff);
int		ft_strchr_mod(const char *s, char ch);

char	*get_next_line(int fd);
char	*save_raw_line(int fd, char *stash);
char	*trim_right(char *raw_line);
char	*trim_left(char *stash);
char	*free_stash(char *stash);

#endif