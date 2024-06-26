/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleantach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:14:43 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/11 15:37:29 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cleantach(char **s)
{
	int	i;

	i = 0;
	if (!*s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	*s = NULL;
}
