/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_player_camera_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:43:34 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 11:50:43 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int init_camera(t_game *game)
{
    t_spawn spawn;

    if (!find_spawn(game->scene, &spawn))
        return (0);
    game->camera.pos.x = (double)spawn.x + 0.5;
    game->camera.pos.y = (double)spawn.y + 0.5;
    game->camera.dir = start_direction(spawn.orientation);
    game->camera.plane = make_camera_plane(game->camera.dir, CAMERA_SCALE);
    return (1);
}