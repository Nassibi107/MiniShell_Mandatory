/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/16 14:53:42 by youmoukh         ###   ########.fr       */
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

void	back_up(t_env **ennv, int i, char *pwd)
{
	t_env	*lst;
	char	*buff;

	buff = NULL;
	pwd = getcwd(buff, sizeof(pwd));
	if (!pwd)
		return ;
	// printf("[%s]\n", pwd);
	while (++i <= 0x4)
	{
		if (i == 0x0)
			lst = lstnew_executor(ft_strdup_1("PWD"), ft_strdup_1(pwd), 0);
		if (i == 0x1)
			lst = lstnew_executor(ft_strdup_1("SHLVL"), ft_strdup_1("1"), 0);
		if (i == 0x2)
			lst = lstnew_executor(ft_strdup_1("_"), ft_strdup_1("/usr/bin/env"), 0);
		if (i == 0x3)
			lst = lstnew_executor(ft_strdup_1("PATH"),
				ft_strdup_1("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), 0);
		if (i == 0x4)
			lst = lstnew_executor(ft_strdup_1("TERM"), 
				ft_strdup_1("xterm-256color"), 0);
		add_back_executor(ennv, lst);
		printf("[%d]\n", i);
	}
	free (pwd);
}

char	*ft_substr_env(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup_1(""));
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (s[start] && l)
	{
		r[i] = s[start];
		start++;
		i++;
		l--;
	}
	r[i] = '\0';
	return (r);
}


t_env	*full_fill_env(char **env, int i, int j)
{
	t_env	*lst_env;
	t_env	*head;
	char	*s1;
	char	*s2;
	// char	*tmp;

	head = NULL;
	if (!*env)
		back_up(&head, -0x1, 0x0);
	else
	{
		while (env[i])
		{
			j = 0x0;
			while (env[i][j] != '=')
				j++;
			s1 = ft_substr_env(env[i], 0x0, j);
			s2 = ft_substr_env(env[i], j + 0x1, ft_strlen(env[i]));
			// if (!strcmp_f(s1, "SHLVL", 0x0, 0x0))
			// {
			// 	tmp = ft_itoa(ft_atoi(s2) + 1);
			// 	s2 = ft_strdup(tmp);
			// 	free (tmp);
			// }
			lst_env = lstnew_executor(s1, s2, 0);
			// free(s2);
			add_back_executor(&head, lst_env);
			i++;
		}
	}
	return (head);
}

void	full_fill_path(t_minishell *mini, t_env *envir)
{
	mini->path = ft_malloc(sizeof(char) * ft_strlen(ft_get_path(envir)) + 0x1, 0x1);
	if (!mini->path)
		return ;
	mini->path = ft_get_path(envir);
	mini->path_d = ft_split_executor(ft_get_path(envir), ':');
}
