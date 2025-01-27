/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:23:25 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/14 15:22:43 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_init_check(t_mini *mini)
{
	if (mini->env)
		free_(mini);
	if (mini->lex_list)
		free(mini->lex_list);
	//if (mini->lex_list->lex)
	//	free(mini->lex_list->lex);
	// eger env_get fonksiyonundan buraya gelirse valgring 1 error durumu olusuyordu
	if (mini)
		free(mini);
	return ((void)printf(ENV_ERR));
}
