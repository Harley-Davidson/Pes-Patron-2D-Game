/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:22:19 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/07/19 19:22:20 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	free_actors(t_game *g, t_texture *texture, int i, int j)
{
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 8)
		{
			if (texture->player_idle[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->player_idle[i][j]);
			if (texture->player_walk[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->player_walk[i][j]);
			if (texture->player_hits[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->player_hits[i][j]);
			if (texture->player_dead[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->player_dead[i][j]);
			if (texture->foe_idle[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->foe_idle[i][j]);
			if (texture->foe_walk[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->foe_walk[i][j]);
			if (texture->foe_hits[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->foe_hits[i][j]);
			if (texture->foe_dead[i][j])
				mlx_destroy_image(g->mlx_ptr, texture->foe_dead[i][j]);
		}
	}
}

static void	free_textures(t_game *g, t_texture *texture)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!texture)
		return ;
	free_actors(g, texture, i, j);
	i = -1;
	while (++i < 8)
	{
		if (texture->gem[i])
			mlx_destroy_image(g->mlx_ptr, texture->gem[i]);
		if (texture->exit[i])
			mlx_destroy_image(g->mlx_ptr, texture->exit[i]);
	}
	i = -1;
	while (++i < 64)
	{
		if (texture->floor[i])
			mlx_destroy_image(g->mlx_ptr, texture->floor[i]);
		if (texture->wall[i])
			mlx_destroy_image(g->mlx_ptr, texture->wall[i]);
	}
}

void	free_plot(t_game *g)
{
	int	i;

	i = -1;
	if (g->map)
	{
		while (++i < g->y_s)
			if (g->map[i])
				free(g->map[i]);
		free(g->map);
		g->map = NULL;
	}
}

void	free_map(t_game *g)
{
	if (g->cnt)
	{
		if (g->cnt->players > 0)
		{
			free(g->player);
			g->player = NULL;
		}
		if (g->cnt->foes > 0)
		{
			free(g->foe);
			g->foe = NULL;
		}
		free(g->cnt);
	}
	free_plot(g);
}

void	free_game(t_game *g)
{
	if (!g)
		return ;
	free_map(g);
	if (g->texture)
	{
		free_textures(g, g->texture);
		free(g->texture);
		g->texture = NULL;
	}
	if (g->win_ptr)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		g->win_ptr = NULL;
	}
	if (g->mlx_ptr)
	{
		mlx_loop_end(g->mlx_ptr);
		mlx_destroy_display(g->mlx_ptr);
	}
}
