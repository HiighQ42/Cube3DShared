/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_mlx_frame_present.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:13:27 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/18 15:16:48 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void present_frame(t_game *game)
{
    if (game == NULL || game->mlx == NULL)
        return ;
    if (game->win == NULL || game->frame.handle == NULL)
        return ;
    mlx_put_image_to_window(game->mlx, game->win, game->frame.handle, 0, 0); 
}