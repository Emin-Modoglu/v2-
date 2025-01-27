/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:06 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/14 02:13:09 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	handle_dollar(t_mini *mini, t_list *lex, char **temp, char *before)
{
	if ((*temp)[1] == '?')
		expand_question_mark(mini, lex, temp, before);
	else if ((*temp)[1] != '$' && ft_strcmp((*temp), "$") != 0)
		expand_dollar_variable(mini, lex, temp, before);
	else
		*temp = ft_strchr(*temp + 1, '$');
}

void	expand_tilde(t_mini *mini)
{
	t_list	*lex;

	lex = mini->lex_list->lex;
	while (lex)
	{
		if (((char *)lex->content)[0] == '~')
			expander_tilde(mini, lex);
		lex = lex->next;
	}
}

void	expand_dollar(t_mini *mini)
{
	t_list	*lex;

	lex = mini->lex_list->lex;
	while (lex)
	{
		expand_dollar_internal(mini, lex);
		lex = lex->next;
	}
}

void	expand_dollar_internal(t_mini *mini, t_list *lex)
{
	char	*temp;
	char	*before;

	temp = ft_strchr(lex->content, '$');
	while (temp)
	{
		before = ft_substr(lex->content, 0, temp - (char *)lex->content);
		if (check_quote(before, temp))
			handle_dollar(mini, lex, &temp, before);
		else
			temp = ft_strchr(temp + 1, '$');
		free(before);
	}
}

void	expander(t_mini *mini)
{
	expand_tilde(mini);
	expand_dollar(mini);
}
