/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:39 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 16:09:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_minishell *mini, t_env **head, int size)
{
	char	*pwd;
	char	*buff;
	char	*input;

	(void) mini;
	buff = NULL;
	pwd = getcwd(buff, sizeof(pwd));
	if (pwd)
		ft_putstr_fd_executor(pwd, 0x1, 0x1);
	else
	{
		input = grep_from_env(*head, "PWD");
		if (input)
			ft_putstr_fd_executor(input, 0x1, 0x1);
	}
	free(pwd);
	if (size > 1)
		exit (0x1);
	return (0x1);
}
