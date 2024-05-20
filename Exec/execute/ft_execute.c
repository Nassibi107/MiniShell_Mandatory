/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 18:11:20 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	big_execution(t_minishell *mini, t_env *envir, int f, int old_stdin)
{
	int	t_pipe[2];

	check_env(mini, envir);
	if (!envir || !(mini)->cmd || !(mini)->cmd[0])
		return ;
	if (!setup_pipes(t_pipe))
		return ;
	signal(SIGQUIT, signal_handler_child);
	mini->pid_fork = fork();
	if (!mini->pid_fork)
	{
		h_cp(mini, envir, t_pipe, f);
	}
	else
	{
		h_pp(mini, t_pipe, f, old_stdin);
	}
}

void	handle_fd(t_minishell *mini)
{
	if ((mini)->fd_out != 0x1)
	{
		if (dup2((mini)->fd_out, 0x1) == -1)
			return (ft_put_err("dup2 ", "Cant Work\n"));
	}
	if ((mini)->fd_in != 0x0)
	{
		if (dup2((mini)->fd_in, 0x0) == -1)
			return (ft_put_err("dup2", "Cant Work\n"));
	}
}

void	status(int *return_exve)
{
	while (wait(return_exve) > 0)
		;
	if (WIFSIGNALED(*return_exve))
		ex_st_f(WTERMSIG(*return_exve) + 128, 0x1);
	else
		ex_st_f(WEXITSTATUS(*return_exve), 0x1);
}

int	return_cmd(int f)
{
	if (f != -1)
	{
		if (f == 0x1)
			ex_st_f(0x0, 0x1);
		else if (f != -1)
			ex_st_f(0x1, 0x1);
		return (0x1);
	}
	else
		return (0x1);
	return (0x0);
}

void	ft_execute(t_minishell **head, t_env *envir, int flag)
{
	t_minishell	*tmp;
	int			old_stdin;
	int			return_exve;

	tmp = *head;
	old_stdin = dup(0);
	if ((*head)->size == 0x1 && is_builtin(*head))
	{
		flag = is_builtin_cmd(*head, envir);
		if (return_cmd(flag))
			return ;
	}
	while (tmp->next)
	{
		big_execution(tmp, envir, 0x1, old_stdin);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, 0x0, old_stdin);
	status(&return_exve);
	close(old_stdin);
}
