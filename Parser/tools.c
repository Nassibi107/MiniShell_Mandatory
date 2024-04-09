/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:17:36 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 16:23:10 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	case__1(char c, int *i, int *len)
{
	if (c == '<')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

static void	case__2(char c, int *i, int *len)
{
	if (c == '>')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

int	ft_set_tk(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
				ft_parq(str, &i, 's');
			else if (str[i] == '\"')
				ft_parq(str, &i, 'q');
			if (!str[i])
				break ;
		}
		if (str[i] == '<')
			case__1(str[i], &i, &len);
		else if (str[i] == '>')
			case__2(str[i], &i, &len);
		i++;
	}
	return (len);
}

int	ft_parq(char *str, int *i, char f)
{
	int	op;

	op = 0;
	*i += 1;
	if (f == 'q')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\"')
				op = 1;
			*i += 1;
		}
	}
	else if (f == 's')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\'')
				op = 1;
			*i += 1;
		}
	}
	return (op);
}
