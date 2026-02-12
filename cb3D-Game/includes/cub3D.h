/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:51:42 by alaaouar          #+#    #+#             */
/*   Updated: 2025/05/06 09:36:42 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define DISP_SIZE 32
# define K_W 119
# define K_E 101
# define K_F 102
# define K_S 115
# define K_A 97
# define K_D 100
# define K_ARRR 65363
# define K_ARRL 65361
# define ESC 65307
# define FOV 1.0472
# define W_WIDTH 1280
# define W_HEIGHT 720
# define NORTH 360
# define SOUTH 180
# define EAST 90
# define WEST 270
# define VERTICAL 1
# define HORIZONTAL 0
# define N_IDX 0
# define S_IDX 1
# define W_IDX 2
# define E_IDX 3
# define M_PI		3.14159265358979323846
# define M_PI_2		1.57079632679489661923

typedef struct s_textures
{
	char	*path;
	void	*image;
	char	*addr;
	int		tbbp;
	int		tline_length;
	int		tendian;
	int		w;
	int		h;
}	t_textures;

typedef struct s_rays
{
	float	rayangle[W_WIDTH];
	float	ray_distance[W_WIDTH];
	float	inter_x[W_WIDTH];
	float	inter_y[W_WIDTH];
	int		ray_wall_coll[W_WIDTH];
	int		ray_direction[W_WIDTH];
}	t_rays;

typedef struct s_player
{
	float	xpos;
	float	ypos;
	int		radius;
	int		turn_dir;
	int		walk_dir;
	int		cwalk_dir;
	float	velo;
	float	rotation_speed;
	float	player_angle;
}	t_player;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*n_texture;
	char	*e_texture;
	char	*w_texture;
	char	*s_texture;
	int		f;
	int		c;
}	t_data;

typedef struct s_game
{
	t_data		data;
	t_player	player;
	t_rays		rays;
	float		projdistance;
	int			map_h;
	int			map_w;
	float		surface_scale;
	float		wall_height;
	float		wall_index;
	float		sky_size;
	float		floor_size;
	char		**map;
	t_textures	arr_text[4];
}	t_game;

typedef struct s_check_info
{
	char	*key;
	char	**value;
}	t_check_info;

typedef struct s_cube
{
	int				fd;
	char			*map_str;
	int				on_off;
	int				num_info;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				f_color;
	int				c_color;
	int				player_exit;
	t_check_info	*info;
	char			**map_2d;
}	t_cube;

//libft
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//g_n_l
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *c);
char	*ft_res_gnl(char *s1, char *s2, char *p);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_second(char *buf);
char	*ft_first(char	*buf);
char	*ft_read(int fd, char *buf);

void			free_2d(char **arr);//valid
void			func_error(char *str);
char			*parsing(t_game *s_game, int argc, char **av);
int				check_file_name(char *str);//valid
void			init_struct(t_cube *s_pars);//valid
void			parse_info(t_cube *s_pars, char *temp1);//valid
void			stock_info(t_cube *s_pars, char **arr_2d);//valid
int				stock_colors(t_cube *s_pars, char **arr_2d);//valid
int				parse_colors(char *arr);//valid
int				ft_strcmp(const char *s1, const char *s2);
int				get_color(char **arr_2d);//valid
int				calculate_comma(char	*str);//valid
int				get_color_num(char *str, int i);//valid
void			parse_map(t_cube *s_pars, char *temp1);//valid
void			check_free_lines(char *arr);//valid
int				empty_line(char	*str);//valid
void			is_it_full_walls(char *str);//valid

//rendering
int init_rendering(t_game *game);
void draw_map(t_game *game);
void	draw_sky(t_game *g, int x, int skysize);
void	draw_wall(t_game *g, int x, int skysize, int wallheight);
void	draw_floor(t_game *g, int x, double fsize, double wheight);
void	my_put_pixel(t_data *data, int x, int y, int color);
int	update_player(t_game *g);

//player
void	init_player(t_player *player);
void	render_player(t_game *game, t_player *player);
int	collided_wall(float x, float y, t_game *g, int mode);
void	fetch_pixel_from_texture(t_game *g, int x, int y, int dir);
int	key_press(int keycode, t_game *g);
int	key_release(int keycode, t_game *g);

//rays
void	cast_rays(t_game *g);
#endif