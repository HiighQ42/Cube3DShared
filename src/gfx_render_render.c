/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:46:52 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 19:05:57 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void render_textured_column(t_game *game, int x)
{
    t_ray ray;

    init_ray(&ray, game, x);
    if (!run_dda(&ray, game->scene))
        return;
    ray.distance = wall_distance(&ray);
    ray.face = wall_face(&ray);
    ray.hit = wall_hit(&game->camera, &ray);
    ray.wall_x = wall_fraction(ray.hit, ray.side);
    draw_textured_slice(game, &ray, x);
}

void render_frame(t_game *game)
{
    int x;

    draw_background(&game->frame, make_rgb(&game->scene->color[1]), make_rgb(&game->scene->color[0]));
    x = 0;
    while (x < game->width)
    {
        render_textured_column(game, x);
        x++;
    }
    present_frame(game);
}

