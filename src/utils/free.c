/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:28 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/24 12:47:29 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_dm(char ***str)
{
	size_t	i;

	i = 0;
	if (*str == NULL)
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

void	free_all(char **path, char **process, char *name_comand)
{
	free_dm(&path);
	free_dm(&process);
	if (name_comand != NULL)
	{
		free(name_comand);
		name_comand = NULL;
	}
}
