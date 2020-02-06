/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:51:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/02/06 18:58:21 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H

# define FUNCTION_H

typedef int	t_bool;

/*
	Fonctions liées au parsing.
*/

t_map		*parser(void);
t_preparse	*pre_parser(void);
t_room		**get_rooms(t_map *data, t_preparse *prep);
uint32_t	jenkins_hash(char *name);
uint32_t	get_hashed_name(t_preparse *prep, char *name);
int			get_nb_rooms(char *buffer);
int			get_next_room(t_preparse *prep, t_map *data);
int			parse_rooms(t_map **data, t_preparse *prep);
int			create_room(t_map *data, t_preparse *prep);
int			parse_comment(t_preparse *prep, t_map *data);
int			get_pipes(t_map **data, t_preparse *prep);
int			fix_room(t_preparse *prep, t_room *room, t_map *data);
int			valid_coords(char *buffer);
void		replace_sink_tank(t_map *data);

t_map		*which_error(t_map *data, int type);
void		free_all(t_map *data);
char		*ft_passing_name(char *str);
char		*ft_strcsub(char *s, char c);
int			count_char_until(char *str, char c, char u);


/*
	Fonctions pour la matrice d'adjacence.
*/

int			ft_line_check(int *line, int len);
int		ft_alt_line_check(t_room *current, int *line);
int			ft_path_length_matrix(int **adj_mat, t_map *data, int c_index);
int		ft_alt_check_line(t_room *current, int *line, int state);
void		ft_reset_matrix(t_map *data, int **adj_mat);
int			ft_check_line(int *line, int len, int nb);
int			**ft_mat_mirror_change(int **adj_mat, int value, int i_1, int i_2);
void		ft_clean_matrix(t_map *data, int **adj_mat);
int			ft_go_to_next(int *line, int nb_rooms);


/*
	Fonctions de gestion de la queue.
*/

t_room		*ft_remove_queue(t_queue *bfs_queue);
void		ft_add_queue(t_queue *bfs_queue, t_room *to_add, t_room *current, int time);
void		ft_add_front_queue(t_queue *bfs_queue, t_room *to_add, t_room *current);
void		ft_actualisation(t_room *to_add, t_room *current, int time);

/*
	Fonction pour la modification du graphe, la creation de chemin et la distribution.
*/

void		ft_clean(t_map *data, int **adj_mat);
void		ft_init_bfs(t_queue *bfs_queue, t_map *data);
void		ft_set_bfs(t_map *data);
int			**ft_bfs(t_map *data, int **adj_mat);
int			**ft_bhandari(t_map *data, int **adj_mat);
void		ft_distribution(int **tab_path, int nb_path, int nb_ants);
int			**ft_print(int **tab, t_map *data);
int			distrib(t_map *data);

/*
	Fonction de gestion des leaks.
*/

void		ft_free_queue(t_queue queue, int len);
void		ft_free(t_map *data, int **tab_path);

/*
	Fonction de gestion du buffer.
*/

void		ft_write_in_buffer(t_buff *buff, char c, int len);
void		ft_putstr_buffer(t_buff *buff, char *str, int len);
void		ft_flush_buffer(t_buff *buff);

/*
	Fonction de Debug.
*/

void		print_info(t_map *data);
void		link_tabs(t_map *data);
void		ft_debug_line_adj_mat(int *line, size_t size);
void		ft_debug_room(t_room *room);
void		ft_debug_rooms(t_room **rooms, size_t size);
void		ft_debug_queue(t_queue bfs_queue);
void		ft_debug_single_path(int *path, int len, t_map *data);
void		ft_debug_print(int **ants, t_map *data, int **tab);
void		ft_debug_collission(t_map *data);
void		ft_debug_path(t_map *data, int **adj_mat);
#endif
