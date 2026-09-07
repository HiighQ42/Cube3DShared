/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_input_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:12:13 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 17:24:29 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void move_forward(t_game *game, double amount)
{
    t_vec next;
    t_point cell;
    
    next.x = game->camera.pos.x + game->camera.dir.x * amount;
    next.y = game->camera.pos.y + game->camera.dir.y * amount;
    cell.x = (int)floor(next.x);
    cell.y = (int)floor(game->camera.pos.y);
    if (!cell_is_wall(game->scene, cell))
        game->camera.pos.x = next.x;
    cell.x = (int)floor(game->camera.pos.x);
    cell.y = (int)floor(next.y);
    if (!cell_is_wall(game->scene, cell))
     game->camera.pos.y = next.y;
}

void move_sideways(t_game *game, double amount)
{
    t_vec next;
    t_point cell;

    next.x = game->camera.pos.x - game->camera.dir.y * amount;
    next.y = game->camera.pos.y + game->camera.dir.x * amount;
    cell.x = (int)floor(next.x);
    cell.y = (int)floor(game->camera.pos.y);
    if (!cell_is_wall(game->scene, cell))
        game->camera.pos.x = next.x;
    cell.x = (int)floor(game->camera.pos.x);
    cell.y = (int)floor(next.y);
    if (!cell_is_wall(game->scene, cell))
        game->camera.pos.y = next.y;
}

void apply_rotation(t_game *game, double angle)
{
    rotate_camera(&game->camera, angle);
}