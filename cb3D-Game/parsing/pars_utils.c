/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:02:55 by slouham           #+#    #+#             */
/*   Updated: 2025/04/29 16:49:59 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_color_num(char *str, int i)
{
	int	num;

	num = ft_atoi(str);
	if (num > 255 || num < 0)
		func_error("color code is not valid");
	if (i == 0)
		num = num << 16;
	else if (i == 1)
		num = num << 8;
	return (num);
}

int	calculate_comma(char *str)
{
	int	num_comma;
	int	i;

	i = 0;
	num_comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			num_comma++;
		i++;
	}
	if (num_comma != 2)
		func_error("Code color is not valid");
	return (num_comma);
}

void	func_error(char *str)
{
	printf("Error\n%s", str);
	exit(1);
}

void	free_2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	init_struct(t_cube *s_pars)
{
	s_pars->info = malloc(sizeof(t_check_info) * 5);
	s_pars->no = NULL;
	s_pars->so = NULL;
	s_pars->we = NULL;
	s_pars->ea = NULL;
	s_pars->f = NULL;
	s_pars->c = NULL;
	s_pars->num_info = 0;
	s_pars->on_off = 0;
	s_pars->info[0].key = "NO";
	s_pars->info[0].value = &s_pars->no;
	s_pars->info[1].key = "SO";
	s_pars->info[1].value = &s_pars->so;
	s_pars->info[2].key = "WE";
	s_pars->info[2].value = &s_pars->we;
	s_pars->info[3].key = "EA";
	s_pars->info[3].value = &s_pars->ea;
	s_pars->info[4].key = NULL;
	s_pars->info[4].value = NULL;
	s_pars->player_exit = 0;
}
