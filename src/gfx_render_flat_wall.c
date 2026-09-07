/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_flat_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:07:28 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 14:27:07 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void draw_wall_slice(t_image *image, int x, t_span span, int color)
{
    t_point point;

    point.x = x;
    point.y = span.start;
    while (point.y <= span.end)
    {
        write_pixel(image, point, color);
        point.y++;
    }
}

t_face wall_face(t_ray *ray)
{
    if (ray->side == SIDE_X && ray->dir.x > 0.0)
        return (FACE_WEST);
    if (ray->side == SIDE_X)
        return (FACE_EAST);
    if (ray->dir.y > 0.0)
        return (FACE_NORTH);
    return (FACE_SOUTH);
}

static int face_color(t_face face)
{
    if (face == FACE_NORTH)
        return (0xD95D39);
    if (face == FACE_SOUTH)
        return (0x7B2CBF);
    if (face == FACE_WEST)
        return (0x2A9D8F);
    return (0xE9C46A);
}

static void cast_flat_column(t_game *game, int x)
{
    t_ray ray;
    t_span span;
    int height;

    init_ray(&ray, game, x);
    if (!run_dda(&ray, game->scene))
        return;
    ray.distance = wall_distance(&ray);
    ray.face = wall_face(&ray);
    height = wall_height(ray.distance, game->height);
    span = clip_span(wall_span(height, game->height), game->height);
    draw_wall_slice(&game->frame, x, span, face_color(ray.face));
}

void render_flat_frame(t_game *game)
{
    int x;

    draw_background(&game->frame, make_rgb(&game->scene->color[1]), make_rgb(&game->scene->color[0]));
    x = 0;
    while (x < game->width)
    {
        cast_flat_column(game, x);
        x++;
    }
}