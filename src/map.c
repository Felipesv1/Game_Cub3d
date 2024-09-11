/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:38:17 by felperei          #+#    #+#             */
/*   Updated: 2024/09/11 14:07:42 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) return NULL;

    char *line;
    char *holder_map = ft_strdup("");
    char **map;

    while ((line = get_next_line(fd))) {
        char *temp = holder_map;
        holder_map = ft_strjoin(holder_map, line);
        free(temp);
        free(line);
    }
    close(fd);
    
    map = ft_split(holder_map, '\n');
    free(holder_map);
    
    return map;
}

int	size_map(t_data *game)
{
	int	i;

	game->w_map = ft_strlen(game->map2d[0]);
	i = 0;
	while (game->map2d[i])
		i++;
	game->h_map = i;
	if (game->w_map != game->h_map)
		return (1);
	return (0);
}