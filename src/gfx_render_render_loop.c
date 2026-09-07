/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_render_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:25:07 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 17:27:03 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int render_loop(t_game *game)
{
    if (game->input.forward)
        move_forward(game, 0.04);
    if (game->input.backward)
        move_forward(game, -0.04);
    if (game->input.left)
        move_sideways(game, -0.04);
    if (game->input.right)
        move_sideways(game, 0.04);
    if (game->input.turn_left)
        apply_rotation(game, -0.03);
    if (game->input.turn_right)
        apply_rotation(game, 0.03);
    render_flat_frame(game);
    present_frame(game);
    return (0);
}