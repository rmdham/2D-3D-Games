/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:02:17 by slouham           #+#    #+#             */
/*   Updated: 2025/04/29 16:49:50 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	skip_whitespace(char	*arr, int i)
{
	while (arr[i] && (arr[i] == 9 || arr[i] == 32))
		i++;
	return (i);
}

void	check_free_lines(char *arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i] == '\n')
		{
			i = skip_whitespace(arr, ++i);
			if (arr[i] == '\0' || arr[i] == '\n')
				func_error("Empty line in your map");
		}
	}
}

char	*get_map(t_cube *s_pars)
{
	char	*temp1;

	temp1 = get_next_line(s_pars->fd);
	while (temp1 && s_pars->num_info < 6)
	{
		parse_info(s_pars, temp1);
		temp1 = get_next_line(s_pars->fd);
	}
	if (s_pars->num_info < 6 || !temp1)
		func_error("Make sure all ur infos and your map exist");
	while (temp1 && empty_line(temp1))
	{
		free(temp1);
		temp1 = get_next_line(s_pars->fd);
	}
	if (!temp1)
		func_error("Make sure you have a map in your file");
	parse_map(s_pars, temp1);
	return ("DONE");
}

void	init_text_array(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		g->arr_text[i].image = mlx_xpm_file_to_image(g->data.mlx, \
			g->arr_text[i].path, \
			&g->arr_text[i].w, &g->arr_text[i].h);
		if (!g->arr_text[i].image)
		{
			func_error("Invalid path to texture\n");
			exit (1);
		}
		g->arr_text[i].addr = mlx_get_data_addr(g->arr_text[i].image, \
		&g->arr_text[i].tbbp, \
		&g->arr_text[i].tline_length, \
		&g->arr_text[i].tendian);
	}
}

char	*parsing(t_game *s_game, int argc, char **av)
{
	t_cube	s_pars;

	if (argc != 2)
		func_error("Usage: ./cub3D [map.cub]");
	s_pars.fd = check_file_name(av[1]);
	init_struct(&s_pars);
	get_map(&s_pars);
	s_game->map = s_pars.map_2d;
	s_game->arr_text[N_IDX].path = s_pars.no;
	s_game->arr_text[S_IDX].path = s_pars.so;
	s_game->arr_text[W_IDX].path = s_pars.we;
	s_game->arr_text[E_IDX].path = s_pars.ea;
	s_game->data.c = s_pars.c_color;
	s_game->data.f = s_pars.f_color;
	init_text_array(s_game);
	free(s_pars.no);
	free(s_pars.so);
	free(s_pars.we);
	free(s_pars.ea);
	free(s_pars.f);
	free(s_pars.c);
	free(s_pars.info);
	close (s_pars.fd);
	return ("DONE");
}
