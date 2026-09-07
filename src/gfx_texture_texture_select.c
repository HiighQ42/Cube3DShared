/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_texture_texture_select.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:48:04 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 17:51:13 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_wall_texture *select_texture(t_game *game, t_face face)
{
    if (face == FACE_NORTH)
        return (&game->walls[0]);
    if (face == FACE_SOUTH)
        return (&game->walls[1]);
    if (face == FACE_WEST)
        return (&game->walls[2]);
    return (&game->walls[3]);
}