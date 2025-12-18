/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:28:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 10:25:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ENV_H
#define M_ENV_H

# define FT "front"
# define VL "env_val"


typedef struct	s_env_list
{
	char				*front;
	char				*env_val;
	struct s_env_list	*next;
	struct s_env_list	*prev;
}	t_env_list;

t_env_list	**delete_node(t_env_list **list);
t_env_list	*find_env_key(char *to_find, t_env_list **list);
int			change_value(char *src, t_env_list **list);
int			add_env_node(t_env_list *node ,t_env_list **list);
void		free_env(t_env_list **env_list);
int			add_env(char *env, t_env_list **list);
int			remove_env(char *target, t_env_list **list);
void		print_env(t_env_list *env);
t_env_list	*env_to_list(char **env);
int			env_size(t_env_list **list);
char		**list_to_char(t_env_list **list, char **res);
int			key_value_len(char *key, t_env_list **list);
int			change_key_value(char *key, char *value, t_env_list **env);
char		*get_value(char *key, t_env_list **list);
void		*print_int_env(char **int_env);
char		**add_int_env(char *target, char *value, char **list);
char		*find_int_env(char *target, char **list);
char		*get_int_env(char *target, char **list);

#endif