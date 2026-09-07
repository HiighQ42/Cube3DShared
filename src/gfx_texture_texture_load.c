/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_texture_texture_load.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:30:34 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 17:46:16 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int load_texture(t_game *game, t_wall_texture *texture, char *path)
{
    texture->image.handle = mlx_xpm_file_to_image(game->mlx, path, &texture->image.width, &texture->image.height);
    if (texture->image.handle == NULL)
        return (0);
    if (!map_texture_memory(texture))
    {
        mlx_destroy_image(game->mlx, texture->image.handle);
        texture->image.handle = NULL;
        return (0);
    }
    return (1);
}

int map_texture_memory(t_wall_texture *texture)
{
    t_image *image;

    image = &texture->image;
    if (image->handle == NULL)
        return (0);
    image->addr = mlx_get_data_addr(image->handle, &image->bpp, &image->line_len, &image->endian);
    return (image->addr != NULL);
}

int texture_pixel(t_wall_texture *texture, t_point point)
{
    unsigned char *pixel;
    int bytes;
    int color;
    int index;

    if (point.x < 0 || point.x >= texture->image.width)
        return (0);
    if (point.y < 0 || point.y >= texture->image.height)
        return (0);
    pixel = (unsigned char *)pixel_address(&texture->image, point);
    bytes = texture->image.bpp / 8;
    color = 0;
    index = 0;
    while (index < bytes)
    {
        if (texture->image.endian == 0)
            color |= pixel[index] << (index * 8);
        else
            color |= pixel[bytes - 1 - index] << (index * 8);
        index++;
    }
    return (color);
}

static void clear_wall_set(t_game *game)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if (game->walls[i].image.handle != NULL)
            mlx_destroy_image(game->mlx, game->walls[i].image.handle);
        game->walls[i].image.handle = NULL;
        i++;
    }
}

int load_textures(t_game *game)
{
    if (!load_texture(game, &game->walls[0], game->scene->texture[NO].path))
    {
        clear_wall_set(game);
        return (0);
    }
    if (!load_texture(game, &game->walls[1], game->scene->texture[SO].path))
    {
        clear_wall_set(game);
        return (0);
    }
    if (!load_texture(game, &game->walls[2], game->scene->texture[WE].path))
    {
        clear_wall_set(game);
        return (0);
    }
    if (!load_texture(game, &game->walls[3], game->scene->texture[EA].path))
    {
        clear_wall_set(game);
        return (0);
    }
    return (1);
}