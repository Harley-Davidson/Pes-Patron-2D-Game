/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:09:02 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/07/18 22:09:04 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_foes(t_game *g, int f)
{
	int	i;

	i = -1;
	while (&(g->foe[++i]) != NULL)
	{
		g->foe[i].d = 0;
		if (g->foe[i].dir == MOVE_UP)
			g->foe[i].d = 1;
		else if (g->foe[i].dir == MOVE_LEFT)
			g->foe[i].d = 3;
		else if (g->foe[i].dir == MOVE_RIGHT)
			g->foe[i].d = 2;
		if (g->foe[i].action == 0)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->texture
				->foe_idle[g->foe[i].d][f], g->foe[i].pos.x, g->foe[i].pos.y);
		else if (g->foe[i].action == 1)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->texture
				->foe_walk[g->foe[i].d][f], g->foe[i].pos.x, g->foe[i].pos.y);
		else if (g->foe[i].action == 2)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->texture
				->foe_hits[g->foe[i].d][f], g->foe[i].pos.x, g->foe[i].pos.y);
		else if (g->foe[i].action == 3)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->texture
				->foe_dead[g->foe[i].d][f], g->foe[i].pos.x, g->foe[i].pos.y);
	}
}

void	draw_tiles(t_game *g, int frame)
{

}

void	draw_gems(t_game *g, int frame)
{

}

void	draw_exit(t_game *g, int frame)
{

}
