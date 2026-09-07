/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:04:19 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 19:54:56 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int prepare_graphics(t_game *game, t_Data *scene)
{
    if (!init_mlx(game, scene))
        return (0);
    if (!open_window(game) || !create_frame(game))
        return (0);
    if (!map_image_memory(&game->frame))
        return (0);
    if (!init_camera(game) || !load_textures(game))
        return (0);
    return (1);
}

int run_graphics(t_Data *scene)
{
    t_game game;
    if (scene == NULL)
        return (0);
    ft_bzero(&game, sizeof(t_game));
    if (!prepare_graphics(&game, scene))
    {
        destroy_game(&game);
        return (0);
    }
    install_hooks(&game);
    render_frame(&game);
    mlx_loop(game.mlx);
    destroy_game(&game);
    return (1);
}