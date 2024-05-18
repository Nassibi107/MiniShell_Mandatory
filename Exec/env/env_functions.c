/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 14:38:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->key, string, 0x0, 0x0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (ft_strdup_1(""));
}

char	*ft_get_path(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->key, "PATH", 0x0, 0x0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	back_up(t_env **ennv, int i, char *pwd, char *buff)
{
	t_env	*lst;
	char	*p;

	p = "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.";
	pwd = getcwd(buff, sizeof(pwd));
	if (!pwd)
		return ;
	while (++i <= 0x4)
	{
		if (i == 0x0)
			lst = lstnew_executor(ft_strdup_1("PWD"), ft_strdup_1(pwd), 0);
		if (i == 0x1)
			lst = lstnew_executor(ft_strdup_1("SHLVL"), ft_strdup_1("1"), 0);
		if (i == 0x2)
			lst = lstnew_executor(ft_strdup_1("_"),
					ft_strdup_1("/usr/bin/env"), 0);
		if (i == 0x3)
			lst = lstnew_executor(ft_strdup_1("PATH"), ft_strdup_1(p), 0);
		if (i == 0x4)
			lst = lstnew_executor(ft_strdup_1("TERM"),
					ft_strdup_1("xterm-256color"), 0);
		add_back_executor(ennv, lst);
	}
	free (pwd);
}

t_env	*full_fill_env(char **env, int i, int j)
{
	t_env	*lst_env;
	t_env	*head;
	char	*s1;
	char	*s2;

	head = NULL;
	if (!*env)
		back_up(&head, -0x1, 0x0, 0x0);
	else
	{
		while (env[i])
		{
			j = 0x0;
			while (env[i][j] != '=')
				j++;
			s1 = ft_substr_env(env[i], 0x0, j);
			s2 = ft_substr_env(env[i], j + 0x1, ft_strlen(env[i]));
			lst_env = lstnew_executor(s1, s2, 0);
			add_back_executor(&head, lst_env);
			i++;
		}
	}
	return (head);
}

void	full_fill_path(t_minishell *mini, t_env *envir)
{
	mini->path = ft_malloc(ft_strlen(ft_get_path(envir)) + 0x1, 0x1);
	if (!mini->path)
		return ;
	mini->path = ft_get_path(envir);
	mini->path_d = ft_split_executor(ft_get_path(envir), ':');
}
