/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_texture_texture_vertical.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:01:45 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 18:07:15 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

double texture_step(int texture_height, int wall_height)
{
    if (wall_height <= 0)
        return (0.0);
    return ((double)texture_height / (double)wall_height);
}

double texture_start(t_span raw, t_span clipped, double step)
{
    return ((double)(clipped.start - raw.start) * step);
}

static void init_sample(t_sample *sample, t_game *game, t_ray *ray)
{
    sample->texture = select_texture(game, ray->face);
    sample->line_height = wall_height(ray->distance, game->height);
    sample->raw = wall_span(sample->line_height, game->height);
    sample->visible = clip_span(sample->raw, game->height);
    sample->tex_x = texture_column(ray->wall_x, sample->texture->image.width);
    sample->tex_x = orient_texture_x(sample->tex_x,
    sample->texture->image.width, ray);
    sample->step = texture_step(sample->texture->image.height, sample->line_height);
    sample->position = texture_start(sample->raw, sample->visible, sample->step);
}
void draw_textured_slice(t_game *game, t_ray *ray, int x)
{
    t_sample sample;
    t_point screen;
    t_point texel;
    int color;
    
    init_sample(&sample, game, ray);
    screen.x = x;
    screen.y = sample.visible.start;
    texel.x = sample.tex_x;
    while (screen.y <= sample.visible.end)
    {
        texel.y = (int)sample.position;
        color = texture_pixel(sample.texture, texel);
        write_pixel(&game->frame, screen, color);
        sample.position += sample.step;
        screen.y++;
    }
}