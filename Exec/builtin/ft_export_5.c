/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:14 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 15:18:57 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_1337(char *s, int i)
{
	while (s[i])
	{
		if ((!ft_isalnum_1(s[i])))
			return (ex_st_f(0x1, 0x1), 0x1);
		i++;
	}
	return (0);
}

int	is_correct(char *s)
{
	int		i;
	char	*r;

	i = 0x0;
	if (is_eq_exist(s))
	{
		r = ft_substr_executor(s, 0x0, is_eq_exist(s));
		while (r[i])
		{
			if (check_1337(r, 0x0))
				return (export_error(NULL, 0x0, s, 0x0), 0x1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (!ft_isalnum_1(s[i]))
				return (export_error(NULL, 0x0, s, 0x0), 0x1);
			i++;
		}
	}
	return (0x0);
}

int	is_correct_1(char *s)
{
	int		i;
	char	*r;

	i = 0x0;
	if (err(s))
		return (0x1);
	if (is_eq_exist(s) != 0x0)
	{
		r = ft_substr_executor(s, 0x0, is_eq_exist(s));
		while (r[i])
		{
			if (check_1337(r, 0x0))
				return (0x1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (!ft_isalnum_1(s[i]))
				return (0x1);
			i++;
		}
	}
	return (0x0);
}

int	err_export(char *s)
{
	if (ft_is_equal(s) || is_correct(s))
		return (0x0);
	return (0x1);
}

int	err_export_1(char *s)
{
	// if (err(s))
	// 	return (0x0);
	if (ft_is_equal_1(s) || is_correct_1(s)) 
		return (0x0);
	return (0x1);
}
