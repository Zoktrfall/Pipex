/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:33 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/24 12:47:34 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *name_command, char **process, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exit(execve(name_command, process, envp));
	}
}

char	*malloc_empty(char **path, char **process)
{
	char	*ptr;

	ptr = ft_strdup("");
	if (ptr == NULL)
	{
		free_all(path, process, NULL);
		exit(1);
	}
	return (ptr);
}

char	*search_der(char **path, char **process, char *ptr, size_t i)
{
	if (process[0] == NULL)
	{
		ptr = malloc_empty(path, process);
		error_file(1, NULL, 13, 2);
		return (ptr);
	}
	if (!access(process[0], X_OK))
	{
		ptr = process[0];
		return (ptr);
	}
	while (path[++i])
	{
		ptr = ft_strjoin(path[i], process[0]);
		if (ptr == NULL)
		{
			free_dm(&path);
			exit(1);
		}
		if (!access(ptr, X_OK))
			return (ptr);
		free(ptr);
	}
	return (NULL);
}

char	**creat_path(char **envp)
{
	char		**path;
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			tmp = ft_strdup(envp[i]);
			if (tmp == NULL)
				return (NULL);
			tmp[3] = '.';
			tmp[4] = ':';
			path = ft_split(tmp + 3, ':');
			break ;
		}
		i++;
	}
	free(tmp);
	if (path == NULL)
		exit(1);
	return (path);
}

int	error_file(int index, char **argv, int number, int output)
{
	char	*error;

	if (number == 404)
		error = "command not found: ";
	else
		error = strerror(number);
	ft_putstr_fd("zsh: ", output);
	ft_putstr_fd(error, output);
	if (number != 404)
		ft_putstr_fd(": ", output);
	if (argv != NULL)
		ft_putstr_fd(argv[index], output);
	write(output, "\n", 1);
	return (output);
}
