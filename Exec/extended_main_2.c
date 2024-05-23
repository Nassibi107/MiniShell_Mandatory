/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_main_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:54:02 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 14:33:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_puterror(int p)
{
	if (p != -1)
	{
		if (p == 0)
			ft_putendl_fd(ERR_0, 2);
		if (p == 1)
			ft_putendl_fd(ERR_1, 2);
		if (p == 3 || p == 5)
			ft_putendl_fd(ERR_2, 2);
		if (p == 6)
			ft_putendl_fd(ERR_3, 2);
		if (p == 7)
			ft_putendl_fd(ERR_4, 2);
		ex_st_f(258, 0x1);
	}
}

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	if (!s[i])
		return (0x1);
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			return (0x0);
		i++;
	}
	return (0x1);
}

char	*display_prompt_msg(void)
{
	char	*cwd;
	char	*str;
	char	buff[4096 + 1];

	str = 0x0;
	cwd = getcwd(buff, 4096);
	if (cwd)
		str = ft_strjoin_executor(cwd, " \033[32m$>\033[0m ");
	return (str);
}

void	sig_func(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	rl_catch_signals = 0;
}

t_minishell	*last_node(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}