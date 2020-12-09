/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:08:51 by mbani             #+#    #+#             */
/*   Updated: 2020/12/09 12:27:52 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHELL_H
# define _SHELL_H
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;
enum	e_type
{
	cmd, arg, pipee, semicolumn, input_red, output_red, append_output, filename
};
enum	e_quotes
{
	none, opened, closed
};
typedef struct	s_cmd
{
	char *			string;
	enum e_type		type;
	struct s_cmd	*next;
}				t_cmd;
typedef struct s_expan
{
	enum e_quotes sng;
	enum e_quotes dbl;
}				t_expan;

t_env	*g_env_head;
t_cmd	*g_cmd_head;
t_cmd	*g_tmp_cmd;
char	*g_line;
char	*g_tmp;
char	**g_tmp_env;
size_t	g_is_out_app;
size_t	g_is_out;
size_t	g_is_int;
int		g_int_fd;
int		g_out_fd;
static	int g_x;
t_env	*ft_lstnewenv(char *key, char *value);
void	ft_lstadd_backenv(t_env **alst, t_env *new);
void	ft_lstclearenv(t_env **lst);
t_cmd	*ft_lstnew_cmd(char *string, enum e_type t);
void	ft_lstadd_backcmd(t_cmd **alst, t_cmd *new);
void	ft_lstclearcmd(t_cmd **lst);
void	ft_cd(void);
void	ft_echo(void);
void	ft_env(void);
void	ft_error(const char *error);
void	ft_execution(char *line, t_cmd *tmp);
void	ft_export(void);
void	ft_not_builtin(void);
void	ft_pwd(void);
void	ft_unset(void);
char	**path_spliter(void);
void	simple_pointer_free(char *ptr);
void	double_pointer_free(char **ptr);
void	str_cpy(char **dst, char **src);
size_t	ft_cd_helper(void);
char	*check_for_home(void);
void	cpy_env(char **envp);
void	ft_exit(char *line, t_cmd *tmp);
void	print_in_sort(void);
int		syntax_error();
int		swap_lst(t_cmd **cmd);
void	red_file_cmd(t_cmd *temp);
void	line_split(char *line);
int		add_string(char *line, enum e_quotes *sngl, enum e_quotes *dbl);
void	quote_check(enum e_quotes *sngl, enum e_quotes *dbl, char *line, int i);
int		quoted_str(char *line, enum e_quotes *sngl, enum e_quotes *dbl);
int		quoted_str_help(enum e_quotes **sngl,
enum e_quotes **dbl, char **tmp, int i);
void	quote_removal_init(t_expan *quote, char **tmp, char **temp, int *i);
void	quote_removal(char **str);
char	*rm_spaces(char *line);
enum e_type	operators_check(char *op);
int		separators_check(char **tmp, int *i, char **op, int *j);
int		operators(char **line, int i, char **op);
void	cp_before_$(int *k, int len, char **tmp, char **str);
void	cp_from_$(int *k, char **tmp, char **env, int *x);
void	replace(char **str, char *env, int j, int i);
int		search_and_replace(char **str, int i, int j);
void	env_var(char **envp);
int		env_spliter(char *env, char **key, char **value);
int		ft_strncmp_env(const char *s1, const char *s2, size_t n);
void	add_to_str(char **tmp, char c);
void	rm_backslash(char **temp, char **str, char **tmp, int *i);
void	join(char **temp, char **tmp);
int		not_escaped(char *line, int i);
int		find_args(t_cmd **tmp_before_arg, t_cmd **tmp_arg,
t_cmd **tmp_cmd, t_cmd **lst);
void	add_to_str(char **tmp, char c);
void	add_to_list(char **tmp, enum e_type t);
int		find_cmd_red(t_cmd **tmp_before_cmd, t_cmd **tmp_red, t_cmd **lst);
void	param_expansion(t_cmd *tmp);
int		add_to_list_bulk(char **tmp, char **op, int *i, int *j);
void	replace_return_value(t_cmd **str, size_t value);
void	ft_lstadd_echo(t_cmd **lst);
int		add_echo(t_cmd **lst);
#endif