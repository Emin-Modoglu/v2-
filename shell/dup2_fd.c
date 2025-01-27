/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:22:01 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/11 05:22:03 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	_create_dup(t_mini *m_mini)
{
	int	new_fd[2];

	pipe(new_fd);
	write(new_fd[1], m_mini->heredoc, ft_strlen(m_mini->heredoc));
	dup2(new_fd[0], 0);
	close(new_fd[1]);
	close(new_fd[0]);
}

void	create_dup(t_mini *m_mini, t_parse *parse)
{
	if (parse->type == HEREDOC)
		_create_dup(m_mini);
	if (parse->infile > STDERR)
		dup2(parse->infile, 0);
	if (parse->outfile > STDERR)
		dup2(parse->outfile, 1);
}

void	create_dup_one(t_parse *parse, int *fd)
{
	t_parse	*nparse;

	nparse = parse->next;
	close(fd[0]);
	if (parse->next && fd && nparse->cmd)
		dup2(fd[1], 1);
	else if (parse->type == HEREDOC && parse->next->next)
		dup2(fd[1], 1);
	close(fd[1]);
}

void	create_dup_two(t_parse *parse, int *fd)
{
	close(fd[1]);
	if (fd && parse->control != 1)
		dup2(fd[0], 0);
	close(fd[0]);
}
