/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:31 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/24 12:47:32 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *str1, char *str2, int flag)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] - str2[i] != 0)
			return (1);
		i++;
	}
	if (flag == 1 && str1[i + 1] == '\0' && str2[i] == '\0')
		return (0);
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	return (1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && b < count)
	{
		if ((str1[i] - str2[i] != 0))
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		b++;
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
	return ;
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	while (str1[i] != '\0')
	{
		ptr[j] = str1[i];
		j++;
		i++;
	}
	ptr[j++] = '/';
	i = 0;
	while (str2[i] != '\0')
	{
		ptr[j] = str2[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(str);
	j = 0;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr != NULL)
	{
		while (str[j] != '\0')
		{
			ptr[j] = str[j];
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
