/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:00:25 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 19:20:23 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_Data	*data;

	if (ac != 2)
		return (error_message(0), 1);
	if (ft_strlen(av[1]) < 5)
		return (error_message(0), 1);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return (error_message(0), 1);
	data = prep_data(av[1]);
	if (!data)
		return (error_message(1), 1);
	if (parse_map(&data->map))
		return (free_data(data), error_message(3), 1);
	return (free_data(data), 0);
}
