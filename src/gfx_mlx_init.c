/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:32:12 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/18 14:58:09 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int init_mlx(t_game *game, t_Data *scene)
{
    if (game == NULL || scene == NULL)
        return (0);
    ft_bzero(game, sizeof(t_game));
    game->scene = scene;
    game->width = VIEW_WIDTH;
    game->height = VIEW_HEIGHT;
    game->mlx = mlx_init();
    if (game->mlx == NULL)
        return (0);
    return (1);
}

int open_window(t_game *game)
{
    if (game == NULL || game->mlx == NULL)
        return (0);
    game->win = mlx_new_window(game->mlx, game->width, game->height, "cube3D");
    if (game->win == NULL)
        return (0);
    return (1);
}

int create_frame(t_game *game)
{
    if (game == NULL || game->mlx == NULL)
        return (0);

    game->frame.width = game->width;
    game->frame.height = game->height;
    game->frame.handle = mlx_new_image(game->mlx, game->width, game->height);
    if (game->frame.handle == NULL)
        return (0);
    return (1);
}

int map_image_memory(t_image *image)
{
    if (image == NULL || image->handle == NULL)
        return (0);
    image->addr = mlx_get_data_addr(image->handle, &image->bpp, &image->line_len, &image->endian);
    if (image->addr == NULL)
        return (0);
    return (1);
}