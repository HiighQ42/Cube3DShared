/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:43:55 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 17:19:40 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	flood_fill(t_Parse *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->copy[y])
	{
		x = 0;
		while (data->copy[y][x])
		{
			if (data->copy[y][x] != ' ' && data->copy[y][x] != '1'
				&& data->copy[y][x] != 'f')
				flood(x, y, data);
			x++;
		}
		y++;
	}
	if (data->flag)
		return (error_message_in_parse(3), -1);
	if (flood_fill_space(data))
		return (error_message_in_parse(0), -1);
	return (0);
}

int	flood_fill_space(t_Parse *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->copy[y])
	{
		x = 0;
		data->flag = 0;
		while (data->copy[y][x])
		{
			if (data->copy[y][x] == ' ')
			{
				flood_space(x, y, data);
				if (!data->flag)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	flood_space(int x_pos, int y_pos, t_Parse *data)
{
	if (x_pos < 0 || y_pos < 0 || x_pos > data->width || y_pos > data->hight)
	{
		data->flag++;
		return ;
	}
	if (data->copy[y_pos][x_pos] == '1' || data->copy[y_pos][x_pos] == 's')
		return ;
	data->copy[y_pos][x_pos] = 's';
	flood_space(x_pos + 1, y_pos, data);
	flood_space(x_pos - 1, y_pos, data);
	flood_space(x_pos, y_pos + 1, data);
	flood_space(x_pos, y_pos - 1, data);
}

void	flood(int x_pos, int y_pos, t_Parse *data)
{
	if (x_pos < 0 || y_pos < 0 || x_pos > data->width || y_pos > data->hight)
	{
		data->flag++;
		return ;
	}
	if (data->copy[y_pos][x_pos] == '1' || data->copy[y_pos][x_pos] == 'f')
		return ;
	if (char_check_in_flood(data->copy[y_pos][x_pos]))
	{
		data->flag++;
		return ;
	}
	data->copy[y_pos][x_pos] = 'f';
	flood(x_pos + 1, y_pos, data);
	flood(x_pos - 1, y_pos, data);
	flood(x_pos, y_pos + 1, data);
	flood(x_pos, y_pos - 1, data);
}

int	char_check_in_flood(char c)
{
	char	*index;
	int		i;

	index = "0NSWE";
	i = 0;
	while (i < 5)
	{
		if (index[i] == c)
			return (0);
		i++;
	}
	return (-1);
}
