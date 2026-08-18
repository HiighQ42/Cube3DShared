/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_input_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:02:42 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/18 14:02:52 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int key_press(int key, t_game *game)
{
    if (key == KEY_ESC)
        return (close_game(game, 0));
    return (set_key_state(key, &game->input, 1));
}

int key_release(int key, t_game *game)
{
    return (set_key_state(key, &game->input, 0));
}

int window_close(t_game *game)
{
    return (close_game(game, 0));
}

static int final_render_loop(t_game *game)
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
    render_frame(game);
    return (0);
}

void install_hooks(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, key_press, game);
    mlx_hook(game->win, 3, 1L << 1, key_release, game);
    mlx_hook(game->win, 17, 0, window_close, game);
    mlx_loop_hook(game->mlx, final_render_loop, game);
}