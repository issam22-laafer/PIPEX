/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:48:09 by lissam            #+#    #+#             */
/*   Updated: 2024/02/06 11:29:20 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_cmd1(t_data *data)
{
	ft_puststr(data->cmd1[0]);
	ft_puststr(" : command not found \n");
	free_all(data);
	exit(127);
}

void	err_cmd2(t_data *data)
{
	ft_puststr(data->cmd2[0]);
	ft_puststr(" : command not found \n");
	free_all(data);
	exit(127);
}

void	err_env1(t_data *data)
{
	ft_puststr(data->cmd1[0]);
	ft_puststr(" : command not found \n");
	free_all(data);
	exit(127);
}

void	err_env2(t_data *data)
{
	ft_puststr(data->cmd2[0]);
	ft_puststr(" : command not found \n");
	free_all(data);
	exit(127);
}
