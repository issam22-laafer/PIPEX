/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:05:19 by lissam            #+#    #+#             */
/*   Updated: 2024/02/03 23:04:52 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac)
{
	if (ac != 5)
	{
		ft_puststr("Number of args is not valid 🤬");
		exit(1);
	}
}

void	access_cmd1(t_data *data)
{
	int		i;
	int		j;
	char	*the_cmd;
	char	*str;

	i = 0;
	j = 0;
	the_cmd = ft_strjoin("/", data->cmd1[0]);
	while (data->my_env[i])
	{
		str = ft_strjoin(data->my_env[i], the_cmd);
		if (access(str, X_OK) == 0)
		{
			data->cmd1_path = str;
			j++;
			break ;
		}
		free(str);
		i++;
	}
	free(the_cmd);
	if (j == 0)
		err_cmd1(data);
}

void	access_cmd2(t_data *data)
{
	int		i;
	int		j;
	char	*the_cmd;
	char	*str;

	i = 0;
	j = 0;
	the_cmd = ft_strjoin("/", data->cmd2[0]);
	while (data->my_env[i])
	{
		str = ft_strjoin(data->my_env[i], the_cmd);
		if (access(str, X_OK) == 0)
		{
			data->cmd2_path = str;
			j++;
			break ;
		}
		free(str);
		i++;
	}
	free(the_cmd);
	if (j == 0)
		err_cmd2(data);
}

void	check_cmd1(t_data *data)
{
	if (!access(data->cmd1[0], X_OK))
		data->cmd1_path = data->cmd1[0];
	else if (data->my_env == NULL)
		err_env1(data);
	else
	{
		access_cmd1(data);
	}
}

void	check_cmd2(t_data *data)
{
	if (!access(data->cmd2[0], X_OK))
		data->cmd2_path = data->cmd2[0];
	else if (data->my_env == NULL)
		err_env2(data);
	else
	{
		access_cmd2(data);
	}
}
