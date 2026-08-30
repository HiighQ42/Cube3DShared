/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_debug_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 10:10:07 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 10:18:40 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void draw_debug_map(t_game *game, t_image *image)
{
    t_rect rect;
    int x;
    int y;
    int color;

    y = 0;
    while (game->scene->map.map[y] != NULL)
    {
        x = 0;
        while (game->scene->map.map[y][x] != '\0')
        {
            color = 0x30343F;
            if (game->scene->map.map[y][x] == '1')
                color = 0xE63946;
            rect.x = x * DEBUG_CELL;
            rect.y = y * DEBUG_CELL;
            rect.width = DEBUG_CELL - 1;
            rect.height = DEBUG_CELL - 1;
            fill_rect(image, rect, color);
            x++;
        }
        y++;
    }
}