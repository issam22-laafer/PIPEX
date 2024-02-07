/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:22 by lissam            #+#    #+#             */
/*   Updated: 2024/02/06 11:16:24 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>

typedef struct data
{
	char	**cmd1;
	char	*cmd1_path;
	char	**cmd2;
	char	*cmd2_path;
	char	*path;
	char	**my_env;

}			t_data;

void		ft_puststr(char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		pipe_error(void);
void		fork_error(void);
char		*ft_strnstr(char *big, char *little, size_t len);
size_t		ft_strlen2(const char *str);
char		*ft_strjoin(char *s1, char *s2);
void		check_args(int ac);
void		check_cmd1(t_data *data);
void		check_cmd2(t_data *data);
void		err_cmd1(t_data *data);
void		err_cmd2(t_data *data);
void		err_env1(t_data *data);
void		err_env2(t_data *data);
void		get_cmds(char **av, t_data *data);
void		free_all(t_data *data);
void		child2(int fd[2], char **av, char **env, t_data *data);
void		child(int fd[2], char **av, char **env, t_data *data);

#endif