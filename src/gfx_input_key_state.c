/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_input_key_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:32:38 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 15:21:18 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int set_key_state(int key, t_input *input, int pressed)
{
    pressed = (pressed != 0);
    if (key == KEY_W)
        input->forward = pressed;
    else if (key == KEY_S)
        input->backward = pressed;
    else if (key == KEY_A)
        input->left = pressed;
    else if (key == KEY_D)
        input->right = pressed;
    else if (key == KEY_LEFT)
        input->turn_left = pressed;
    else if (key == KEY_RIGHT)
        input->turn_right = pressed;
    return (0);
}

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