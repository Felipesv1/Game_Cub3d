/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:18 by felperei          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:36 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

// void	move_left(t_mlx *mlx)
// {
// 	double move_x;
// 	double move_y;
	
// 	move_x = -mlx->ray->dirY;
// 	move_y = mlx->ray->dirY;


//     int newX = (int)(mlx->ply->plyr_x + move_x * PLAYER_SPEED);
//     int newY = (int)(mlx->ply->plyr_y + move_y * PLAYER_SPEED);

// 	if (mlx->dt->map2d[newX][newY] != '1')
// 	{
// 		mlx->ply->plyr_x += move_x;
// 		mlx->ply->plyr_y += move_y;
// 	}
// }
// void	move_player_backward(t_mlx *mlx)
// {
// 	double move_x;
// 	double move_y;

// 	move_x = -cos(mlx->ply->angle) * PLAYER_SPEED;
// 	move_y = -sin(mlx->ply->angle) * PLAYER_SPEED;
// 	int newX = (int)(mlx->ply->plyr_x + move_x) / TILE_SIZE;
//     int newY = (int)(mlx->ply->plyr_y + move_y) / TILE_SIZE;

// 	if (mlx->dt->map2d[newX][newY] != '1')
// 	{
// 		mlx->ply->plyr_x += move_x;
// 		mlx->ply->plyr_y += move_y;
// 	}
// }

void	move_left(t_mlx *mlx)	// rotate the player
{
	double move_x;
	double move_y;
	
	move_x = -mlx->ray->dirY;
	move_y = mlx->ray->dirY;




	if (mlx->dt->map2d[(int)(mlx->ply->plyr_x + move_x * PLAYER_SPEED)][(int)mlx->ply->plyr_y] == 0)
	{
		mlx->ply->plyr_x += move_x * PLAYER_SPEED;
	}
		if (mlx->dt->map2d[(int)mlx->ply->plyr_x][(int)(mlx->ply->plyr_y + move_y * PLAYER_SPEED)] == 0)
	{
		mlx->ply->plyr_y += move_y * PLAYER_SPEED;
	}
}


int keypress(int keycode, t_mlx *mlx) {

    if (keycode == KEY_W) { // Mover para frente
        mlx->ply->plyr_x += mlx->ray->dirX * PLAYER_SPEED;
        mlx->ply->plyr_y += mlx->ray->dirY * PLAYER_SPEED;
    }
    if (keycode == KEY_S) { // Mover para trás
        mlx->ply->plyr_x -= mlx->ray->dirX * PLAYER_SPEED;
        mlx->ply->plyr_y -= mlx->ray->dirY * PLAYER_SPEED;
    }
    if (keycode == KEY_A) { // Girar para a esquerda
      move_left(mlx);
    }
    if (keycode == KEY_D) { // Girar para a direita
        double oldDirX = mlx->ray->dirX;
        mlx->ray->dirX = mlx->ray->dirX * cos(ROTATION_SPEED) - mlx->ray->dirY * sin(ROTATION_SPEED);
        mlx->ray->dirY = oldDirX * sin(ROTATION_SPEED) + mlx->ray->dirY * cos(ROTATION_SPEED);
    }
	return (0);
}


// int	keypress(int keycode, t_mlx *game)
// {
// 	if (keycode == ESC || keycode == KEY_Q)
// 		ft_exit(game);
// 	game_events(keycode, game);
// 	return (0);
// }

//  void	game_events(int keycode, t_mlx *game)
// {
// 	if (keycode == KEY_W || keycode == KEY_UP)
// 	{
// 		move_player_forward(game);
// 	}
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 	{
// 		move_player_backward(game);
// 	}
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 	{

// 		rotate_player(game, 1);
// 	}
// 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// 	{
// 		move_left(game);
// 	}
// }
