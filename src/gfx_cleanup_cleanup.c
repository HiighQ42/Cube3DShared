/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_cleanup_cleanup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:07:20 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 19:15:59 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void destroy_textures(t_game *game)
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

static void destroy_frame(t_game *game)
{
    if (game->frame.handle != NULL)
        mlx_destroy_image(game->mlx, game->frame.handle);
    game->frame.handle = NULL;
}

static void destroy_window(t_game *game)
{
    if (game->win != NULL)
        mlx_destroy_window(game->mlx, game->win);
    game->win = NULL;
}
void destroy_game(t_game *game)
{
    if (game == NULL)
        return ;
    if (game->mlx != NULL)
    {
        destroy_textures(game);
        destroy_frame(game);
        destroy_window(game);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        game->mlx = NULL;
    }
    free_data(game->scene);
    game->scene = NULL;
}
int close_game(t_game *game, int exit_code)
{
    destroy_game(game);
    exit(exit_code);
    return (exit_code);
}