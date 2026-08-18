/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:00:25 by shiraishida       #+#    #+#             */
/*   Updated: 2026/08/18 14:30:08 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "graphics.h"

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
	if (!run_graphics(data))
		return (1);
	return (free_data(data), 0);
}
