/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:38:02 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 23:28:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd_executor(char *s, int fd, int flag_newline)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (flag_newline == 1)
		write(fd, "\n", 1);
}

int	ft_strcmp_flag(char *s1, char *s2, int flag, int i)
{
	if (!s1 || !s2)
		return (0);
	if (flag == 0)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (-1);
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
	}
	else
	{
		while (s1[i] && s2[i] && i < flag)
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
	}
	return (0);
}

char	*copy_1(char *r, char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

char	*copy_2(char *r, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
