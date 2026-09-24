/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:51:17 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 15:57:20 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	char_in_map(char **map)
{
	int		player;
	int		i;
	int		j;
	char	*tmp;

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		tmp = ft_strtrim(map[i], " ");
		if (!tmp)
			return (error_message(2), -1);
		while (tmp[j])
		{
			if (go_through_indexarr(tmp[j], &player))
				return (error_message_in_parse(0), -1);
			j++;
		}
		free(tmp);
		i++;
	}
	return (player_check(player));
}

int	player_check(int player)
{
	if (!player)
		return (error_message_in_parse(1), -1);
	else if (player != 1)
		return (error_message_in_parse(2), -1);
	return (0);
}

int	go_through_indexarr(char c, int *player)
{
	char	*index;
	int		i;

	index = "10 NSWE";
	i = 0;
	while (i < 7)
	{
		if (c == index[i])
		{
			if (i > 2)
				*player = *player + 1;
			return (0);
		}
		i++;
	}
	return (-1);
}
