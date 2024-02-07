/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:16:36 by lissam            #+#    #+#             */
/*   Updated: 2024/02/06 09:30:06 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_env(char **env, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", sizeof(env[i])))
		{
			data->path = env[i];
			j++;
		}
		i++;
	}
	if (j == 0)
	{
		data->my_env = NULL;
	}
	else
	{
		data->path = data->path + 5;
		data->my_env = ft_split(data->path, ':');
	}
}

void	parent(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 0;
	wait(&n1);
	wait(&n2);
	if (WIFEXITED(n1))
		exit(WEXITSTATUS(n1));
	if (WIFEXITED(n2))
		exit(WEXITSTATUS(n2));
	exit(0);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd1[i])
	{
		free(data->cmd1[i]);
		i++;
	}
	free(data->cmd1);
	i = 0;
	while (data->cmd2[i])
	{
		free(data->cmd2[i]);
		i++;
	}
	free(data->cmd2);
	i = 0;
	if (data->my_env != NULL)
	{
		while (data->my_env[i])
			free(data->my_env[i++]);
		free(data->my_env);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	t_data	data;

	check_args(ac);
	(get_cmds(av, &data), get_env(env, &data));
	if (pipe(fd) == -1)
		pipe_error();
	pid1 = fork();
	if (pid1 == -1)
		fork_error();
	if (pid1 == 0)
		child(fd, av, env, &data);
	pid2 = fork();
	if (pid2 == -1)
		fork_error();
	if (pid2 == 0)
		child2(fd, av, env, &data);
	(close(fd[0]), close(fd[1]));
	free_all(&data);
	parent();
}
