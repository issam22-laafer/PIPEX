/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:18:12 by lissam            #+#    #+#             */
/*   Updated: 2024/02/05 22:14:54 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_for_child1(t_data *data)
{
	int	i;

	i = 0;
	while (data->my_env[i])
	{
		free(data->my_env[i]);
		i++;
	}
	free(data->my_env);
	i = 0;
	while (data->cmd2[i])
	{
		free(data->cmd2[i]);
		i++;
	}
	free(data->cmd2);
}

void	free_for_child2(t_data *data)
{
	int	i;

	i = 0;
	while (data->my_env[i])
	{
		free(data->my_env[i]);
		i++;
	}
	free(data->my_env);
	i = 0;
	while (data->cmd1[i])
	{
		free(data->cmd1[i]);
		i++;
	}
	free(data->cmd1);
}

void	child(int fd[2], char **av, char **env, t_data *data)
{
	int	fdin;

	fdin = open(av[1], O_RDONLY);
	if (fdin == -1)
	{
		perror(av[1]);
		exit(1);
	}
	check_cmd1(data);
	close(fd[0]);
	dup2(fdin, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fdin);
	execve(data->cmd1_path, data->cmd1, env);
}

void	child2(int fd[2], char **av, char **env, t_data *data)
{
	int	fdout;

	fdout = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout == -1)
	{
		perror(av[4]);
		exit(1);
	}
	check_cmd2(data);
	close(fd[1]);
	dup2(fdout, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fdout);
	execve(data->cmd2_path, data->cmd2, env);
}
