/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/10 22:32:06 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	file_first_check(t_minishell *m)
{
	int	i;
	int	fd;

	i = 0x1;
	fd = 0x0;
	while (m->files[i])
	{
		if (m->tab[i - 1] == 0x3)
		{
			fd = open(m->files[i], O_RDONLY);
			if (fd == -0x1)
			{
				// ex_st_f(0x0, 0x1);
				return (func_err(m->files[i]), 0x1);
			}
		}
		i++;
	}
	return (0x0);
}

int	advanced(t_minishell *m)
{
	if (!strcmp_f(m->cmd[0x0], "cat", 0x0, 0x0) && file_first_check(m) == 1 &&
		!strcmp_f(m->next->cmd[0x0], "cat", 0x0, 0x0))
		return (0x1);
	return (0x0);
}

int	check_here(t_minishell *m)
{
	int	i;

	i = -0x1;
	while (++i < m->len_tab)
	{
		if (m->tab[i] == 0x4)
			return (0x0);
	}
	return (0x1);
}

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;
	int	l;

	flag = 0x1;
	l = 0;
	if (!mini->files[0x1])
		return (0x0);
	if (!check_files(mini, env, -0x1) && check_here(mini))
		expand_files(&mini, env, 0x0);
	else if (!check_here(mini))
		l = 1;
	else if (!check_files(mini, env, -0x1) && l == 0)
		return (0x1);
		
	// if (advanced(mini))
	// 	return (0x1);
	// if (file_first_check(mini))
	// 	return (0x1);
	if (ft_fd_files(mini, env))
		flag = 0x0;
	if (ft_open_others(mini))
		flag = 0x2;
	if (!flag || flag == 0x2)
		return (0x1);
	return (0x0);
}
