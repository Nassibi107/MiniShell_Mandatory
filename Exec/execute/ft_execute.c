/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/10 22:30:57 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	big_execution(t_minishell *mini, t_env *envir, int f, int old_stdin)
{
	int	t_pipe[2];
	int	pid;
	int	return_exve;
	int	check;

	check = 0x0;
	full_fill_path(mini, envir);
	if (check_fd(mini, envir))
		check = 0x1;
	expander(&mini, envir);
	if (pipe(t_pipe) == -1)
		return ;
		// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
		// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
	// printf("[%d]\n", mini->fd_in);
	pid = fork();
	if (pid == 0)
	{
		if (check == 0x1)
		{
			ex_st_f(0x0, 0x1);
			exit (0x1);
		}
		if (mini->fd_in != 0)
		{
			if (dup2(mini->fd_in, 0) == -1)
				exit(1);
			close(mini->fd_in);
		}
		if (f == 1)
		{
			if (mini->fd_out != 1)
			{
				if (dup2(mini->fd_out, 1) == -1)
					exit(1);
				close (mini->fd_out);
			}
			else
			{
				close (t_pipe[0]);
				if (dup2(t_pipe[1], 1) == -1)
					exit(1);
				close (t_pipe[1]);
			}
		}
		else
		{
			if (dup2(mini->fd_out, 1) == -1)
				exit(1);
			
		}
		is_cmd(mini, envir);
	}
	else
	{
		while(waitpid(pid, &return_exve, 0) != -1);
		if (WIFSIGNALED(return_exve))
			ex_st_f(WTERMSIG(return_exve) + 128, 0x1);
		else
			ex_st_f(WEXITSTATUS(return_exve), 0x1);
		close(t_pipe[1]);
		if (mini->fd_in != 0)
			dup2(t_pipe[0], mini->fd_in);
		else
			dup2(t_pipe[0], 0);
		close(t_pipe[0]);
		if (f == 0)
		{
			dup2(old_stdin, 0x0);
			close(old_stdin);
		}
		else
		{
			if (mini->fd_in != 0)
			{
				dup2(mini->fd_in, 0);
				close(mini->fd_in);
			}
		}
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

void	ft_execute(t_minishell **head, t_env *envir, int flag)
{
	t_minishell	*tmp;
	int			old_stdin;

	tmp = *head;
	old_stdin = dup(0);
	// mini->export = full_fill_print(&envir);
	if ((*head)->size == 0x1 && is_builtin(*head))
	{
		flag = is_builtin_cmd(*head, envir);
		if (flag != -1)
		{
			if (flag == 0x1)
				ex_st_f(0x0, 0x1);
			else if (flag != -1)
				ex_st_f(0x1, 0x1);
			return ;
		}
	}
	while (tmp->next)
	{
		big_execution(tmp, envir, 0x1, old_stdin);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, 0x0, old_stdin);
}
