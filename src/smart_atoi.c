/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:59:20 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/15 12:09:51 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v'
		|| c == '\r');
}

int	protect_overflow(const char *nptr, int i, int sign)
{
	long	res;

	res = 0;
	while (ft_isdigit((unsigned char)nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		if (res > 255)
			return (-1);
		i++;
	}
	return ((int)(sign * res));
}

int	smart_atoi(const char *nptr)
{
	size_t	i;
	int		sign;

	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		if (nptr[i] == '-' || nptr[i] == '+')
			return (0);
	}
	return (protect_overflow(nptr, i, sign));
}
