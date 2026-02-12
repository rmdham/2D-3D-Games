/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:02:43 by slouham           #+#    #+#             */
/*   Updated: 2025/04/29 16:54:29 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_color(char **arr_2d)
{
	int	i;
	int	j;
	int	color_code;

	color_code = 0;
	i = -1;
	while (arr_2d[++i])
	{
		j = -1;
		while (arr_2d[i][++j])
		{
			if (ft_isdigit(arr_2d[i][j]) != 1)
				func_error("Code color is not valid");
		}
		color_code += get_color_num(arr_2d[i], i);
	}
	return (color_code);
}

int	parse_colors(char *arr)
{
	char	**f_color_2d;
	int		i;
	int		num_color;

	calculate_comma(arr);
	f_color_2d = ft_split(arr, ',');
	i = 0;
	while (f_color_2d[i])
		i++;
	if (i != 3)
		func_error("Code color is not valid");
	num_color = get_color(f_color_2d);
	free_2d(f_color_2d);
	return (num_color);
}

int	stock_colors(t_cube *s_pars, char **arr_2d)
{
	if (ft_strcmp(arr_2d[0], "F") == 0)
	{
		if (s_pars->f)
			func_error("F duplicated");
		s_pars->f = ft_strdup(arr_2d[1]);
		s_pars->num_info++;
		s_pars->f_color = parse_colors(s_pars->f);
		return (1);
	}
	else if (ft_strcmp(arr_2d[0], "C") == 0)
	{
		if (s_pars->c)
			func_error("C duplicated");
		s_pars->c = ft_strdup(arr_2d[1]);
		s_pars->num_info++;
		s_pars->c_color = parse_colors(s_pars->c);
		return (1);
	}
	func_error("Not an info");
	return (0);
}

void	stock_info(t_cube *s_pars, char **arr_2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (ft_strcmp(s_pars->info[i].key, arr_2d[0]) == 0)
		{
			if (*(s_pars->info[i].value))
				func_error("duplicate");
			*(s_pars->info[i].value) = ft_strdup(arr_2d[1]);
			s_pars->num_info++;
			j = 1;
			break ;
		}
		i++;
	}
	if (j == 0)
		stock_colors(s_pars, arr_2d);
	return ;
}

void	parse_info(t_cube *s_pars, char *temp1)
{
	int		i;
	char	*temp2;
	char	**temp_2d;

	temp2 = ft_strtrim(temp1, " 	\n");
	if (temp2[0] != '\n' && temp2[0] != '\0')
	{
		temp_2d = ft_split2(temp2);
		i = -1;
		while (temp_2d[++i])
			;
		if (i != 2)
			func_error("The informations are not valid");
		stock_info(s_pars, temp_2d);
		free_2d(temp_2d);
	}
	free(temp1);
	free(temp2);
	return ;
}
