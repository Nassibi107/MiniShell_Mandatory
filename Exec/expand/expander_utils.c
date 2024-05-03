/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:20:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/19 18:43:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	case_1(char *s, int pos)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == DBL)
		{
			i++;
			while (s[i] != DBL && s[i])
			{
				if (i == pos)
					return (0x1);
				i++;
			}
		}
		i++;
	}
	return (0x0);
}

int	case_2(char *s, int pos)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == SGL)
		{
			i++;
			while (s[i] != SGL && s[i])
			{
				if (i == pos)
					return (0x0);
				i++;
			}
		}
		i++;
	}
	return (1);
}

int	dollar_position(char *s, int pos)
{
	if (case_1(s, pos))
		return (0x1);
	if (case_2(s, pos))
		return (0x1);
	return (0x0);
}

int	check_single(char *s)
{
	if (!s)
		return (0x0);
	if (s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL && ft_strlen(s) > 2)
		return (0x1);
	return (0x0);
}

char	*do_single(char *s, int i, int j)
{
	char	*r;

	r = ft_calloc(ft_strlen(s), 1);
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] == SGL)
			i++;
		if (!s[i])
			break ;
		r[j] = s[i];
		i++;
		j++;
	}
	return (r);
}

char	*without_quotes(char *s, int flag)
{
	int		i;
	int		j;
	char	*res;

	i = 0x0;
	j = 0x0;
	if (check_single(s))
		return (do_single(s, 0x0, 0x0));
	if (!s)
		return ("");
	res = calloc(strlen(s) + 0x1, 0x1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] == DBL && s[i] && flag == 0x0)
		{
			flag = 0x1;
			i++;
		}
		if (s[i] == DBL && flag == 0x1)
		{
			i++;
			flag = 0x0;
		}
		while (s[i] == SGL && flag == 0x0)
			i++;
		if (!s[i])
			break ;
		if (s[i] != DBL && s[i])
		{
			res[j] = s[i];
			i++;
			j++;
		}
	}
	return (res);
}
