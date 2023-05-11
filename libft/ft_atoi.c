/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorompa <akorompa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:02:03 by akorompa          #+#    #+#             */
/*   Updated: 2022/10/21 13:29:13 by akorompa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_ismax(int n)
{
	if (n == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		count;
	long	result;

	count = 0;
	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - 48);
		count++;
		if (result < 0 || count > 19)
			return (ft_ismax(sign));
	}
	return (sign * result);
}
