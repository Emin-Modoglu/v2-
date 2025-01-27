/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:21:07 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/11 05:30:05 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	change_old(char *str, t_mini *m_mini)
{
	t_list	*node;
	t_env	*env;
	char	*targetkey;
	int		flag;

	flag = 0;
	targetkey = "OLDPWD";
	node = m_mini->env;
	while (node)
	{
		env = (t_env *)node->content;
		if (!ft_strcmp(env->key, targetkey))
		{
			free(env->value);
			env->value = ft_strdup(str);
			return ;
		}
		node = node->next;
		if (!node)
			flag = 1;
	}
	if (flag == 1)
		create_oldpwd(m_mini, str);
}

void	create_oldpwd(t_mini *m_mini, char *str)
{
	t_env	*newenv;

	newenv = malloc(sizeof(t_env));
	if (!newenv)
		return ;
	newenv->key = strdup("OLDPWD");
	newenv->value = strdup(str);
	ft_lstadd_back(&(m_mini->env), ft_lstnew(newenv));
	return ;
}

void	change_pwd(t_parse *data, t_mini *m_mini)
{
	char	*targetkey;
	t_list	*node;
	t_env	*env;

	targetkey = "PWD";
	node = m_mini->env;
	while (node)
	{
		env = (t_env *)node->content;
		if (!ft_strcmp(env->key, targetkey))
		{
			if (env->value)
				free(env->value);
			if (data->text && !ft_strcmp(data->text[0], "~"))
				env->value = get_home(m_mini);
			else
				env->value = getcwd(NULL, 0);
			return ;
		}
		node = node->next;
	}
}

void	exec_cd1(char *str, t_parse *data, t_mini *m_mini)
{
	change_old(str, m_mini);
	chdir(get_home(m_mini));
	change_pwd(data, m_mini);
	m_mini->exec_status = 0;
}

void	exec_cd(t_parse *data, t_mini *m_mini)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (data->text && data->text[0])
	{
		if (chdir(data->text[0]) == 0)
		{
			change_old(str, m_mini);
			change_pwd(data, m_mini);
			m_mini->exec_status = 0;
		}
		else
		{
			if (str)
				free(str);
			m_mini->exec_status = 1;
			perror("cd");
		}
	}
	else
		exec_cd1(str, data, m_mini);
}
